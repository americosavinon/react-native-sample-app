//
//  OnlineCareId.h
//
//  Created by Calvin Chestnut on 8/31/15.
//  Copyright (c) 2014 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

@interface OnlineCareId : NSObject <NSCopying>

@property (nonatomic, copy) NSString *encryptedId;
@property (nonatomic, copy) NSString *persistentId;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
