//
//  GMTextView.h
//  Glimmer
//
//  Created by Pablo Kang on 10/12/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <QuartzCore/CADisplayLink.h>
#import <AVFoundation/AVAudioPlayer.h>

@interface GMTextView : UIView<AVAudioPlayerDelegate> {
	NSString *text;
	
	CADisplayLink *timer;
	AVAudioPlayer *player;
	NSArray *cueTimes;	
	NSString *pageName;

	CFRange hiliteRange;
	int cueIndex;
	BOOL checkForCues;
}

@property (nonatomic, retain) UIColor *hiliteColor;
@property (nonatomic, copy) NSString *fontName;
@property (nonatomic) int fontSize;

- (void)loadPage:(NSString *)page withConfig:(NSDictionary *)config;
- (void)play;
- (void)stop;

@end
