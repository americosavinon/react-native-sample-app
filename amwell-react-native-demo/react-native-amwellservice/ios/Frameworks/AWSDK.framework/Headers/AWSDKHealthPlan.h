//
//  AWSDKHealthPlan.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/2/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 A health plan protocol that a consumer can be subscribed to.

 @since 3.1.0
 */
@protocol AWSDKHealthPlan <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the name of the health plan

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSString representing the regular expression to validate subscriber IDs on health plans that support it.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *validationRegex;

/**
 NSString representing a configured validation message retrieved from the server.

 @discussion This is defined by the system configuration, and can be displayed to the user when a validation error is retrieved.

 @since 2.0.0
 */
@property (nonatomic, readonly, nullable) NSString *validationErrorMessage;

/**
 BOOL value that indicates whether the health plan is configured to suppress payment for the visit if the health plan eligibility check times out waiting for a response.

 @discussion This value can be used to display the appropriate message to the customer when the health plan system is temporarily unavailable.

 @since 4.2.0
 */
@property (nonatomic, readonly) BOOL suppressCharge;

/**
 BOOL value that indicates whether the health plan is feed controlled and therefore cannot have users manually set it as their subscribed health plan.

 @since 1.0.0
 */
@property (nonatomic, readonly) BOOL enrollmentEnabled;

/**
 BOOL value that indicates whether or not the suffix field is shown.

 @discussion This is defined by the system configuration and can be changed by the system admin.

 @since 1.0.0
 */
@property (nonatomic, readonly) BOOL usesSuffix;

/**
 BOOL value indicating if the health plan has a card image available.

 @discussion This should be checked before making a call to getCardImage: to determine if there is an image to retrieve.

 @since 3.2.0
 */
@property (nonatomic, readonly) BOOL hasCardImage;

/**
 NSURL pointing to the location of the card image.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSURL *imageUrl;

/**
 BOOL value that indicates whether to display or show the primary subscriber question for the health plan.

 @discussion This value can be used to hide/display the primary subscriber question for the health plan.

 @since 4.4.0
 */
@property (nonatomic, readonly) BOOL showPrimarySubscriberQuestion;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Retrieves an image provided by the health plan showing an annotated example of the health plan card.

 @param completion ImageCompletionBlock containing an UIImage for the example health plan card if available, otherwise an NSError explaining any failures.

 @since 2.1.0
 */
- (void)getCardImage:(nullable ImageCompletionBlock)completion;

/**
 Array of HealthPlan options for a SubscriptionForm

  @since 4.0.0
*/
@property (class, nonatomic, readonly, nullable) NSArray<id<AWSDKHealthPlan>> *healthPlans;

@end

/**
 A health plan that a consumer can be subscribed to.

 @since 1.0.0
 */
@interface AWSDKHealthPlan : AWSDKDataObject <AWSDKHealthPlan>
@end
