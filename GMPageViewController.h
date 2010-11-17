//
//  GMPageViewController.h
//  Glimmer
//
//  Created by Pablo Kang on 9/30/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GMAnimationView.h"
#import "GMTouchView.h"
#import "GMTextView.h"
#import "GMTiltNotifier.h"

@interface GMPageViewController : UIViewController {
	IBOutlet GMTouchView *touchView;
	IBOutlet GMAnimationView *animationView;
	IBOutlet UIImageView *nextPageView;
	IBOutlet GMTextView *textView;
	
	GMTiltNotifier *tiltNotifier;
	NSArray *animationConfig;
	int currentPage;
}

@property(readwrite) int currentPage;

- (void) buildUp;
- (void) tearDown;

@end
