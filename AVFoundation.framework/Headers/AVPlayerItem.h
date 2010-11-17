/*
    File:  AVPlayerItem.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

/*!
	@class			AVPlayerItem

	@abstract		An AVPlayerItem carries a reference to an AVAsset as well as presentation settings for that asset,
					including track enabled state.

	@discussion		Note that inspection of media assets is provided by AVAsset.
					This class is intended to represent presentation state for an asset that's played by an AVPlayer
					and to permit observation of that state.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>
#if TARGET_OS_IPHONE
#import <CoreGraphics/CGGeometry.h>
#else // ! TARGET_OS_IPHONE
#import <ApplicationServices/../Frameworks/CoreGraphics.framework/Headers/CGGeometry.h>
#endif  // ! TARGET_OS_IPHONE

/* Note that NSNotifications posted by AVPlayerItem may be posted on a different thread from the one on which the observer was registered. */

// notification                                                                description
extern NSString *const AVPlayerItemDidPlayToEndTimeNotification				// item has played to its end time
							__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
/*!
 @enum AVPlayerItemStatus
 @abstract
	These constants are returned by the AVPlayerItem status property to indicate whether it can successfully be played.
 
 @constant	 AVPlayerItemStatusUnknown
	Indicates that the status of the player item is not yet known because it has not tried to load new media resources
	for playback.
 @constant	 AVPlayerItemStatusReadyToPlay
	Indicates that the player item is ready to be played.
 @constant	 AVPlayerItemStatusFailed
	Indicates that the player item can no longer be played because of an error. The error is described by the value of
	the player item's error property.
 */
enum {
	AVPlayerItemStatusUnknown,
	AVPlayerItemStatusReadyToPlay,
	AVPlayerItemStatusFailed
};
typedef NSInteger AVPlayerItemStatus;

@class AVPlayer;
@class AVAsset;
@class AVAssetTrack;
@class AVAudioMix;
@class AVVideoComposition;
@class AVPlayerItemInternal;

@interface AVPlayerItem : NSObject <NSCopying>
{
@private
	AVPlayerItemInternal* _playerItem;
}

/*!
 @method			playerItemWithURL:
 @abstract		Returns an instance of AVPlayerItem for playing a resource at the specified location.
 @param			URL
 @result			An instance of AVPlayerItem.
 @discussion	
 */
+ (AVPlayerItem *)playerItemWithURL:(NSURL *)URL;

/*!
 @method			playerItemWithAsset:
 @abstract		Returns an instance of AVPlayerItem for playing an AVAsset.
 @param			asset
 @result			An instance of AVPlayerItem.
 @discussion	
 */
+ (AVPlayerItem *)playerItemWithAsset:(AVAsset *)asset;

/*!
 @method			initWithURL:
 @abstract		Initializes an AVPlayerItem with an NSURL.
 @param			URL
 @result			An instance of AVPlayerItem
 @discussion	
 */
- (id)initWithURL:(NSURL *)URL;

/*!
 @method			initWithAsset:
 @abstract		Initializes an AVPlayerItem with an AVAsset.
 @param			asset
 @result			An instance of AVPlayerItem
 @discussion	
 */
- (id)initWithAsset:(AVAsset *)asset;

/*!
 @property status
 @abstract
	The ability of the receiver to be used for playback.
 
 @discussion
	The value of this property is an AVPlayerItemStatus that indicates whether the receiver can be used for playback.
	When the value of this property is AVPlayerItemStatusFailed, the receiver can no longer be used for playback and
	a new instance needs to be created in its place. When this happens, clients can check the value of the error
	property to determine the nature of the failure. This property is key value observable.
 */
@property (nonatomic, readonly) AVPlayerItemStatus status;

/*!
 @property error
 @abstract
	If the receiver's status is AVPlayerItemStatusFailed, this describes the error that caused the failure.
 
 @discussion
	The value of this property is an NSError that describes what caused the receiver to no longer be able to be played.
	If the receiver's status is not AVPlayerItemStatusFailed, the value of this property is nil.
 */
@property (nonatomic, readonly) NSError *error;

/*!
 @method			currentTime
 @abstract			Returns the current time of the item.
 @result			A CMTime
 @discussion		Returns the current time of the item.
 */
- (CMTime)currentTime;

/*!
 @method			seekToTime:
 @abstract			Moves the playback cursor.
 @param				time
 @discussion		Use this method to seek to a specified time for the item.
					The time seeked to may differ from the specified time for efficiency. For sample accurate seeking see seekToTime:toleranceBefore:toleranceAfter:.
 */
- (void)seekToTime:(CMTime)time;

/*!
 @method			seekToTime:toleranceBefore:toleranceAfter:
 @abstract			Moves the playback cursor within a specified time bound.
 @param				time
 @param				toleranceBefore
 @param				toleranceAfter
 @discussion		Use this method to seek to a specified time for the item.
					The time seeked to will be within the range [time-toleranceBefore, time+toleranceAfter] and may differ from the specified time for efficiency.
					Pass kCMTimeZero for both toleranceBefore and toleranceAfter to request sample accurate seeking which may incur additional decoding delay. 
					Messaging this method with beforeTolerance:kCMTimePositiveInfinity and afterTolerance:kCMTimePositiveInfinity is the same as messaging seekToTime: directly.
 */
