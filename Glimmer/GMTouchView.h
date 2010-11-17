//
//  GMTouchView.h
//  Glimmer
//
//  Created by Pablo Kang on 10/5/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString * const GMTouchViewTapNotification;
extern NSString * const GMTouchViewSwipeLeftNotification;
extern NSString * const GMTouchViewSwipeRightNotification;

@interface GMTouchView : UIView  {
	NSMutableArray *masks;
	UITapGestureRecognizer *tapGesture;
}

@property (nonatomic, readonly) NSString *lastObjectTapped;

- (void)loadMasks:(NSDictionary *)pageConfig;

@end