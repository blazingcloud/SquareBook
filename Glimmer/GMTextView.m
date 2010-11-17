//
//  GMTextView.m
//  Glimmer
//
//  Created by Pablo Kang on 10/12/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <CoreText/CoreText.h>
#import <QuartzCore/QuartzCore.h>
#import "GMTextView.h"

@implementation GMTextView

@synthesize fontName, fontSize, hiliteColor;

- (id)initWithCoder:(NSCoder *)aDecoder {
	if ((self = [super initWithCoder:aDecoder])) {
		self.fontName = @"Helvetica";
		self.fontSize = 12;
		self.hiliteColor = [UIColor redColor];
		hiliteRange = CFRangeMake(0, 0);
	}
	return self;
}

- (void)setCueTimes:(NSArray *)aCueTimes {
	if (cueTimes != aCueTimes) {
		[cueTimes release];
		cueTimes = [aCueTimes retain];
	}
}

- (void)setText:(NSString *)aText {
	[text release];
	if (aText) {
		NSMutableString *newText = [[NSMutableString alloc] init];
		for (NSString *line in [aText componentsSeparatedByString:@"\\n"]) {
			[newText appendString:line];
			[newText appendString:@"\n"];
		}
		text = [[NSString alloc] initWithString:newText];
	} else {
		text = [[NSString alloc] initWithString:@""];
	}
}

- (void)loadPage:(NSString *)page withConfig:(NSDictionary *)config {
	[pageName release];
	pageName = [page copy];
	[self setText:[config objectForKey:@"text"]];
    
	[self setCueTimes:[config objectForKey:@"cues"]];
    
	float x = [[config objectForKey:@"x"] floatValue];
	if (isnan(x)) x = 0;
	
	float y = [[config objectForKey:@"y"] floatValue];
	if (isnan(y)) y = 0;
	self.frame = CGRectMake(x, y, 600, 600);

	[self setNeedsDisplay];
}

- (void)hiliteNextWord {
	// TODO: doesn't work with hyphenated words.
	
	int location = hiliteRange.location + hiliteRange.length;
	do {
		unichar c = [text characterAtIndex:location];
		if (c == '\0') return; // means we're at the end of the string
		if (isalnum(c)) break;
		location++;
	} while (location < text.length);
	
	if (location >= text.length) return;
	
	int index = location;
	do {
		if (!isalnum([text characterAtIndex:index])) break;
		index++;
	} while (index < text.length);

	hiliteRange.location = location;
	hiliteRange.length = index - location;
}

- (void)refresh {
	if (checkForCues && player.playing) {
		float next = [[cueTimes objectAtIndex:cueIndex] floatValue];
		if (next <= player.currentTime) {
			[self hiliteNextWord];
			++cueIndex;
			if (cueIndex >= cueTimes.count) {
				checkForCues = NO;
			}
		}
	}
	
	[self setNeedsDisplay];
}

- (void)drawRect:(CGRect)rect {
	// http://forums.macrumors.com/showthread.php?t=925312
	CGContextRef context = UIGraphicsGetCurrentContext();

	CGContextTranslateCTM(context, 0.0f, rect.size.height); //seems to work better by translating, then scaling
	CGContextScaleCTM(context, 1.0f, -1.0f);
	CFMutableAttributedStringRef attributedString = CFAttributedStringCreateMutable(NULL, 0);
	CFAttributedStringBeginEditing(attributedString);	
	
	
	CFAttributedStringReplaceString(attributedString, CFRangeMake(0, 0), (CFStringRef)text);
	
	CTFontRef font = CTFontCreateWithName((CFStringRef)fontName, fontSize, NULL);
	CFAttributedStringSetAttribute(attributedString, CFRangeMake(0, text.length), kCTFontAttributeName, font);
	CFRelease(font);
	

	CFAttributedStringSetAttribute(attributedString, hiliteRange, kCTForegroundColorAttributeName, hiliteColor.CGColor);
	
	CFAttributedStringEndEditing(attributedString);	
	
	CTFramesetterRef frs = CTFramesetterCreateWithAttributedString(attributedString);
	CGMutablePathRef path = CGPathCreateMutable();
	
	CGPathAddRect(path, NULL, rect);
	
	CTFrameRef ctframe = CTFramesetterCreateFrame(frs, CFRangeMake(0, 0), path, NULL);	
	CGPathRelease(path);	
	CTFrameDraw(ctframe, context);
	CFRelease(frs);
	
	CFRelease(attributedString);
}

- (void)stop {
	hiliteRange.location = 0;
	hiliteRange.length = 0;
	
	[timer invalidate];	
	timer = nil;
	[player stop];
	[player release];
	player = nil;
	
	[self setNeedsDisplay];
}

- (void)play {
	[self stop];

	NSString *filePath = [[NSBundle mainBundle] pathForResource:pageName ofType:@"aiff"];
	if (!filePath) return;
	
	NSURL *url = [NSURL fileURLWithPath:filePath];
	if (!url) return;
	
	cueIndex = 0;
	checkForCues = cueTimes != nil;

	timer = [CADisplayLink displayLinkWithTarget:self selector:@selector(refresh)];
	[timer addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    
	player = [[AVAudioPlayer alloc] initWithContentsOfURL:url error:nil];
	player.delegate = self;
	[player prepareToPlay];
	[player play];
}

- (NSString*)description {
	return [NSString stringWithFormat:@"<%@: 0x%x | frame=(x=%f, y=%f, w=%f, h=%f) | fontName=%@ | fontSize=%d | hiliteColor=%@ | text='%@'>", 
			[super class], self, 
			self.frame.origin.x, self.frame.origin.y, self.frame.size.width, self.frame.size.height,
			fontName, fontSize, hiliteColor, text];
}

#pragma mark -
#pragma mark AVAudioPlayerDelegate

- (void)audioPlayerDidFinishPlaying:(AVAudioPlayer *)player successfully:(BOOL)flag {
	[self stop];
}

#pragma mark -
#pragma mark Deallocation

- (void)dealloc {
	[self stop];
	[text release];
	[fontName release];
	[hiliteColor release];
	[pageName release];
	[super dealloc];
}

@end
