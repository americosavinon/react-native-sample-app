//
//  AWSDKSubscriptionForm.h
//  AWSDK
//
//  Created by Steven Uy on 8/09/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKForm.h>

// clang-format off
@protocol AWSDKRelationshipToSubscriber, AWSDKHealthPlan;
// clang-format on

/**
 Protocol used to enroll a new subscription.

 @since 3.1.0
 */
@protocol AWSDKSubscriptionForm <AWSDKForm>

#pragma mark - Required Read-Write Properties
/**
 @name Required Read-Write Properties
 */

/**
 NSString representing the ID for the health insurance subscription, usually found on the insurance card.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *subscriberID;

/**
 NSString representing the suffix of the health insurance subscription, usually found on the insurance card.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *subscriberSuffix;

/**
 AWSDKRelationshipToSubscriber representing the relationship between a consumer and the primary subscriber.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) id<AWSDKRelationshipToSubscriber> relationshipToSubscriber;

/**
 AWSDKHealthPlan representing the health plan a consumer is subscribed to.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) id<AWSDKHealthPlan> healthPlan;

#pragma mark - Optional Read-Write Properties
/**
 @name Optional Read-Write Properties
 */

/**
 NSDate representing the date of birth of the primary subscriber.

 @note When representing this field in your UI and to avoid off-by-one errors, be sure you are using the UTC time zone. This field is serialized from "milliseconds since epoch" at 00:00:00.

 @since 4.1.0
 */
@property (nonatomic, nullable, readwrite) NSDate *primarySubscriberDateOfBirth;

/**
 NSString representing the primary subscriber's first name.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *primarySubscriberFirstName;

/**
 NSString representing the primary subscriber's last name.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *primarySubscriberLastName;

/**
 BOOL when set to _TRUE_, the server will ignore eligibility checks and will save the health subscription.

 @discussion If updating the subscription information in a visit context, this will automatically be overriden to true. This is strictly for performance reasons to avoid duplicate eligibility checks
 where eligibilty was previously validated.

 @note The eligibility check allows the health plan to be validated and find out if the health plan will cover some or all of the visits cost. This should be kept as false unless a specific flow
 submits a subscription form more than once.

 @since 2.0.0
 */
@property (nonatomic, assign, readwrite) BOOL ignoreEligibility;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches a list of all valid AWSDKRelationshipToSubscriber relationships.

 @return NSArray of valid AWSDKRelationshipToSubscriber relationships.

 @since 2.0.0
 */
+ (nonnull NSArray<id<AWSDKRelationshipToSubscriber>> *)getRelationships;

@end
/**
 Class used to enroll a new subscription.

 @note As of 2.0.0, AWSDKNewSubscription was renamed to AWSDKSubscriptionForm to use AWSDKForm.

 @since 2.0.0
 */
@interface AWSDKSubscriptionForm : AWSDKForm <AWSDKSubscriptionForm>
#pragma mark - Appledoc
@property (nonatomic, nullable, readwrite) NSString *subscriberID;
@property (nonatomic, nullable, readwrite) NSString *subscriberSuffix;
@property (nonatomic, nullable, readwrite) id<AWSDKRelationshipToSubscriber> relationshipToSubscriber;
@property (nonatomic, nullable, readwrite) id<AWSDKHealthPlan> healthPlan;
@property (nonatomic, nullable, readwrite) NSDate *primarySubscriberDateOfBirth;
@property (nonatomic, nullable, readwrite) NSString *primarySubscriberFirstName;
@property (nonatomic, nullable, readwrite) NSString *primarySubscriberLastName;
@property (nonatomic, assign, readwrite) BOOL ignoreEligibility;
+ (nonnull NSArray<id<AWSDKRelationshipToSubscriber>> *)getRelationships;
#pragma mark -
@end
