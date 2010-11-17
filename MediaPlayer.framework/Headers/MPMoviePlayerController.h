//
//  MPMoviePlayerController.h
//  MediaPlayer
//
//  Copyright 2008-2010 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MPMediaPlayback.h>
#import <UIKit/UIKit.h>

// -----------------------------------------------------------------------------
// Types

enum {
    MPMovieScalingModeNone,       // No scaling
    MPMovieScalingModeAspectFit,  // Uniform scale until one dimension fits
    MPMovieScalingModeAspectFill, // Uniform scale until the movie fills the visible bounds. One dimension may have clipped contents
    MPMovieScalingModeFill        // Non-uniform scale. Both render dimensions will exactly match the visible bounds
};
typedef NSInteger MPMovieScalingMode;

enum {
    MPMoviePlaybackStateStopped,
    MPMoviePlaybackStatePlaying,
    MPMoviePlaybackStatePaused,
    MPMoviePlaybackStateInterrupted,
    MPMoviePlaybackStateSeekingForward,
    MPMoviePlaybackStateSeekingBackward
};
typedef NSInteger MPMoviePlaybackState;

enum {
    MPMovieLoadStateUnknown        = 0,
    MPMovieLoadStatePlayable       = 1 << 0,
    MPMovieLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
    MPMovieLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};
typedef NSInteger MPMovieLoadState;

enum {
    MPMovieRepeatModeNone,
    MPMovieRepeatModeOne
};
typedef NSInteger MPMovieRepeatMode;

enum {
    MPMovieControlStyleNone,       // No controls
    MPMovieControlStyleEmbedded,   // Controls for an embedded view
    MPMovieControlStyleFullscreen, // Controls for fullscreen playback
    
    MPMovieControlStyleDefault = MPMovieControlStyleEmbedded
};
typedef NSInteger MPMovieControlStyle;

enum {
    MPMovieFinishReasonPlaybackEnded,
    MPMovieFinishReasonPlaybackError,
    MPMovieFinishReasonUserExited
};
typedef NSInteger MPMovieFinishReason;

// -----------------------------------------------------------------------------
// Movie Property Types

enum {
    MPMovieMediaTypeMaskNone  = 0,
    MPMovieMediaTypeMaskVideo = 1 << 0,
    MPMovieMediaTypeMaskAudio = 1 << 1
};
typedef NSInteger MPMovieMediaTypeMask;

enum {
    MPMovieSourceTypeUnknown,
    MPMovieSourceTypeFile,     // Local or progressively downloaded network content
    MPMovieSourceTypeStreaming // Live or on-demand streaming content
};
typedef NSInteger MPMovieSourceType;

// -----------------------------------------------------------------------------
// Movie Player
// 
// See MPMediaPlayback.h for the playback methods.

MP_EXTERN_CLASS_AVAILABLE(2_0) @interface MPMoviePlayerController : NSObject <MPMediaPlayback> {
@private
    id _internal;
}

- (id)initWithContentURL:(NSURL *)url;

- (NSURL *)contentURL;

- (void)setContentURL:(NSURL *)contentURL;

// The view in which the media and playback controls are displayed.
@property(nonatomic, readonly) UIView *view;

// A view for customization which is always displayed behind movie content.
@property(nonatomic, readonly) UIView *backgroundView;

// Returns the current playback state of the movie player.
@property(nonatomic, readonly) MPMoviePlaybackState playbackState;

// Returns the network load state of the movie player.
@property(nonatomic, readonly) MPMovieLoadState loadState;

// The style of the playback controls. Defaults to MPMovieControlStyleDefault.
@property(nonatomic) MPMovieControlStyle controlStyle;

// Determines how the movie player repeats when reaching the end of playback. Defaults to MPMovieRepeatModeNone.
@property(nonatomic) MPMovieRepeatMode repeatMode;

// Indicates if a movie should automatically start playback when it is likely to finish uninterrupted based on e.g. network conditions. Defaults to YES.
@property(nonatomic) BOOL shouldAutoplay;

// Indicates if the movie player should inherit the application's audio session instead of creating a new session (which would interrupt the application's session).
// Defaults to YES. Setting this property during playback will not take effect until playback is stopped and started again.
@property(nonatomic) BOOL useApplicationAudioSession;

// Determines if the movie is presented in the entire screen (obscuring all other application content). Default is NO.
// Setting this property to YES before the movie player's view is visible will have no effect.
@property(nonatomic, getter=isFullscreen) BOOL fullscreen;
- (void)setFullscreen:(BOOL)fullscreen animated:(BOOL)animated;

// Determines how the content scales to fit the view. Defaults to MPMovieScalingModeAspectFit.
@property(nonatomic) MPMovieScalingMode scalingMode;

