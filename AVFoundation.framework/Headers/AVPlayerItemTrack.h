/*
	File:  AVPlayerItemTrack.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

@class AVPlayerImageProvider;
@class AVAssetTrack;
@class AVPlayerItemTrackInternal;

@interface AVPlayerItemTrack : NSObject
{
@private
	AVPlayerItemTrackInternal	*_playerItemTrack;
}

/* indicates the AVAssetTrack for which the AVPlayerItemTrack represents presentation state  */
@property (nonatomic, readonly) AVAssetTrack *assetTrack;

/* indicates whether the track is enabled for presentation during playback */
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

@end
