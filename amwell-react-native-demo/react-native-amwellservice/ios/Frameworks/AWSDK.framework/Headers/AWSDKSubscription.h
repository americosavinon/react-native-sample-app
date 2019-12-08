//
//  AWSDKSubscription.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/16/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

// clang-format off
@protocol AWSDKRelationshipToSubscriber, AWSDKHealthPlan;
// clang-format on

/**
 A user's subscription to an AWSDKHealthPlan.

 @since 3.1.0
 */
@protocol AWSDKSubscription <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the ID for the health insurance subscription, usually found on the insurance card.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) NSString *subscriberID;

/**
 NSString representing the suffix of the health insurance subscription, usually found on the insurance card.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) NSString *subscriberSuffix;

/**
 AWSDKRelationshipToSubscriber representing the relationship between the consumer and the primary subscriber, otherwise _nil_ if the consumer is the primary subscriber.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKRelationshipToSubscriber> relationshipToSubscriber;

/**
 AWSDKHealthPlan representing the health plan the consumer is subscribed to.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKHealthPlan> healthPlan;

/**
 NSDate representing the date of birth of the primary subscriber.

 @since 4.1.0
 */
@property (nonatomic, nullable, readonly) NSDate *primarySubscriberDateOfBirth;

/**
 NSString representing the primary subscriber's first name.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) NSString *primarySubscriberFirstName;

/**
 NSString representing the primary subscriber's last name.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) NSString *primarySubscriberLastName;
@end
