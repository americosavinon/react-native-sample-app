//
//  NSDictionary+UnwrappedPrivate.h
//
//  Created by Calvin Chestnut on 8/31/15.
//  Copyright (c) 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (Unwrapped)

/**
 Returns the dictionary in the dictionary for the given key.
 If this dictionary doesn't contain a value for the key
 or that value isn't an NSDictionary, this method returns self.

 @param key the key to check for

 @return the NSDictionary
 */
- (NSDictionary *)unwrap:(NSString *)key;

/**
 Helper method to quickly determine if there is usable info in the NSDictionary for the given key

 @discusssion Sometimes when the American Well Telehealth Platform sends back nil in the JSON, our parser will interpret that as an NSNull object and add it to the dictionary. Obviously NSNull is not
 a valid value, so this method exists mostly so we don't have to write if(dict[@"key"] && dict[@"key"] != [NSNull null]) over and over again

 @param key Key to look in Dictionary for
 @return Bool indicating if there is a non null value in the dictionary for that key
 */
- (BOOL)hasValidValue:(id)key;

@end
