//
//  AWSDKBaseVisitSummary.h
//  AWSDK
//
//  Created by Steven Uy on 9/9/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>
#import <AWSDK/AWSDKVisitDisposition.h>

// clang-format off
@protocol AWSDKVisitTopic, AWSDKVisitDiagnosis, AWSDKVisitProcedure, AWSDKPrescription, AWSDKFollowUpItem, AWSDKPharmacy, AWSDKAddress, AWSDKCost, AWSDKState, AWSDKConsumer, AWSDKFeedbackQuestion, AWSDKProviderType, AWSDKSchedule, AWSDKModality;
// clang-format on

/**
 Parent visit summary class containing properties shared between AWSDKVisitSummary and AWSDKVisitReportSummary.

 @since 2.1.0
 */
@protocol AWSDKBaseVisitSummary <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
NSString for HIPAA Notice Text.

@since 3.1.0
*/
@property (nonatomic, readonly, nullable) NSString *hipaaNoticeText;

/**
NSString for additional HIPAA Notice Text.

@since 3.1.0
*/
@property (nonatomic, readonly, nullable) NSString *additionalHipaaNoticeText;

/**
 AWSDKPharmacy selected for the visit, _nil_ if none selected.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKPharmacy> pharmacy;

/**
 AWSDKAddress for shipping selected for the visit, _nil_ if none selected.

 @discussion shippingAddress is collected specifically for fulfilling prescriptions via a mail-order pharmacy, see [AWSDKPharmacy isMailOrder].

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKAddress> shippingAddress;

/**
 NSString first name of the provider for the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSString *providerFirstName;

/**
  NSString middle initial of the provider for the visit, _nil_ if none provided.

  @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSString *providerMiddleInitial;

/**
  NSString last name of the provider for the visit.

  @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSString *providerLastName;

/**
 NSString professional title of the provider for the visit such as "MD", _nil_ if none provided.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSString *providerProfessionalTitle;

/**
  AWSDKProviderType specialty of the provider for the visit.

  @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKProviderType> providerSpecialty;

/**
 NSString practice name for the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSString *providerPractice;

/**
 AWSDKCost billed for the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKCost> cost;

/**
 NSArray of AWSDKVisitTopic topics that the consumer selected before the visit, _nil_ if none selected.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKVisitTopic>> *selectedTopics;

/**
 AWSDKState location of the consumer at the time of the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKState> consumerLocation;

/**
 AWSDKSchedule containing start time and durations of the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKSchedule> schedule;

/**
 NSArray of NSString triage questions defined by the practice.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *triageQuestions;

/**
 NSArray of NSString triage answers to the triage questions.

 @note triageQuestions indexes are aligned with triageAnswers to associate question with answers.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *triageAnswers;

/**
 NSArray of email addresses as NSString that received invitations to join the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *visitInviteEmails;

/**
 AWSDKConsumer representing the person for whom the visit is for. This can be either the account owner or a dependent.


  @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKConsumer> consumer;

/**
 AWSDKConsumer parent for the visit if the consumer is a dependent

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKConsumer> consumerProxy;

#pragma mark - Provider Read-Only Entries
/**
 @name Provider Read-Only Entries
 */

/**
 AWSDKModality representing the mode of communication for the visit.

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKModality> modality;

/**
 NSString formatted provider notes about the visit, _nil_ if none added.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSString *providerNotes;

/**
 NSArray of AWSDKVisitDiagnosis items the provider added after or during the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKVisitDiagnosis>> *diagnoses;

/**
 NSArray of AWSDKVisitProcedure items added after or during the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKVisitProcedure>> *procedures;

/**
 NSArray of AWSDKPrescription items added after or during the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKPrescription>> *prescriptions;

/**
 NSArray of AWSDKFollowUpItem items defined by the Provider.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKFollowUpItem>> *followUpItems;

#pragma mark - Feedback Question
/**
 @name Feedback Question
 */

/**
 AWSDKFeedbackQuestion containing a question and a selectable response available to the consumer, _nil_ if no question is to be shown.

 @discussion When in wrap up for the visit, submit the feedbackQuestion response by setting the [AWSDKFeedbackQuestion selectedOption] and then calling [AWSDKVisitSummary submitFeedbackQuestion:].

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKFeedbackQuestion> feedbackQuestion;

/**
 AWSDKVisitDisposition describing the state of the AWSDKVisit

 @since 4.2.0
 */
@property (nonatomic, readonly) AWSDKVisitDisposition disposition;

#pragma mark - Convenience Methods
/**
 @name Convenience Methods
 */

/**
 Get the Provider's full name.

 @return NSString with formatted full name.

 @since 2.1.0
 */
- (nonnull NSString *)providerFullName;

/**
 Fetches the AWSDKProvider for the visit.

 @param completion ProviderResultCompletionBlock containing the AWSDKProvider for the visit, otherwise NSError for any failures.

 @since 2.1.0
 */
- (void)fetchProviderWithCompletion:(nonnull ProviderResultCompletionBlock)completion;

@end