@end

// -----------------------------------------------------------------------------
// Movie properties of the current movie prepared for playback.

@interface MPMoviePlayerController (MPMovieProperties)

// The types of media in the movie, or MPMovieMediaTypeNone if not known.
@property(nonatomic, readonly) MPMovieMediaTypeMask movieMediaTypes;

// The playback type of the movie. Defaults to MPMovieSourceTypeUnknown.
// Specifying a playback type before playing the movie can result in faster load times.
@property(nonatomic) MPMovieSourceType movieSourceType;

// The duration of the movie, or 0.0 if not known.
@property(nonatomic, readonly) NSTimeInterval duration;

// The currently playable duration of the movie, for progressively downloaded network content.
@property(nonatomic, readonly) NSTimeInterval playableDuration;

// The natural size of the movie, or CGSizeZero if not known/applicable.
@property(nonatomic, readonly) CGSize naturalSize;

// The start time of movie playback. Defaults to NaN, indicating the natural start time of the movie.
@property(nonatomic) NSTimeInterval initialPlaybackTime;

// The end time of movie playback. Defaults to NaN, which indicates natural end time of the movie.
@property(nonatomic) NSTimeInterval endPlaybackTime;

@end

// -----------------------------------------------------------------------------
// Movie Player Notifications

// Posted when the scaling mode changes.
MP_EXTERN NSString *const MPMoviePlayerScalingModeDidChangeNotification;

// Posted when movie playback ends or a user exits playback.
MP_EXTERN NSString *const MPMoviePlayerPlaybackDidFinishNotification;

MP_EXTERN NSString *const MPMoviePlayerPlaybackDidFinishReasonUserInfoKey NS_AVAILABLE_IPHONE(3_2); // NSNumber (MPMovieFinishReason)

// Posted when the playback state changes, either programatically or by the user.
MP_EXTERN NSString *const MPMoviePlayerPlaybackStateDidChangeNotification NS_AVAILABLE_IPHONE(3_2);

// Posted when the network load state changes.
MP_EXTERN NSString *const MPMoviePlayerLoadStateDidChangeNotification NS_AVAILABLE_IPHONE(3_2);

// Posted when the currently playing movie changes.
MP_EXTERN NSString *const MPMoviePlayerNowPlayingMovieDidChangeNotification NS_AVAILABLE_IPHONE(3_2);

// Posted when the movie player enters or exits fullscreen mode.
MP_EXTERN NSString *const MPMoviePlayerWillEnterFullscreenNotification NS_AVAILABLE_IPHONE(3_2);
MP_EXTERN NSString *const MPMoviePlayerDidEnterFullscreenNotification NS_AVAILABLE_IPHONE(3_2);
MP_EXTERN NSString *const MPMoviePlayerWillExitFullscreenNotification NS_AVAILABLE_IPHONE(3_2);
MP_EXTERN NSString *const MPMoviePlayerDidExitFullscreenNotification NS_AVAILABLE_IPHONE(3_2);
MP_EXTERN NSString *const MPMoviePlayerFullscreenAnimationDurationUserInfoKey NS_AVAILABLE_IPHONE(3_2); // NSNumber of double (NSTimeInterval)
MP_EXTERN NSString *const MPMoviePlayerFullscreenAnimationCurveUserInfoKey NS_AVAILABLE_IPHONE(3_2);     // NSNumber of NSUInteger (UIViewAnimationCurve)

// -----------------------------------------------------------------------------
// Movie Property Notifications

// Calling -prepareToPlay on the movie player will begin determining movie properties asynchronously.
// These notifications are posted when the associated movie property becomes available.
MP_EXTERN NSString *const MPMovieMediaTypesAvailableNotification NS_AVAILABLE_IPHONE(3_2);
MP_EXTERN NSString *const MPMovieSourceTypeAvailableNotification NS_AVAILABLE_IPHONE(3_2); // Posted if the movieSourceType is MPMovieSourceTypeUnknown when preparing for playback.
MP_EXTERN NSString *const MPMovieDurationAvailableNotification NS_AVAILABLE_IPHONE(3_2);
MP_EXTERN NSString *const MPMovieNaturalSizeAvailableNotification NS_AVAILABLE_IPHONE(3_2);

// -----------------------------------------------------------------------------
// Thumbnails

enum {
    MPMovieTimeOptionNearestKeyFrame,
    MPMovieTimeOptionExact
};
typedef NSInteger MPMovieTimeOption;


@interface MPMoviePlayerController (MPMoviePlayerThumbnailGeneration)

// Returns a thumbnail at the given time.
- (UIImage *)thumbnailImageAtTime:(NSTimeInterval)playbackTime timeOption:(MPMovieTimeOption)option;

