/*
	File:  AVAudioSession.h
	
	Framework:  AVFoundation
	
	Copyright 2009-2010 Apple Inc. All rights reserved.
	
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>	/* for NSTimeInterval */
#import <AvailabilityMacros.h>

/* This protocol is available with iPhone 3.0 or later */
@protocol AVAudioSessionDelegate;
@class NSError, NSString;

/* values for the category property */
extern NSString *const AVAudioSessionCategoryAmbient;
extern NSString *const AVAudioSessionCategorySoloAmbient;
extern NSString *const AVAudioSessionCategoryPlayback;
extern NSString *const AVAudioSessionCategoryRecord;
extern NSString *const AVAudioSessionCategoryPlayAndRecord;
extern NSString *const AVAudioSessionCategoryAudioProcessing;

enum {
	AVAudioSessionInterruptionFlags_ShouldResume = 1
};

enum {	
	AVAudioSessionSetActiveFlags_NotifyOthersOnDeactivation = 1
};

@interface AVAudioSession : NSObject {
@private
    __strong void *_impl;
}

 /* returns singleton instance */
+ (id)sharedInstance;

@property(assign) id<AVAudioSessionDelegate> delegate;

- (BOOL)setActive:(BOOL)beActive error:(NSError**)outError;
- (BOOL)setActive:(BOOL)beActive withFlags:(NSInteger)flags error:(NSError**)outError
	 __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);

- (BOOL)setCategory:(NSString*)theCategory error:(NSError**)outError;
- (BOOL)setPreferredHardwareSampleRate:(double)sampleRate error:(NSError**)outError;
- (BOOL)setPreferredIOBufferDuration:(NSTimeInterval)duration error:(NSError**)outError;

@property(readonly) NSString* category;
@property(readonly) double preferredHardwareSampleRate;
@property(readonly) NSTimeInterval preferredIOBufferDuration;

@property(readonly) BOOL inputIsAvailable;
@property(readonly) double currentHardwareSampleRate;
@property(readonly) NSInteger currentHardwareInputNumberOfChannels;
@property(readonly) NSInteger currentHardwareOutputNumberOfChannels;

@end


/* A protocol for delegates of AVAudioSession */
@protocol AVAudioSessionDelegate <NSObject>
@optional 

- (void)beginInterruption;

- (void)endInterruptionWithFlags:(NSUInteger)flags /* Currently the only flag is AVAudioSessionInterruptionFlags_ShouldResume. */
		__OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0);
		
- (void)endInterruption; /* endInterruptionWithFlags: will be called instead if implemented. */

- (void)inputIsAvailableChanged:(BOOL)isInputAvailable;
@end
