//
//  GMAnimationView.h
//  Glimmer
//
//  Created by Pablo Kang on 10/1/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import "GMAnimationView.h"
#import "GMAnimation.h"

static GMAnimationTiltType lastTilt = kGMAnimationTiltLevel;

@implementation GMAnimationView

#pragma mark -
#pragma mark Setup

- (id)initWithCoder:(NSCoder *)aDecoder {
	if ((self = [super initWithCoder:aDecoder])) {
		
		sequencer = [[GMAnimationSequencer alloc] init];
		
		backgroundView = [[UIImageView alloc] initWithFrame:self.frame];
		foregroundView = [[UIImageView alloc] initWithFrame:self.frame];
		[self addSubview:foregroundView];
	}
	return self;
}

- (void)loadPage:(NSString *)page {
	sequencer.page = page;
	animating = NO;
	if (videoPlayer) {
		// pause because if we call stop, preparedToPlay will be invoked
		[videoPlayer pause];
	}	
	UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"%@_default.png", page]];
	backgroundView.image = image;
	foregroundView.image = image;
	foregroundView.hidden = NO;
}

#pragma mark -
#pragma mark Animation

- (void)preparedToPlay {
	if (videoPlayer.loadState & MPMovieLoadStatePlayable &&
		videoPlayer.loadState & MPMovieLoadStatePlaythroughOK) {
		foregroundView.hidden = YES;
NSLog(@"videoPlayer play");
		[videoPlayer play];
	}
}

- (void)playNextVideo {
	GMAnimation *animation = [sequencer nextAnimation];

	if (!animation) {
		animating = NO;
		if (lastTilt != sequencer.currentTilt) {
			[self tilt:lastTilt];
		} else if (lastTilt == kGMAnimationTiltLevel) {
			foregroundView.hidden = NO;
		}
		return;
	}

	if (!videoPlayer) {
	    videoPlayer = [[MPMoviePlayerController alloc] initWithContentURL:animation.url];
	    videoPlayer.view.frame = self.frame;
	    [videoPlayer.backgroundView addSubview:backgroundView];
	    videoPlayer.movieSourceType = MPMovieSourceTypeFile;
	    videoPlayer.controlStyle = MPMovieControlStyleNone;
	    videoPlayer.scalingMode = MPMovieScalingModeFill;
	    [self insertSubview:videoPlayer.view atIndex:0];
		
		[[NSNotificationCenter defaultCenter] addObserver:self 
												 selector:@selector(playNextVideo) 
													 name:MPMoviePlayerPlaybackDidFinishNotification
												   object:nil];	
		
		[[NSNotificationCenter defaultCenter] addObserver:self 
                                                 selector:@selector(preparedToPlay) 
                                                     name:MPMediaPlaybackIsPreparedToPlayDidChangeNotification 
                                                   object:nil];
		

	}

	if (animation.isReverse) {
		// Don't set URL again if it's the same URL when running in reverse.
		// Runs in fast reverse frame rate if we set it again. 
		BOOL didSet = NO;
		if (![animation.url.path isEqualToString:[videoPlayer contentURL].path]) {
			didSet = YES;
			[videoPlayer setContentURL:animation.url];
		}
		videoPlayer.currentPlaybackTime = videoPlayer.duration;
		videoPlayer.currentPlaybackRate = -1.0;
		if (didSet) {
			[self preparedToPlay];
		} else {
			[videoPlayer prepareToPlay];
		}
	} else {
		[videoPlayer setContentURL:animation.url];
		videoPlayer.currentPlaybackTime = -1.0;
		videoPlayer.currentPlaybackRate = 1.0;

		// If the video player was just created and the animation is played immediately,
		// a flash occurs because the video player didn't enough time to set itself up.
		// We want to wait till its ready before hiding the foreground view. Hence the
		// reason why the play code was factored out to the preparedToPlay method.
		[videoPlayer prepareToPlay];
	}

}

- (void)animate {
	if (!animating) {
		animating = YES;
		[self playNextVideo];
	}
}

- (void)tap:(NSString *)object {
	if (animating) return;
	[sequencer tap:object];
	[self animate];
}

- (void)tilt:(GMAnimationTiltType)tilt {
	lastTilt = tilt;
	if (animating) return;
	[sequencer tilt:tilt];
	[self animate];
}

#pragma mark -
#pragma mark Deallocation

- (void)dealloc {
	[[NSNotificationCenter defaultCenter] removeObserver:self];
	[backgroundView removeFromSuperview];
	[backgroundView release];
	[videoPlayer release];
	[sequencer release];
    [super dealloc];
}

@end