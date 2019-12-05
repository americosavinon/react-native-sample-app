//
//  AWSDKRelationshipToSubscriber.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/11/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A relationship protocol to a primary subscriber of a health plan.

 @since 3.1.0
 */
@protocol AWSDKRelationshipToSubscriber <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the displayable string representing the relationship.

 @discussion Some examples would be 'Son', 'Daughter', 'Wife', or 'Husband'.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *title;

#pragma mark - Convenience methods
/**
 @name Convenience Methods
 */

/**
 Determines if the relationship indicates that the consumer is the primary subscriber.

 @return _TRUE_ if the relationship is the consumer is the primary subscriber, otherwise _FALSE_ if not primary.

 @since 1.0.0
 */
- (BOOL)isPrimary;

/**
 Determines if the relationship is valid for a minor or dependent such as 'Son' or 'Daughter'.

 @return _TRUE_ if the relationship is the consumer is a minor, otherwise _FALSE_ if not a minor.

 @since 2.1.0
 */
- (BOOL)isValidForMinor;

@end
