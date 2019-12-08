//
//  AWSDKCondition.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/15/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A medical condition protocol that may be current for a consumer.

 @since 3.1.0
 */
@protocol AWSDKCondition <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString displayable name of the condition.

 @since 1.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *displayName;

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 Boolean value indicates if the condition is reported as current by the consumer.

 @since 1.0.0
 */
@property (nonatomic, readwrite) BOOL isCurrent;
@end
