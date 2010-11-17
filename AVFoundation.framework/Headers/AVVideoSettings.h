/*
	File:  AVVideoSettings.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

/*!
	@class			AVVideoSettings
 
	@abstract		NSDictionary keys for configuring video compression
*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

extern NSString *const AVVideoCodecKey /* NSString (CMVideoCodecType) */                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	extern NSString *const AVVideoCodecH264 /* @"avc1" */                                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
    extern NSString *const AVVideoCodecJPEG /* @"jpeg" */                                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVVideoWidthKey /* NSNumber (encoded pixels) */                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVVideoHeightKey /* NSNumber (encoded pixels) */                                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVVideoScalingModeKey /* NSString */                                              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_NA);
	/* AVVideoScalingModeFit - Copy full width and height.  Write adjusted clean aperture and pixel aspect ratios to compensate for any change in dimensions. */
	extern NSString *const AVVideoScalingModeFit                                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_NA);
	/* AVVideoScalingModeResize - Crop to remove edge processing region; scale remainder to destination clean aperture. */
	extern NSString *const AVVideoScalingModeResize                                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_NA);
	/* AVVideoScalingModeResizeAspect - Preserve aspect ratio of the source, and fill remaining areas with black to fit destination dimensions. */
	extern NSString *const AVVideoScalingModeResizeAspect                                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_NA);
	/* AVVideoScalingModeResizeAspectFill - Preserve aspect ratio of the source, and crop picture to fit destination dimensions. */
	extern NSString *const AVVideoScalingModeResizeAspectFill                                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_NA);
extern NSString *const AVVideoCompressionPropertiesKey /* NSDictionary */                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	extern NSString *const AVVideoAverageBitRateKey /* NSNumber (bits per second) */                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	extern NSString *const AVVideoMaxKeyFrameIntervalKey /* NSNumber (1 means key frames only) */        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	extern NSString *const AVVideoProfileLevelKey                                                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoProfileLevelH264Baseline30 /* Baseline Profile Level 3.0 */        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoProfileLevelH264Baseline31 /* Baseline Profile Level 3.1 */        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoProfileLevelH264Main30 /* Main Profile Level 3.0 */                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoProfileLevelH264Main31 /* Main Profile Level 3.1 */                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	extern NSString *const AVVideoPixelAspectRatioKey /* NSDictionary */                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoPixelAspectRatioHorizontalSpacingKey /* NSNumber */                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoPixelAspectRatioVerticalSpacingKey /* NSNumber */                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
	extern NSString *const AVVideoCleanApertureKey /* NSDictionary */                                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoCleanApertureWidthKey /* NSNumber */                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoCleanApertureHeightKey /* NSNumber */                              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoCleanApertureHorizontalOffsetKey /* NSNumber */                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
		extern NSString *const AVVideoCleanApertureVerticalOffsetKey /* NSNumber */                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

