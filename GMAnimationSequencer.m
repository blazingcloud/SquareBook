//
//  GMAnimationSequencer.m
//  Glimmer
//
//  Created by Pablo Kang on 10/14/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import "GMAnimationSequencer.h"

@implementation GMAnimationSequencer

@synthesize page, currentTilt;

- (id)init {
	if ((self == [super init])) {
		sequence = [[NSMutableArray alloc] init];
		currentTilt = kGMAnimationTiltLevel;
	}
	return self;
}

- (void)addToSequence:(NSString *)action object:(NSString *)object reverse:(BOOL)reverse {
    
	NSString *fileName = [NSString stringWithFormat:@"%@_%@%@", page, action, [object capitalizedString]];
	NSString *path = [[NSBundle mainBundle] pathForResource:fileName ofType:@"mov"];

	if (path) {
		NSURL *url = [[NSURL alloc] initFileURLWithPath:path];
		GMAnimation *animation = [[GMAnimation alloc] initWithURL:url reverse:reverse];
		[sequence addObject:animation];
		[animation release];
		[url release];
	} else {
		NSLog(@"Error: no such file '%@'", fileName);
	}
}

- (void)setPage:(NSString *)aPage {
	[page release];
	page = [aPage copy];
	[sequence removeAllObjects];
}

- (NSString *)tiltToString:(GMAnimationTiltType)tilt {
	if (tilt == kGMAnimationTiltLeft) {
		return @"left";	
	}
	if (tilt == kGMAnimationTiltRight) {
		return @"right";	
	}
	return nil;
}

- (void)tilt:(GMAnimationTiltType)tilt {
	if (currentTilt == tilt) return;
	
	NSString *tiltObject;

	tiltObject= [self tiltToString:currentTilt];
	if (tiltObject) {
		[self addToSequence:@"tilt" object:tiltObject reverse:YES];
	}

	tiltObject= [self tiltToString:tilt];
	if (tiltObject) {
		[self addToSequence:@"tilt" object:tiltObject reverse:NO];
	}
	
	currentTilt = tilt;
}

- (void)tap:(NSString *)object {
	if (currentTilt != kGMAnimationTiltLevel) {
		[self tilt:kGMAnimationTiltLevel];
	}
	[self addToSequence:@"tap" object:object reverse:NO];
}

- (GMAnimation *)nextAnimation {
	if (sequence.count == 0) {
		return nil;
	}
	GMAnimation *next = [[sequence objectAtIndex:0] retain];
	[sequence removeObjectAtIndex:0];
	return [next autorelease];
}

- (void)dealloc {
	[page release];
	[sequence release];
	[super dealloc];
}

@end