- (void)seekToTime:(CMTime)time toleranceBefore:(CMTime)toleranceBefore toleranceAfter:(CMTime)toleranceAfter;

/* Accessor for underlying AVAsset provided during initialization. */
@property (nonatomic, readonly) AVAsset *asset;

/* Provides array of AVPlayerItem tracks. Observable (can change dynamically during playback). */
@property (nonatomic, readonly) NSArray *tracks;

/* indicates the size at which the visual portion of the item is presented by the player; can be scaled from this size to fit within the bounds of an AVPlayerLayer via its videoGravity property */
@property (nonatomic, readonly) CGSize presentationSize;

/*!
 @property forwardPlaybackEndTime
 @abstract
	The end time for forward playback.
 
 @discussion
	Specifies the time at which playback should end when the playback rate is positive (see AVPlayer's rate property).
	The default value is kCMTimeInvalid, which indicates that no end time for forward playback is specified.
	In this case, the effective end time for forward playback is the receiver's duration.

	The value of this property has no effect on playback when the rate is negative.
*/
@property (nonatomic) CMTime forwardPlaybackEndTime;


/*!
 @property reversePlaybackEndTime
 @abstract
	The end time for reverse playback.
 
 @discussion
	Specifies the time at which playback should end when the playback rate is negative (see AVPlayer's rate property).
	The default value is kCMTimeInvalid, which indicates that no end time for reverse playback is specified.
	In this case, the effective end time for reverse playback is kCMTimeZero.

	The value of this property has no effect on playback when the rate is positive.
 */
@property (nonatomic) CMTime reversePlaybackEndTime;

/* indicates the audio mix parameters to be applied during playback */
@property (nonatomic, copy) AVAudioMix *audioMix;

/* Indicates the video composition settings to be applied during playback.
   Note that if any AVPlayerItem played by an AVPlayer has a non-nil videoComposition,
   that instance of AVPlayer will expect all of the AVPlayerItems it plays to have a non-nil videoComposition. */
@property (nonatomic, copy) AVVideoComposition *videoComposition;

/*!
 @method		stepByCount:
 @abstract      Moves player's current item's current time forward or backward by the specified number of steps.
 @param 		stepCount
   The number of steps by which to move. A positive number results in stepping forward, a negative number in stepping backward.
 @discussion
   The size of each step depends on the enabled AVPlayerItemTracks of the AVPlayerItem. 
 */
- (void)stepByCount:(NSInteger)stepCount;

/*!
 @method		seekToDate
 @abstract		move playhead to a point corresponding to a particular date.
 @discussion
   For playback content that is associated with a range of dates, move the
   playhead to point within that range. Will fail if the supplied date is outside
   the range or if the content is not associated with a range of dates.
 @param			date	The new position for the playhead.
 @result		Returns true if the playhead was moved to the supplied date.
 */
- (BOOL)seekToDate:(NSDate *)date;

/*!
 @property playbackLikelyToKeepUp
 @abstract Indicates whether the item will likely play through without stalling.
 @discussion This property communicates a prediction of playability. Factors considered in this prediction
	include I/O throughput and media decode performance. It is possible for playbackLikelyToKeepUp to
	indicate NO while the property playbackBufferFull indicates YES. In this event the playback buffer has
	reached capacity but there isn't the statistical data to support a prediction that playback is likely to 
	keep up. It is left to the application programmer to decide to continue media playback or not. 
	See playbackBufferFull below.
  */
@property (nonatomic, readonly, getter=isPlaybackLikelyToKeepUp) BOOL playbackLikelyToKeepUp;

/*! 
 @property playbackBufferFull
 @abstract Indicates that the internal media buffer is full and that further I/O is suspended.
 @discussion This property reports that the data buffer used for playback has reach capacity.
	Despite the playback buffer reaching capacity there might not exist sufficient statistical 
	data to support a playbackLikelyToKeepUp prediction of YES. See playbackLikelyToKeepUp above.
 */

@property (nonatomic, readonly, getter=isPlaybackBufferFull) BOOL playbackBufferFull;

/* indicates that playback has consumed all buffered media and that playback will stall or end */
@property (nonatomic, readonly, getter=isPlaybackBufferEmpty) BOOL playbackBufferEmpty;

/* array of NSValues containing CMTimeRanges*/
@property (nonatomic, readonly) NSArray *seekableTimeRanges;

/* array of NSValues containing CMTimeRanges */
@property (nonatomic, readonly) NSArray *loadedTimeRanges;

/* The timed metadata played most recently by the media stream. NSArray[ AVMetadataItem ] */
@property (nonatomic, readonly) NSArray *timedMetadata;

@end
