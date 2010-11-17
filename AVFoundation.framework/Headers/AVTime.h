/*
	File:  AVTime.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMTimeRange.h>


// utilities for carriage of CoreMedia time structures in NSValues

@interface NSValue (NSValueAVFoundationExtensions)

+ (NSValue *)valueWithCMTime:(CMTime)time;
- (CMTime)CMTimeValue;

+ (NSValue *)valueWithCMTimeRange:(CMTimeRange)timeRange;
- (CMTimeRange)CMTimeRangeValue;

+ (NSValue *)valueWithCMTimeMapping:(CMTimeMapping)timeMapping;
- (CMTimeMapping)CMTimeMappingValue;

@end

// utilities for encoding and decoding CoreMedia time structures for NSCoding

@interface NSCoder (AVTimeCoding)
- (void)encodeCMTime:(CMTime)time forKey:(NSString *)key;
- (CMTime)decodeCMTimeForKey:(NSString *)key;

- (void)encodeCMTimeRange:(CMTimeRange)timeRange forKey:(NSString *)key;
- (CMTimeRange)decodeCMTimeRangeForKey:(NSString *)key;

- (void)encodeCMTimeMapping:(CMTimeMapping)timeMapping forKey:(NSString *)key;
- (CMTimeMapping)decodeCMTimeMappingForKey:(NSString *)key;
@end

