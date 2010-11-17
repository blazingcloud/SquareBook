//
//  GMPageViewController.m
//  Glimmer
//
//  Created by Pablo Kang on 9/30/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import "GMPageViewController.h"

@implementation GMPageViewController

@synthesize currentPage;

- (void)handleTap {
	[animationView tap:touchView.lastObjectTapped];
}

- (void)turnPage:(NSNotification *)notification {
	if (notification.name == GMTouchViewSwipeLeftNotification) {
		currentPage = (currentPage+1) % animationConfig.count;
	} else if (currentPage > 0) {
		--currentPage;
	} else {
		// at the beginning
		return;
	}
	
	[textView stop];
	textView.hidden = YES;
	
	NSDictionary *nextPageConfig = [animationConfig objectAtIndex:currentPage];
	NSString *pageName = [nextPageConfig objectForKey:@"name"];
	
	NSString *imageName = [NSString stringWithFormat:@"%@_default", pageName];
	NSString *imagePath = [[NSBundle mainBundle] pathForResource:imageName ofType:@"png"];
	UIImage *image = [[UIImage alloc] initWithContentsOfFile:imagePath];
	nextPageView.image = image;	
	[image release];
	
	UIViewAnimationTransition transition;
	if (notification.name == GMTouchViewSwipeLeftNotification) {
		transition = (self.interfaceOrientation & UIInterfaceOrientationLandscapeRight)
						? UIViewAnimationTransitionCurlUp
						: UIViewAnimationTransitionCurlDown;
	} else {
		transition = (self.interfaceOrientation & UIDeviceOrientationLandscapeLeft)
						? UIViewAnimationTransitionCurlDown
						: UIViewAnimationTransitionCurlUp;
	}
		
	[UIView beginAnimations:nil context:nil];
	[UIView setAnimationDuration:1.0];
	[UIView setAnimationTransition:transition forView:self.view cache:YES];
	[UIView setAnimationDelegate:self];
	[UIView setAnimationDidStopSelector:@selector(loadPage)];
	animationView.hidden = YES;
	[UIView commitAnimations];
}

- (void)handleTilt:(NSNotification *)notification {
	if (notification.name == GMTouchViewTiltLevelNotification) {
		[animationView tilt:kGMAnimationTiltLevel];
	} else if (notification.name == GMTouchViewTiltLeftNotification) {
		[animationView tilt:kGMAnimationTiltLeft];
	} else if (notification.name == GMTouchViewTiltRightNotification) {
		[animationView tilt:kGMAnimationTiltRight];
	}
}

- (void)loadPage {
	NSDictionary *pageConfig = [animationConfig objectAtIndex:currentPage];
	NSString *page = [pageConfig objectForKey:@"name"];
    
NSLog(@"page name: %@", page);

	[textView loadPage:page withConfig:[pageConfig objectForKey:@"words"]];
	textView.hidden = NO;

	[animationView loadPage:page];
	[touchView loadMasks:pageConfig];
	[textView play];

	animationView.hidden = NO;
	touchView.hidden = NO;
	nextPageView.image = nil;
}

- (void) buildUp {
    tiltNotifier = [[GMTiltNotifier alloc] init];
	textView.fontName = @"AmericanTypewriter-Bold";
	textView.fontSize = 24;
	textView.hiliteColor = [UIColor redColor];
	
	NSString *path = [[NSBundle mainBundle] pathForResource:@"Glimmer-Animation" ofType:@"plist"];
	animationConfig = [[NSArray alloc] initWithContentsOfFile:path];
	
	[self loadPage];
	
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:@selector(handleTap) 
												 name:GMTouchViewTapNotification
											   object:nil];
    
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:@selector(turnPage:) 
												 name:GMTouchViewSwipeLeftNotification
											   object:nil];
    
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:@selector(turnPage:) 
												 name:GMTouchViewSwipeRightNotification
											   object:nil];
	
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:@selector(handleTilt:) 
												 name:GMTouchViewTiltLevelNotification
											   object:nil];
    
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:@selector(handleTilt:) 
												 name:GMTouchViewTiltLeftNotification
											   object:nil];
    
	[[NSNotificationCenter defaultCenter] addObserver:self 
											 selector:@selector(handleTilt:) 
												 name:GMTouchViewTiltRightNotification
											   object:nil];
}

- (void) tearDown {
NSLog(@"application terminated on page: %d", currentPage);
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
	[animationConfig release];
	animationConfig = nil;
	[tiltNotifier release];
	tiltNotifier = nil;    
}

#pragma mark -
#pragma mark View lifecycle

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
	return interfaceOrientation == UIInterfaceOrientationLandscapeLeft || interfaceOrientation == UIInterfaceOrientationLandscapeRight;
}


#pragma mark -
#pragma mark Memory management

- (void)dealloc {
	[animationConfig release];
	[tiltNotifier release];
    [super dealloc];
}


@end
