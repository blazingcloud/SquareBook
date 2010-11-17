/*
    File:  AVAnimation.h
 
    Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.
 
 */

#import <Foundation/Foundation.h>
#import <AVFoundation/AVBase.h>
#import <CoreFoundation/CFDate.h>

/*!
 @constant					AVCoreAnimationBeginTimeAtZero
 @discussion				Use this constant to set the CoreAnimation's animation beginTime property to be time 0.
							The constant is a small, non-zero, positive value which avoids CoreAnimation
							from replacing 0.0 with CACurrentMediaTime().
*/
extern const CFTimeInterval AVCoreAnimationBeginTimeAtZero __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);


/*!
	@constant		AVLayerVideoGravityResizeAspect
	@abstract		Preserve aspect ratio; fit within layer bounds.
	@discussion		AVLayerVideoGravityResizeAspect may be used when setting the videoGravity
                    property of an AVPlayerLayer or AVCaptureVideoPreviewLayer instance.
 */
extern NSString *const AVLayerVideoGravityResizeAspect __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);


/*!
	@constant		AVLayerVideoGravityResizeAspectFill
	@abstract		Preserve aspect ratio; fill layer bounds.
    @discussion     AVLayerVideoGravityResizeAspectFill may be used when setting the videoGravity
                    property of an AVPlayerLayer or AVCaptureVideoPreviewLayer instance.
 */
extern NSString *const AVLayerVideoGravityResizeAspectFill __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

/*!
	@constant		AVLayerVideoGravityResize
	@abstract		Stretch to fill layer bounds.
    @discussion     AVLayerVideoGravityResize may be used when setting the videoGravity
                    property of an AVPlayerLayer or AVCaptureVideoPreviewLayer instance.
 */
extern NSString *const AVLayerVideoGravityResize __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
