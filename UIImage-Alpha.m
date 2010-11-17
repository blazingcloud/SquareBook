//
//  UIImage-Alpha.m
//  Glimmer
//
//  Created by Pablo Kang on 10/4/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import "UIImage-Alpha.h"

// http://rebelalfons.posterous.com/irregular-shaped-buttons-and-alpha-masks


CGContextRef CreateARGBBitmapContext(CGImageRef inImage) {
    CGContextRef    context = NULL;
    CGColorSpaceRef colorSpace = NULL; // tell we want  kCGImageAlphaOnly
    void *          bitmapData;
    int             bitmapByteCount;
    int             bitmapBytesPerRow;
    
    
    size_t pixelsWide = CGImageGetWidth(inImage);
    size_t pixelsHigh = CGImageGetHeight(inImage);
    bitmapBytesPerRow   = (pixelsWide * 1); // 8bpp
    bitmapByteCount     = (bitmapBytesPerRow * pixelsHigh);
    
    bitmapData = malloc(bitmapByteCount);
    if (bitmapData == NULL) {
		CGColorSpaceRelease(colorSpace);
		return nil;
	}
    context = CGBitmapContextCreate(bitmapData,
                                    pixelsWide,
                                    pixelsHigh,
                                    8,
                                    bitmapBytesPerRow,
                                    colorSpace,
									kCGImageAlphaOnly);
    if (context == NULL) {
		free (bitmapData);
		fprintf (stderr, "Context not created!");
	}
    CGColorSpaceRelease(colorSpace);
    
    return context;
}

@implementation UIImage(Alpha)

- (NSData *)ARGBData {
    CGContextRef cgctx = CreateARGBBitmapContext(self.CGImage);
    if (cgctx == NULL) 
        return nil;
    
    size_t w = CGImageGetWidth(self.CGImage);
    size_t h = CGImageGetHeight(self.CGImage);
    CGRect rect = {{0,0},{w,h}}; 
    CGContextDrawImage(cgctx, rect, self.CGImage); 
    
    unsigned char *data = CGBitmapContextGetData (cgctx);
    CGContextRelease(cgctx); 
    if (!data)
        return nil;
    
    size_t dataSize = 1 * w * h; // 8 bits
    
    return [[NSData alloc] initWithBytes:data length:dataSize];
}

- (BOOL)isPointTransparent:(CGPoint) point {
    NSData *rawData = [self ARGBData];  // Or cache this
    if (rawData == nil)
        return NO;
    
    // just 8 bits per alpha component
    size_t bpp = 1;
    size_t bpr = self.size.width * 1;
    
    NSUInteger index = (point.x * bpp) + (point.y * bpr);
    unsigned char *rawDataBytes = (unsigned char *)[rawData bytes];
    
    BOOL isTransparent = rawDataBytes[index] == 0;
	[rawData release];
	return isTransparent;
}

@end
