//
//  RestLink.h
//
//  Created by Calvin Chestnut on 5/29/15.
//  Copyright (c) 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

/**
 Simple class that stores an NSURL and the corresponding
 HTTP method that should be used.
 */
@interface RestLink : NSObject <NSCoding>

@property (nonatomic) NSURL *url;
@property (nonatomic) NSString *method;

+ (instancetype)restLinkWithDictionary:(NSDictionary *)dict;
+ (NSDictionary *)restLinksWithDictionary:(NSDictionary *)dict;

- (void)encodeWithCoder:(NSCoder *)aCoder;
- (instancetype)initWithCoder:(NSCoder *)aDecoder;

@end
