//
//  AWSDKDataObjectPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/15/15.
//  Copyright (c) 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObject.h"

#import <AWSDK/NSDictionary+UnwrappedPrivate.h>

@class OnlineCareId, RestLink;

@interface AWSDKDataObject ()

/**
 Initialize a new instance of this class with the given dictionary.

 @param dict a dictionary representing the object

 @return the object
 */
- (instancetype)initWithDictionary:(NSDictionary *)dict;

/**
 Initialize a new instance

 @return the object
 */
- (instancetype)initPrivate;

/**
 The URL for accessing this entity. At a minimum, this instance can
 be retrieved from the server by making a GET request to this URL.
 */
@property (nonatomic) NSURL *entityURL;

@property (nonatomic) OnlineCareId *pk;

/**
 Dictionary where each key represents a linked entity and
 the corresponding entry is a RestLink (see above) that
 defines the interaction URL and HTTP method.
 */
@property (nonatomic) NSDictionary<NSString *, RestLink *> *links;

/**
 Validates that the link exists and throws an exception if it does not

 @note This should be used with all model objects, since sometimes the American Well Telehealth Platform returns sparse versions of objects that aren't intended to be fully functional

 @param key The key associated with the desired link
 @return RestLink object if the link is valid
 */
- (RestLink *)validLinkWithKey:(NSString *)key;

/**
 Add a new link to this object's collection.

 @param newLink  the link to add
 @param key      the name of the link
 */
- (void)addLink:(RestLink *)newLink forKey:(NSString *)key;

/**
 Populate this object with the given JSON.

 @param json the json received from the server
 */
- (void)populate:(NSDictionary *)json;

/**
 Validates the object, overriden in subclasses if used

 @param object AWSDKDataObject to validate

 @return NSNumber containing the error code, or an NSMutableDictionary if nested parameters. Nil if no error
 */
+ (id)validate:(AWSDKDataObject *)object;

/**
 Convience to call validate on itself and return true if valid, false otherwise

 @return True if valid, false otherwise
 */
- (BOOL)isValid;

@end