// Asynchronously request thumbnails for one or more times, provided as an array of NSNumbers (double).
// Posts MPMoviePlayerThumbnailImageRequestDidFinishNotification on completion.
- (void)requestThumbnailImagesAtTimes:(NSArray *)playbackTimes timeOption:(MPMovieTimeOption)option;

// Cancels all pending asynchronous thumbnail requests.
- (void)cancelAllThumbnailImageRequests;

@end

// Posted when each thumbnail image request is completed.
MP_EXTERN NSString *const MPMoviePlayerThumbnailImageRequestDidFinishNotification NS_AVAILABLE_IPHONE(3_2);
MP_EXTERN NSString *const MPMoviePlayerThumbnailImageKey NS_AVAILABLE_IPHONE(3_2); // UIImage, may be nil if an error occurred.
MP_EXTERN NSString *const MPMoviePlayerThumbnailTimeKey NS_AVAILABLE_IPHONE(3_2);  // NSNumber (double)
MP_EXTERN NSString *const MPMoviePlayerThumbnailErrorKey NS_AVAILABLE_IPHONE(3_2); // NSError

// -----------------------------------------------------------------------------
// Timed Metadata

@interface MPMoviePlayerController (MPMoviePlayerTimedMetadataAdditions)

// Returns an array of the most recent MPTimedMetadata objects provided by the media stream.
- (NSArray *)timedMetadata NS_AVAILABLE_IPHONE(4_0);

@end

MP_EXTERN_CLASS_AVAILABLE(4_0) @interface MPTimedMetadata : NSObject {
@private
    id _internal;
}

// A key which identifies a piece of timed metadata.
@property(nonatomic, readonly) NSString *key;

// The namespace of the identifying key.
@property(nonatomic, readonly) NSString *keyspace;

// The object value of the metadata.
@property(nonatomic, readonly) id value;

// The timestamp of the metadata, in the timebase of the media stream.
@property(nonatomic, readonly) NSTimeInterval timestamp;

// A dictionary containing all metadata information associated with this object, which may hold additional key-specific data (see below).
@property(nonatomic, readonly) NSDictionary *allMetadata;

@end

// Posted when new timed metadata arrives.
MP_EXTERN NSString *const MPMoviePlayerTimedMetadataUpdatedNotification NS_AVAILABLE_IPHONE(4_0);
MP_EXTERN NSString *const MPMoviePlayerTimedMetadataUserInfoKey NS_AVAILABLE_IPHONE(4_0);       // NSArray of the most recent MPTimedMetadata objects.

// Additional dictionary keys for use with the 'allMetadata' property. All keys are optional.
MP_EXTERN NSString *const MPMoviePlayerTimedMetadataKeyName NS_AVAILABLE_IPHONE(4_0);           // NSString
MP_EXTERN NSString *const MPMoviePlayerTimedMetadataKeyInfo NS_AVAILABLE_IPHONE(4_0);           // NSString
MP_EXTERN NSString *const MPMoviePlayerTimedMetadataKeyMIMEType NS_AVAILABLE_IPHONE(4_0);       // NSString
MP_EXTERN NSString *const MPMoviePlayerTimedMetadataKeyDataType NS_AVAILABLE_IPHONE(4_0);       // NSString
MP_EXTERN NSString *const MPMoviePlayerTimedMetadataKeyLanguageCode NS_AVAILABLE_IPHONE(4_0);   // NSString (ISO 639-2)

// -----------------------------------------------------------------------------
// Deprecated methods and properties
// These will be removed in a future release of iPhone OS

typedef enum {
    MPMovieControlModeDefault,
    MPMovieControlModeVolumeOnly,
    MPMovieControlModeHidden
} MPMovieControlMode;

@interface MPMoviePlayerController (MPMoviePlayerDeprecated)

// Use the backgroundView property instead.
- (void)setBackgroundColor:(UIColor *)backgroundColor NS_DEPRECATED_IPHONE(2_0, 3_2);
- (UIColor *)backgroundColor NS_DEPRECATED_IPHONE(2_0, 3_2);

// Use the movieControlStyle property instead.
- (void)setMovieControlMode:(MPMovieControlMode)movieControlMode NS_DEPRECATED_IPHONE(2_0, 3_2);
- (MPMovieControlMode)movieControlMode NS_DEPRECATED_IPHONE(2_0, 3_2);

@end

// This notification is superseded by MPMediaPlaybackIsPreparedToPlayDidChangeNotification.
MP_EXTERN NSString *const MPMoviePlayerContentPreloadDidFinishNotification NS_DEPRECATED_IPHONE(2_0, 3_2);
