//
//  AWSDKVisitReportSummary.h
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

#import <AWSDK/AWSDKBaseVisitSummary.h>

// clang-format off
@protocol AWSDKAddress, AWSDKVisitTopic, AWSDKChatReport, AWSDKProvider;
// clang-format on

/**
 Past visit report containing details about the visit.

 @since 2.1.0
 */
@protocol AWSDKVisitReportSummary <AWSDKBaseVisitSummary>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString displayable title of the visit containing the provider and provider's specialty.

 @discussion An example would be "Visit with Mary Jones, Family Physician".

 @since 2.1.0
 */
@property (nonatomic, nonnull, readonly) NSString *title;

/**
 NSArray of NSStrings representing the titles of disclaimers that were accepted by the consumer.

 @since 2.1.0
 */
@property (nonatomic, nonnull, readonly) NSArray<NSString *> *acceptedDisclaimers;

/**
 NSString name of the provider transferred from, _nil_ if no transfer occurred.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSString *transferredFromProviderName;

/**
 NSString provider specialty of the provider transferred from, _nil_ if none provided or no transfer occurred.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSString *transferredFromProviderSpecialty;

/**
 NSString formatted transfer note set by the provider, _nil_ if none provided or no transfer occurred.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSString *transferNote;

/**
 Consumer's billing AWSDKAddress used for this visit, _nil_ if none on file.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKAddress> consumerBillingAddress;

/**
 NSString credit card type charged for this visit, _nil_ if none on file.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSString *paymentType;

/**
 CGFloat payment amount charged.

 @since 2.1.0
 */
@property (nonatomic, readonly) CGFloat paymentAmount;

/**
 NSArray of AWSDKVisitTopic items set by the consumer, _nil_ if no topics provided.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSArray<id<AWSDKVisitTopic>> *consumerSummaryTopics;

/**
 NSArray of AWSDKFollowUpItem items set after the visit by the provider, _nil_ if no items.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSArray<id<AWSDKFollowUpItem>> *postVisitFollowUpItems;

/**
 AWSDKChatReport containing information about the chat and the AWSDKChatItem items, _nil_ if no chat occurred.

 @discussion Includes pre-visit, in-visit, and post-visit chat items.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKChatReport> chatReport;

/**
 NSUInteger visit rating set by consumer on a scale from 1 (worst) to 5 (best), otherwise 0 if not set.

 @since 2.1.0
 */
@property (nonatomic, readonly) NSUInteger visitRating;

/**
 NSUInteger provider rating set by the consumer on a scale from 1 (worst) to 5 (best), otherwise 0 if not set.

 @since 2.1.0
 */
@property (nonatomic, readonly) NSUInteger providerRating;

/**
 Provider associated with the generated report
 
 @since 5.2.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKProvider> assignedProvider;

/**
 Practice associated with the generated report
 
 @since 5.2.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKPractice> practice;


#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the visit report summary as a server-generated PDF.

 @param completion DataResultCompletionBlock containing NSData representing the PDF, or an NSError reporting any issues.

 @since 2.1.0
 */
- (void)fetchReportAsData:(nullable DataResultCompletionBlock)completion;

@end
