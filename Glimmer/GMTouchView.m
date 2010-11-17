//
//  GMTouchView.m
//  Glimmer
//
//  Created by Pablo Kang on 10/5/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import "GMTouchView.h"
#import "UIImage-Alpha.h"

NSString * const GMTouchViewTapNotification = @"GMTouchViewTapNotification";
NSString * const GMTouchViewSwipeLeftNotification = @"GMTouchViewSwipeLeftNotification";
NSString * const GMTouchViewSwipeRightNotification = @"GMTouchViewSwipeRightNotification";

@implementation GMTouchView

@synthesize lastObjectTapped;

- (void)setupSwipeGesture:(int)numberOfTouchesRequired {
    UISwipeGestureRecognizer *swipeGesture;
	
	swipeGesture = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipe:)];
	swipeGesture.direction = UISwipeGestureRecognizerDirectionLeft;
	swipeGesture.numberOfTouchesRequired = numberOfTouchesRequired;
	[self addGestureRecognizer:swipeGesture];
	[swipeGesture release];
	
	swipeGesture = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(swipe:)];
	swipeGesture.direction = UISwipeGestureRecognizerDirectionRight;
	swipeGesture.numberOfTouchesRequired = numberOfTouchesRequired;
	[self addGestureRecognizer:swipeGesture];
	[swipeGesture release];
}


- (void)initializeView {
	static const int maxTouches = 4;
	for (int touches = 1; touches <= maxTouches; touches++) {
		[self setupSwipeGesture:touches];
	}
}

- (id)initWithCoder:(NSCoder *)aDecoder {
	if ((self = [super initWithCoder:aDecoder])) {
		[self initializeView];
	}
	return self;
}

- (id)initWithFrame:(CGRect)frame {
	if ((self = [super initWithFrame:frame])) {
		[self initializeView];
	}
	return self;
}

- (void)sendNotification:(NSString *)notificationName {
	NSNotification *notification = [NSNotification notificationWithName:notificationName
																 object:self];
	[[NSNotificationCenter defaultCenter] postNotification:notification];
}

- (void)loadMasks:(NSDictionary *)pageConfig {
	if (masks) {
		[masks release];	
	}
    masks = [[NSMutableArray alloc] initWithCapacity:5];

	NSString *pageName = [pageConfig objectForKey:@"name"];
	for (NSString *tapObject in [pageConfig objectForKey:@"tap"]) {
		NSString *imageName = [NSString stringWithFormat:@"%@_tap%@", pageName, [tapObject capitalizedString]];
		NSString *imagePath = [[NSBundle mainBundle] pathForResource:imageName ofType:@"png"];
		UIImage *image = [[UIImage alloc] initWithContentsOfFile:imagePath];
		NSDictionary *mask = [[NSDictionary alloc] initWithObjectsAndKeys: image, @"image", tapObject, @"name", nil];
		[masks addObject:mask];
		[image release];
		[mask release];
	}

	if (tapGesture) {
		[tapGesture release];	
	}
	tapGesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(testImageHit:)];
    tapGesture.numberOfTapsRequired = 1;
    [self addGestureRecognizer:tapGesture];	

}

#pragma mark -
#pragma mark Gesture selectors

- (void)testImageHit:(UIGestureRecognizer *)gestureRecognizer {
	CGPoint point = [gestureRecognizer locationInView:self];
	
	for (NSDictionary *mask in [masks reverseObjectEnumerator]) {
		UIImage *maskImage = [mask objectForKey:@"image"];
		if (0 <= point.x && point.x <= maskImage.size.width &&
			0 <= point.y && point.y <= maskImage.size.height) {
			if (![maskImage isPointTransparent:CGPointMake(point.x, point.y)]) {
				if (lastObjectTapped) {
					[lastObjectTapped release];	
				}
				lastObjectTapped = [[mask objectForKey:@"name"] copy];
				[self sendNotification:GMTouchViewTapNotification];
				break;
			}
		}
	}
}

- (void)swipe:(UIGestureRecognizer *)gestureRecognizer {
	UISwipeGestureRecognizer *swipeGesture = (UISwipeGestureRecognizer *)gestureRecognizer;
	switch (swipeGesture.direction) {
		case UISwipeGestureRecognizerDirectionLeft:
			[self sendNotification:GMTouchViewSwipeLeftNotification];
			break;
		case UISwipeGestureRecognizerDirectionRight:
			[self sendNotification:GMTouchViewSwipeRightNotification];
			break;
		default:
			break;
	}
}


#pragma mark -
#pragma mark Deallocation

- (void)dealloc {
	[masks release];
	[lastObjectTapped release];
	[tapGesture release];
    [super dealloc];
}


@end

