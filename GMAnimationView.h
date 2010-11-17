//
//  GMAnimationView.h
//  Glimmer
//
//  Created by Pablo Kang on 10/1/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import "GMAnimationSequencer.h"

@interface GMAnimationView : UIView {    
	MPMoviePlayerController *videoPlayer;
	UIImageView *backgroundView;
	UIImageView *foregroundView;
	GMAnimationSequencer *sequencer;
	BOOL animating;
}

- (void)loadPage:(NSString *)page;
- (void)tap:(NSString *)object;
- (void)tilt:(GMAnimationTiltType)tilt;

@end
