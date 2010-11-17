//
//  GMAnimation.m
//  Glimmer
//
//  Created by Pablo Kang on 10/13/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import "GMAnimation.h"

@implementation GMAnimation

@synthesize url, reverse;

- (id)initWithURL:(NSURL *)anURL reverse:(BOOL)isReverse {
	if ((self = [self init])) {
		self.url = anURL;
		self.reverse = isReverse;
	}
	return self;
}

- (NSString *)description {
	NSString *file = [[url path] lastPathComponent];
	NSString *reverseStr = reverse ? @"YES" : @"NO";
	return [NSString stringWithFormat:@"<%@: 0x%x | url=%@ | reverse=%@>", [super class], self, file, reverseStr];
}

- (void)dealloc {
	[url release];
	[super dealloc];
}

@end
