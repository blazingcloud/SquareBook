//
//  UIImage-Alpha.h
//  Glimmer
//
//  Created by Pablo Kang on 10/4/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UIImage(Alpha) {
}

- (NSData *)ARGBData;
- (BOOL)isPointTransparent:(CGPoint)point;

@end
