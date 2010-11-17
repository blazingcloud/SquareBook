/*
	File:  AVAsset.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

/*!
    @class			AVAsset

    @abstract		An AVAsset is an abstract class that defines AVFoundation's model for timed audiovisual media.
    				Each asset contains a collection of tracks that are intended to be presented or processed together, each of a uniform media type,
    				including but not limited to audio, video, text, closed captions, and subtitles.

	@discussion		AVAssets are often instantiated via its concrete subclass AVURLAsset with NSURLs that refer to audiovisual media files,
					such as QuickTime movie files, MP3 files, or files of other types.
					
					They can also be instantiated using other concrete subclasses that extend the basic model for audiovisual media 
					in useful ways, as AVComposition does for temporal editing.
					
					Properties of assets as a whole are defined by AVAsset.
					Additionally, references to instances of AVAssetTracks representing tracks of the collection
					can be obtained, so that each of these can be examined independently.
					
					Because of the nature of timed audiovisual media, upon successful initialization of an AVAsset
					some or all of the values for its keys may not be immediately available. The value of any key can be
					requested at any time, and AVAsset will always return its value synchronously, although it may have to
					block the calling thread in order to do so.

					In order to avoid blocking, clients can register their interest
					in particular keys and to become notified when their values become available. For further details, see the category
					AVAssetAsynchronousLoading below.
					
					To play an instance of AVAsset, initialize an instance of AVPlayerItem with it, use the AVPlayerItem
					to set up its presentation state (such as whether only a limited timeRange of the asset should be played, etc.),
					and provide the AVPlayerItem to an AVPlayer according to whether the items is to be played by itself
					or together with a collection of other items. Full details available in AVPlayerItem.h and AVPlayer.h.
					
					AVAssets can also be inserted into AVMutableCompositions in order to assemble audiovisual constructs from one or more
					source assets.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <AVFoundation/AVAsynchronousKeyValueLoading.h>

#if TARGET_OS_IPHONE
#import <CoreGraphics/CGAffineTransform.h>
#else // ! TARGET_OS_IPHONE
#import <ApplicationServices/../Frameworks/CoreGraphics.framework/Headers/CGAffineTransform.h>
#endif // ! TARGET_OS_IPHONE

#import <CoreMedia/CMTime.h>

@class AVAssetTrack;
@class AVCompositionTrack;

@class AVAssetInternal;

@interface AVAsset : NSObject <NSCopying, AVAsynchronousKeyValueLoading>
{
@private
	AVAssetInternal *_assetInternal;
}

/*	indicates the duration of the asset. If @"providesPreciseDurationAndTiming" is NO, a best-available estimate
    of the duration is returned. The degree of precision required for timing-related properties can be set at
    initialization time for assets initialized with URLs. See AVURLAssetPreferPreciseDurationAndTimingKey for AVURLAsset below. */
@property (nonatomic, readonly) CMTime duration;

/*	indicates the natural rate at which the asset is to be played; often but not always 1.0 */
@property (nonatomic, readonly) float preferredRate;

/*	indicates the preferred volume at which the audible media of an asset is to be played; often but not always 1.0 */
@property (nonatomic, readonly) float preferredVolume;

/*	indicates the preferred transform to apply to the visual content of the asset for presentation or processing;
	the value is often but not always the identity transform */
@property (nonatomic, readonly) CGAffineTransform preferredTransform;

/*	indicates the encoded or authored size of the visual portion of the asset */
@property (nonatomic, readonly) CGSize naturalSize;

@end


@interface AVAsset (AVAssetAsynchronousLoading)

/*	indicates that the asset provides precise timing. See @"duration" above and AVURLAssetPreferPreciseDurationAndTimingKey below. */
@property (nonatomic, readonly) BOOL providesPreciseDurationAndTiming;

/*!
	@method			cancelLoading
	@abstract		Cancels the loading of all values for all observers.
	@discussion		Deallocation or finalization of an instance of AVAsset will implicitly cancel loading if any loading requests are still outstanding.
*/
- (void)cancelLoading;

@end


@interface AVAsset (AVAssetTrackInspection)

/* provides the array of AVAssetTracks contained by the asset */
@property (nonatomic, readonly) NSArray *tracks;

/*!
	@method			trackWithTrackID:
	@abstract		Provides an instance of AVAssetTrack that represents the track of the specified trackID.
	@param			trackID
					The trackID of the requested AVAssetTrack.
	@result			An instance of AVAssetTrack; may be nil if no track of the specified trackID is available.
	@discussion		Becomes callable without blocking when the key @"tracks" has been loaded
*/
- (AVAssetTrack *)trackWithTrackID:(CMPersistentTrackID)trackID;

/*!
	@method			tracksWithMediaType:
	@abstract		Provides an array of AVAssetTracks of the asset that present media of the specified media type.
	@param			mediaType
					The media type according to which AVAsset filters its AVAssetTracks. (Media types are defined in AVMediaFormat.h.)
	@result			An NSArray of AVAssetTracks; may be empty if no tracks of the specified media type are available.
	@discussion		Becomes callable without blocking when the key @"tracks" has been loaded
*/
- (NSArray *)tracksWithMediaType:(NSString *)mediaType;

