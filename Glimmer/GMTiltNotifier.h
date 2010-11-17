//
//  GMTiltNotifier.h
//  Glimmer
//
//  Created by Pablo Kang on 10/14/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const GMTouchViewTiltLeftNotification;
extern NSString * const GMTouchViewTiltRightNotification;
extern NSString * const GMTouchViewTiltLevelNotification;

@interface GMTiltNotifier : NSObject<UIAccelerometerDelegate> {
	NSString *lastTiltNotification;
}

@end
