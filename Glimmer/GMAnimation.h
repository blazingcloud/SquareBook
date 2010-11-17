//
//  GMAnimation.h
//  Glimmer
//
//  Created by Pablo Kang on 10/13/10.
//  Copyright 2010 Blazing Cloud. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GMAnimation : NSObject {
}

@property (nonatomic, retain) NSURL *url;
@property (nonatomic, getter=isReverse) BOOL reverse;

- (id)initWithURL:(NSURL *)anURL reverse:(BOOL)isReverse;

@end