/*!
	@method			tracksWithMediaCharacteristic:
	@abstract		Provides an array of AVAssetTracks of the asset that present media with the specified characteristic.
	@param			mediaCharacteristic
					The media characteristic according to which AVAsset filters its AVAssetTracks. (Media characteristics are defined in AVMediaFormat.h.)
	@result			An NSArray of AVAssetTracks; may be empty if no tracks with the specified characteristic are available.
	@discussion		Becomes callable without blocking when the key @"tracks" has been loaded
*/
- (NSArray *)tracksWithMediaCharacteristic:(NSString *)mediaCharacteristic;

@end


@interface AVAsset (AVAssetMetadataReading)

// high-level access to selected metadata of common interest

/* Provides access to the lyrics of the asset suitable for the current locale. */
@property (nonatomic, readonly) NSString *lyrics;

/* Provides access to an array of AVMetadataItems for each common metadata key for which a value is available;
   can be filtered according to locale via +[AVMetadataItem metadataItemsFromArray:withLocale:]
   or according to key via +[AVMetadataItem metadataItemsFromArray:withKey:keySpace:]. */
@property (nonatomic, readonly) NSArray *commonMetadata;

/* Provides an NSArray of NSStrings, each representing a metadata format that's available to the asset (e.g. ID3, iTunes metadata, etc.).
   Metadata formats are defined in AVMetadataFormat.h. */
@property (nonatomic, readonly) NSArray *availableMetadataFormats;

/*!
	@method			metadataForFormat:
	@abstract		Provides an NSArray of AVMetadataItems, one for each metadata item in the container of the specified format;
					can subsequently be filtered according to locale via +[AVMetadataItem metadataItemsFromArray:withLocale:]
					or according to key via +[AVMetadataItem metadataItemsFromArray:withKey:keySpace:].
	@param			format
					The metadata format for which items are requested.
	@result			An NSArray containing AVMetadataItems; may be empty if there is no metadata of the specified format.
	@discussion		Becomes callable without blocking when the key @"availableMetadataFormats" has been loaded
*/
- (NSArray *)metadataForFormat:(NSString *)format;

@end


@interface AVAsset (AVAssetProtectedContent)

/*! Indicates whether or not the asset has protected content. */
@property (nonatomic, readonly) BOOL hasProtectedContent;

@end


// Keys for options dictionary for use with -initWithURL:options:

/*!
	@constant		AVURLAssetPreferPreciseDurationAndTimingKey
	@abstract		Indicates whether the asset should be prepared to indicate a precise duration and provide precise random access by time.
	                The value for this key is a boolean NSNumber.
	@discussion		Pass YES if longer loading times are acceptable in cases in which precise timing is required.
					Note that such precision may require additional parsing of the resource in advance
					of operations that make use of any portion of it, depending on the specifics of its container format.
					Many container formats provide sufficient summary information for precise timing and do not require additional
					parsing to prepare for it; QuickTime movie files and MPEG-4 files are examples of such formats.
					Other formats do not provide sufficient summary information, and precise random access for them is possible
					only after a preliminary examination of a file's contents.
					If the asset is intended to be played only, because AVPlayer will support approximate random access by time
					when full precision isn't available, the default value of NO will suffice.
					If the asset is intended to be inserted into an AVMutableComposition,
					precise random access is typically desirable and the value of YES is recommended.
 */
extern NSString *const AVURLAssetPreferPreciseDurationAndTimingKey __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

@class AVURLAssetInternal;

@interface AVURLAsset : AVAsset
{
@private
    AVURLAssetInternal     *_asset;
}

/*!
	@method			URLAssetWithURL:options:
	@abstract		Returns an instance of AVURLAsset for inspection of a media resource.
	@param			URL
					An instance of NSURL that references a media resource.
	@param			options
					An instance of NSDictionary that contains keys for specifying options for the initialization of the AVURLAsset.
					See AVURLAssetPreferPreciseDurationAndTimingKey above.
	@result			An instance of AVURLAsset.
*/
+ (AVURLAsset *)URLAssetWithURL:(NSURL *)URL options:(NSDictionary *)options;

/*!
	@method			initWithURL:options:
	@abstract		Initializes an instance of AVURLAsset for inspection of a media resource.
	@param			URL
					An instance of NSURL that references a media resource.
	@param			options
					An instance of NSDictionary that contains keys for specifying options for the initialization of the AVURLAsset.
					See AVURLAssetPreferPreciseDurationAndTimingKey above.
	@result			An instance of AVURLAsset.
*/
- (id)initWithURL:(NSURL *)URL options:(NSDictionary *)options;

/* indicates the URL with which the instance of AVURLAsset was initialized */
@property (nonatomic, readonly, copy) NSURL *URL;

@end


@interface AVURLAsset (AVAssetCompositionUtility )

/*!
	@method			compatibleTrackForCompositionTrack:
	@abstract		Provides a reference to an AVAssetTrack of the target from which any timeRange
					can be inserted into a mutable composition track (via -[AVMutableCompositionTrack insertTimeRange:ofTrack:atTime:error:]).
	@param			compositionTrack
					The composition track for which a compatible AVAssetTrack is requested.
	@result			an instance of AVAssetTrack
	@discussion
	  Finds a track of the target with content that can be accommodated by the specified composition track.
	  The logical complement of -[AVMutableComposition mutableTrackCompatibleWithTrack:].
*/
- (AVAssetTrack *)compatibleTrackForCompositionTrack:(AVCompositionTrack *)compositionTrack;

@end


