/*
    File:  AVError.h
 
	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

 */

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

extern NSString *const AVFoundationErrorDomain                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

extern NSString *const AVErrorDeviceKey                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVErrorTimeKey                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVErrorFileSizeKey                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVErrorPIDKey                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVErrorRecordingSuccessfullyFinishedKey  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVErrorDiscontinuityFlagsKey				__OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_NA);

enum {
	AVErrorUnknown                                      = -11800,
	AVErrorOutOfMemory									= -11801,
	AVErrorSessionNotRunning                            = -11803,
	AVErrorDeviceAlreadyUsedByAnotherSession            = -11804,
	AVErrorNoDataCaptured                               = -11805,
	AVErrorSessionConfigurationChanged                  = -11806,
	AVErrorDiskFull                                     = -11807,
	AVErrorDeviceWasDisconnected                        = -11808,
	AVErrorMediaChanged                                 = -11809,
	AVErrorMaximumDurationReached                       = -11810,
	AVErrorMaximumFileSizeReached                       = -11811,
	AVErrorMediaDiscontinuity                           = -11812,
	AVErrorMaximumNumberOfSamplesForFileFormatReached   = -11813,
	AVErrorDeviceNotConnected                           = -11814,
	AVErrorDeviceInUseByAnotherApplication              = -11815,
	AVErrorDeviceLockedForConfigurationByAnotherProcess = -11817,
#if TARGET_OS_IPHONE
	AVErrorSessionWasInterrupted						= -11818,
	AVErrorMediaServicesWereReset						= -11819,
#endif
	AVErrorExportFailed									= -11820,
	AVErrorDecodeFailed									= -11821,
	AVErrorInvalidSourceMedia							= -11822,
	AVErrorFileAlreadyExists                            = -11823,
	AVErrorCompositionTrackSegmentsNotContiguous		= -11824,
	AVErrorInvalidCompositionTrackSegmentDuration		= -11825,
	AVErrorInvalidCompositionTrackSegmentSourceStartTime= -11826,
	AVErrorInvalidCompositionTrackSegmentSourceDuration	= -11827,
	AVErrorFileFormatNotRecognized                      = -11828,
	AVErrorFileFailedToParse                            = -11829,
    AVErrorMaximumStillImageCaptureRequestsExceeded     = -11830,
	AVErrorContentIsProtected							= -11831,
	AVErrorNoImageAtTime								= -11832,
};
