//
//  AWSDKVisitSummary.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/18/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKBaseVisitSummary.h>
#import <AWSDK/AWSDKCompletionBlock.h>

// clang-format off
@protocol AWSDKVisitTopic, AWSDKVisitDiagnosis, AWSDKVisitProcedure, AWSDKPrescription, AWSDKFollowUpItem, AWSDKPharmacy, AWSDKAddress, AWSDKCost, AWSDKState, AWSDKConsumer, AWSDKFeedbackQuestion, AWSDKProviderType;
// clang-format on

/**
 The wrap-up summary provided at the end of the visit.

 @note This is provided by [AWSDKVisit fetchVisitSummary:].

 @since 1.0.0
 */
@protocol AWSDKVisitSummary <AWSDKBaseVisitSummary>

#pragma mark - Read-Only Configurations
/**
 @name Read-Only Configurations
 */

/**
 Boolean value indicating if the visit ratings have been marked as optional on the system configuration.

 @discussion If enabled, consumers on the web will be asked to rate their visit. The SDK does not enforce that ratings are actually collected, but provides access for consistent user experience.

 @since 1.0.0
 */
@property (readonly) BOOL endVisitRatingsOptional;

/**
 Boolean value indicating if the visit ratings should be shown set by the system configuration.

 @discussion The SDK does not enforce that provider ratings are shown, but provides access for a consistent user experience.

 @since 1.0.0
 */
@property (readonly) BOOL showProviderRatings;

/**
 AWSDKModality representing the mode of communication for the visit.

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKModality> modality;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Submits the [AWSDKFeedbackQuestion selectedOption] response to the telehealth platform.

 @param completion GenericCompletionBlock containing _TRUE_ if feedback question response was successfully submitted, otherwsie _FALSE_ and an NSError explaining the failures.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidValue   Invalid value for feedback question answer.

 @since 1.0.0
 */
- (void)submitFeedbackQuestion:(nullable GenericCompletionBlock)completion;

/**
 Sends the visit summary to one or more email addresses.

 @warning These email addresses will receive protected health information (PHI) about the consumer.

 @param emails     NSArray of NSString email addresses to send the visit summary to.
 @param completion GenericCompletionBlock containing _TRUE_ if the visit summary was successfully sent, otherwise _FALSE_ and an NSError describing any error cases.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidValue   Invalid value for emails, one of the specified emails is not valid.
 
 @note Valid dispositions for visit: AWSDKVisitDispositionProviderWrapUp, AWSDKVisitDispositionCompleted and AWSDKVisitDispositionExpired

 @since 2.0.0
 */
- (void)sendSummaryToEmailAddresses:(nonnull NSArray<NSString *> *)emails withCompletion:(nullable GenericCompletionBlock)completion;

/**

 Sends the visit summary to one or more email addresses, one or more fax numbers or both.

 @warning These email addresses and fax numbers will receive protected health information (PHI) about the consumer.

 @param emails     NSArray of NSString email addresses to send the visit summary to.
 @param faxNumbers     NSArray of NSString fax numbers to send the visit summary to.
 @param completion GenericCompletionBlock containing _TRUE_ if the visit summary was successfully sent, otherwise _FALSE_ and an NSError describing any error cases.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidValue   Invalid value for emails or fax numbers, one of the specified emails or fax numbers are not valid or no emails and fax numbers are supplied.


 @since 4.1.0
 */
- (void)sendSummaryToEmailAddresses:(nullable NSArray<NSString *> *)emails faxNumbers:(nullable NSArray<NSString *> *)faxNumbers withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Submits a rating for the provider and/or visit to the American Well telehealth platform.

 @param providerRating   Optional NSNumber rating for the provider as a number between 1 and 5, with 5 being the best.
 @param engagementRating Optional NSNumber rating for the visit experience as a number between 1 and 5, with 5 being the best.
 @param completion       GenericCompletionBlock containing _TRUE_ if the rating was sucessfully submitted, otherwise _FALSE_ and an NSError explaining if anything went wrong.

 @note Valid dispositions for visit: Any disposition
 
 @since 1.0.0
 */
- (void)rateProvider:(nullable NSNumber *)providerRating engagement:(nullable NSNumber *)engagementRating withCompletion:(nullable GenericCompletionBlock)completion;

@end
