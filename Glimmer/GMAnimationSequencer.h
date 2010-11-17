//
//  GMAnimationSequencer.h
//  Glimmer
//
//  Created by Pablo Kang on 10/14/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GMAnimation.h"

typedef enum {
	kGMAnimationTiltLevel,
	kGMAnimationTiltLeft,
	kGMAnimationTiltRight,
} GMAnimationTiltType;

@interface GMAnimationSequencer : NSObject {
	NSMutableArray *sequence;
}

@property (nonatomic, copy) NSString *page;
@property (nonatomic, readonly) GMAnimationTiltType currentTilt;

- (void)tilt:(GMAnimationTiltType)tilt;
- (void)tap:(NSString *)object;
- (GMAnimation *)nextAnimation;

@end
