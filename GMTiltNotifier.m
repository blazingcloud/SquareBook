//
//  GMTiltNotifier.m
//  Glimmer
//
//  Created by Pablo Kang on 10/14/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import "GMTiltNotifier.h"

NSString * const GMTouchViewTiltLeftNotification = @"GMTouchViewTiltLeftNotification";
NSString * const GMTouchViewTiltRightNotification = @"GMTouchViewTiltRightNotification";
NSString * const GMTouchViewTiltLevelNotification = @"GMTouchViewTiltLevelNotification";

static const float kAccelerometerFrequency = 50.0; //Hz

@implementation GMTiltNotifier


- (id)init {
	if ((self = [super init])) {
		UIAccelerometer *accelerometer = [UIAccelerometer sharedAccelerometer];
		accelerometer.updateInterval = 1 / kAccelerometerFrequency;
		accelerometer.delegate = self;	
	}
	return self;
}

#pragma mark -
#pragma mark UIAccelerometerDelegate

- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration {
	
	// The x gives us the landscape orientation:
	//    negative means home button on the right
	//        +y means left tilt
	//        -y means right tilt
	//    positive menas home button on the left
	//        -y means right tilt
	//        +y means left tilt
	// We also don't say it's tilted unless the y is greater than a specific threshold
	
	static const float threshold = 0.15;
	float y = acceleration.y;
	float absY = fabs(y);
	NSString *tiltNotification;
	if (absY >= threshold) {
		if (acceleration.x < 0) {
			tiltNotification = y > 0 ? GMTouchViewTiltLeftNotification : GMTouchViewTiltRightNotification;
		} else {
			tiltNotification = y < 0 ? GMTouchViewTiltLeftNotification : GMTouchViewTiltRightNotification;
		}
	} else {
		tiltNotification = GMTouchViewTiltLevelNotification;
	}
	
	if (lastTiltNotification != tiltNotification) {
		lastTiltNotification = tiltNotification;
		NSNotification *notification = [NSNotification notificationWithName:tiltNotification
																	 object:self];
		[[NSNotificationCenter defaultCenter] postNotification:notification];
	}
}

- (void)dealloc {
	[UIAccelerometer sharedAccelerometer].delegate = nil;
	[super dealloc];
}


@end
