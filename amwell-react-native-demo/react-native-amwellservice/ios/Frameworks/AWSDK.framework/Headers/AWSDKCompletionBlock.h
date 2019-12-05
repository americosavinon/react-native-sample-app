//
//  AWSDKCompletionBlock.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/14/15.
//  Copyright (c) 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// clang-format off
@protocol AWSDKAddress;
@protocol AWSDKAllergy;
@protocol AWSDKAppointment;
@protocol AWSDKAppointmentReadiness;
@protocol AWSDKAvailableProviderSearchResults;
@protocol AWSDKChatReport;
@protocol AWSDKCondition;
@protocol AWSDKConsumer;
@protocol AWSDKConsumerVitals;
@protocol AWSDKContact;
@protocol AWSDKCost;
@protocol AWSDKCreditCardType;
@protocol AWSDKDependentAccessRequest;
@protocol AWSDKDeviceIntegration;
@protocol AWSDKHealthDocument;
@protocol AWSDKHealthPlan;
@protocol AWSDKHealthSummary;
@protocol AWSDKInboxMessageDetails;
@protocol AWSDKMedication;
@protocol AWSDKMessage;
@protocol AWSDKMessageDraft;
@protocol AWSDKMessageFolder;
@protocol AWSDKMessageTopic;
@protocol AWSDKOnDemandSpecialty;
@protocol AWSDKPaymentMethod;
@protocol AWSDKPharmacy;
@protocol AWSDKPlatformType;
@protocol AWSDKPractice;
@protocol AWSDKPracticeSearchResult;
@protocol AWSDKProvider;
@protocol AWSDKProviderSearchResult;
@protocol AWSDKProviderType;
@protocol AWSDKSchedule;
@protocol AWSDKSpeedPass;
@protocol AWSDKState;
@protocol AWSDKSubscription;
@protocol AWSDKTrackerEntry;
@protocol AWSDKTrackerTemplate;
@protocol AWSDKVisit;
@protocol AWSDKVisitContext;
@protocol AWSDKVisitReport;
@protocol AWSDKVisitReportSummary;
@protocol AWSDKVisitSummary;

@class AWSDKConsumerNotifications;
@class AWCoreVisitConsoleController;
// clang-format on
#pragma mark - Completion Blocks
/**
 @name Completion Blocks
 */

/**
 Used for requests where a single AWSDKConsumer result is expected.

 @discussion Will contain the expected AWSDKConsumer result, otherwise an optional NSError if there are any problems with the request.

 @param consumer  The expected AWSDKConsumer object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ConsumerResultCompletionBlock)(_Nullable id<AWSDKConsumer> consumer, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKPractice result is expected.

 @discussion Will contain the expected AWSDKPractice result, otherwise an optional NSError if there are any problems with the request.

 @param practice  The expected AWSDKPractice object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^PracticeCompletionBlock)(_Nullable id<AWSDKPractice> practice, NSError *_Nullable error);

/**
 @discussion Will contain an array of NSDates.

 @param dates       An array of dates
 @param error       NSError explaining why the request failed.

 @since 4.1.0
 */
typedef void (^DatesArrayCompletionBlock)(NSArray<NSDate *> *_Nullable dates, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKVisit or AWSDKVisitContext result is expected.

 @discussion Will contain the expected AWSDKVisit or AWSDKVisitContext result, otherwise an optional NSError if there are any problems with the request.

 @param transferResult  The expected AWSDKVisit or AWSDKVisitContext object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^TransferResultCompletionBlock)(_Nullable id transferResult, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKChatReport result is expected.

 @discussion Will contain the expected AWSDKChatReport result, otherwise an optional NSError if there are any problems with the request.

 @param chatReport  The expected AWSDKChatReport object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ChatReportCompletionBlock)(_Nullable id<AWSDKChatReport> chatReport, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKVisitSummary result is expected.

 @discussion Will contain the expected AWSDKVisitSummary result, otherwise an optional NSError if there are any problems with the request.

 @param summary  The expected AWSDKVisitSummary object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^VisitSummaryCompletionBlock)(_Nullable id<AWSDKVisitSummary> summary, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKInboxMessageDetails result is expected.

 @discussion Will contain the expected AWSDKInboxMessageDetails result, otherwise an optional NSError if there are any problems with the request.

 @param messageDetails  The expected AWSDKInboxMessageDetails object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^InboxMessageDetailsCompletionBlock)(_Nullable id<AWSDKInboxMessageDetails> messageDetails, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKInboxMessageDetails or AWSDKSentMessageDetails result is expected.

 @discussion Will contain the expected AWSDKInboxMessageDetails or AWSDKSentMessageDetails result, otherwise an optional NSError if there are any problems with the request.

 @param messageDetails  The expected AWSDKInboxMessageDetails or AWSDKSentMessageDetails object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^MessageDetailsCompletionBlock)(_Nullable id<AWSDKMessage> messageDetails, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKAppointmentReadiness result is expected.

 @discussion Will contain the expected AWSDKAppointmentReadiness result, otherwise an optional NSError if there are any problems with the request.

 @param appointmentReadiness  The expected AWSDKAppointmentReadiness object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^AppointmentReadinessCompletionBlock)(_Nullable id<AWSDKAppointmentReadiness> appointmentReadiness, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKHealthSummary result is expected.

 @discussion Will contain the expected AWSDKHealthSummary result, otherwise an optional NSError if there are any problems with the request.

 @param summary  The expected AWSDKHealthSummary object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^HealthSummaryCompletionBlock)(_Nullable id<AWSDKHealthSummary> summary, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKVisitReportSummary result is expected.

 @discussion Will contain the expected AWSDKVisitReportSummary result, otherwise an optional NSError if there are any problems with the request.

 @param summary  The expected AWSDKVisitReportSummary object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^VisitReportSummaryCompletionBlock)(_Nullable id<AWSDKVisitReportSummary> summary, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKAddress result is expected.

 @discussion Will contain the expected AWSDKAddress result, otherwise an optional NSError if there are any problems with the request.

 @param address  The expected AWSDKAddress object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^AddressCompletionBlock)(_Nullable id<AWSDKAddress> address, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKConsumerVitals result is expected.

 @discussion Will contain the expected AWSDKConsumerVitals result, otherwise an optional NSError if there are any problems with the request.

 @param vitals  The expected AWSDKConsumerVitals object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^VitalsCompletionBlock)(_Nullable id<AWSDKConsumerVitals> vitals, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKConsumer or AWSDKPartialConsumer result is expected.

 @discussion Will contain the expected AWSDKConsumer or AWSDKPartialConsumer result, otherwise an optional NSError if there are any problems with the request.

 @param consumer  The expected AWSDKConsumer or AWSDKPartialConsumer object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^AuthenticationResultCompletionBlock)(_Nullable id consumer, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKMessageFolder result is expected.

 @discussion Will contain the expected AWSDKMessageFolder result, otherwise an optional NSError if there are any problems with the request.

 @param folder  The expected AWSDKMessageFolder object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^MessageFolderCompletionBlock)(_Nullable id<AWSDKMessageFolder> folder, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKProvider result is expected.

 @discussion Will contain the expected AWSDKProvider result, otherwise an optional NSError if there are any problems with the request.

 @param provider  The expected AWSDKProvider object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ProviderResultCompletionBlock)(_Nullable id<AWSDKProvider> provider, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKAvailableProviderSearchResults result is expected.

 @discussion Will contain the expected AWSDKAvailableProviderSearchResults result, otherwise an optional NSError if there are any problems with the request.

 @param results  The expected AWSDKAvailableProviderSearchResults object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^AvailableProviderSearchResultsCompletionBlock)(_Nullable id<AWSDKAvailableProviderSearchResults> results, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKMessageDraft result is expected.

 @discussion Will contain the expected AWSDKMessageDraft result, otherwise an optional NSError if there are any problems with the request.

 @param draft  The expected AWSDKMessageDraft object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^MessageDraftCompletionBlock)(_Nullable id<AWSDKMessageDraft> draft, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKVisit result is expected.

 @discussion Will contain the expected AWSDKVisit result, otherwise an optional NSError if there are any problems with the request.

 @param visit  The expected AWSDKVisit object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^VisitCompletionBlock)(_Nullable id<AWSDKVisit> visit, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKProvider results are expected.

 @discussion Will contain the expected array of AWSDKProvider results, otherwise an optional NSError if there are any problems with the request.

 @param providers  The expected array of AWSDKProvider objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ProviderResultsCompletionBlock)(NSArray<id<AWSDKProvider>> *_Nullable providers, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKVisitReport results are expected.

 @discussion Will contain the expected array of AWSDKVisitReport results, otherwise an optional NSError if there are any problems with the request.

 @param visitReports  The expected array of AWSDKVisitReport objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^VisitReportsCompletionBlock)(NSArray<id<AWSDKVisitReport>> *_Nullable visitReports, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKCreditCardType results are expected.

 @discussion Will contain the expected array of AWSDKCreditCardType results, otherwise an optional NSError if there are any problems with the request.

 @param types  The expected array of AWSDKCreditCardType objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^CreditCardTypesCompletionBlock)(NSArray<id<AWSDKCreditCardType>> *_Nullable types, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKContact results are expected.

 @discussion Will contain the expected array of AWSDKContact results, otherwise an optional NSError if there are any problems with the request.

 @param contacts  The expected array of AWSDKContact objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ContactsCompletionBlock)(NSArray<id<AWSDKContact>> *_Nullable contacts, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKSubscription result is expected.

 @discussion Will contain the expected AWSDKSubscription result, otherwise an optional NSError if there are any problems with the request.

 @param subscription  The expected AWSDKSubscription object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^SubscriptionCompletionBlock)(_Nullable id<AWSDKSubscription> subscription, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKPaymentMethod result is expected.

 @discussion Will contain the expected AWSDKPaymentMethod result, otherwise an optional NSError if there are any problems with the request.

 @param paymentMethod  The expected AWSDKPaymentMethod object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^PaymentMethodCompletionBlock)(_Nullable id<AWSDKPaymentMethod> paymentMethod, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKCost result is expected.

 @discussion Will contain the expected AWSDKCost result, otherwise an optional NSError if there are any problems with the request.

 @param cost  The expected AWSDKCost object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^CostResultCompletionBlock)(_Nullable id<AWSDKCost> cost, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKAppointment result is expected.

 @discussion Will contain the expected AWSDKAppointment result, otherwise an optional NSError if there are any problems with the request.

 @param appointment  The expected AWSDKAppointment object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^AppointmentCompletionBlock)(_Nullable id<AWSDKAppointment> appointment, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKAllergy results are expected.

 @discussion Will contain the expected array of AWSDKAllergy results, otherwise an optional NSError if there are any problems with the request.

 @param allergies  The expected array of AWSDKAllergy objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^AllergiesCompletionBlock)(NSArray<id<AWSDKAllergy>> *_Nullable allergies, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKCondition results are expected.

 @discussion Will contain the expected array of AWSDKCondition results, otherwise an optional NSError if there are any problems with the request.

 @param conditions  The expected array of AWSDKCondition objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ConditionsCompletionBlock)(NSArray<id<AWSDKCondition>> *_Nullable conditions, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKHealthDocument results are expected.

 @discussion Will contain the expected array of AWSDKHealthDocument results, otherwise an optional NSError if there are any problems with the request.

 @param documents  The expected array of AWSDKHealthDocument objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^HealthDocumentsCompletionBlock)(NSArray<id<AWSDKHealthDocument>> *_Nullable documents, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKHealthDocument result is expected.

 @discussion Will contain the expected AWSDKHealthDocument result, otherwise an optional NSError if there are any problems with the request.

 @param document  The expected AWSDKHealthDocument object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^HealthDocumentCompletionBlock)(_Nullable id<AWSDKHealthDocument> document, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKSchedule results are expected.

 @discussion Will contain the expected array of AWSDKSchedule results, otherwise an optional NSError if there are any problems with the request.

 @param schedules  The expected array of AWSDKSchedule objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ScheduleResultsCompletionBlock)(NSArray<id<AWSDKSchedule>> *_Nullable schedules, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKAppointment results are expected.

 @discussion Will contain the expected array of AWSDKAppointment results, otherwise an optional NSError if there are any problems with the request.

 @param appointments  The expected array of AWSDKAppointment objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^AppointmentsCompletionBlock)(NSArray<id<AWSDKAppointment>> *_Nullable appointments, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKVisitContext result is expected.

 @discussion Will contain the expected AWSDKVisitContext result, otherwise an optional NSError if there are any problems with the request.

 @param visitContext  The expected AWSDKVisitContext object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^VisitContextCompletionBlock)(_Nullable id<AWSDKVisitContext> visitContext, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKProviderType results are expected.

 @discussion Will contain the expected array of AWSDKProviderType results, otherwise an optional NSError if there are any problems with the request.

 @param providerTypes  The expected array of AWSDKProviderType objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ProviderTypeResultsCompletionBlock)(NSArray<id<AWSDKProviderType>> *_Nullable providerTypes, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKProviderSearchResult results are expected.

 @discussion Will contain the expected array of AWSDKProviderSearchResult results, otherwise an optional NSError if there are any problems with the request.

 @param providerSearchResults  The expected array of AWSDKProviderSearchResult objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ProviderSearchResultsCompletionBlock)(NSArray<id<AWSDKProviderSearchResult>> *_Nullable providerSearchResults, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKPractice results are expected.

 @discussion Will contain the expected array of AWSDKPractice results, otherwise an optional NSError if there are any problems with the request.

 @param practices  The expected array of AWSDKPractice objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^PracticeResultsCompletionBlock)(NSArray<id<AWSDKPractice>> *_Nullable practices, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKPracticeSearchResult results are expected.

 @discussion Will contain the expected array of AWSDKPracticeSearchResult results, otherwise an optional NSError if there are any problems with the request.

 @param practiceSearchResults  The expected array of AWSDKPracticeSearchResult objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^PracticeSearchResultsCompletionBlock)(NSArray<id<AWSDKPracticeSearchResult>> *_Nullable practiceSearchResults, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKState results are expected.

 @discussion Will contain the expected array of AWSDKState results, otherwise an optional NSError if there are any problems with the request.

 @param stateResults  The expected array of AWSDKState objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^StatesCompletionBlock)(NSArray<id<AWSDKState>> *_Nullable stateResults, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKMessageTopic results are expected.

 @discussion Will contain the expected array of AWSDKMessageTopic results, otherwise an optional NSError if there are any problems with the request.

 @param messageTopics  The expected array of AWSDKMessageTopic objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^MessageTopicsCompletionBlock)(NSArray<id<AWSDKMessageTopic>> *_Nullable messageTopics, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKHealthPlan results are expected.

 @discussion Will contain the expected array of AWSDKHealthPlan results, otherwise an optional NSError if there are any problems with the request.

 @param healthPlans  The expected array of AWSDKHealthPlan objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^HealthPlansCompletionBlock)(NSArray<id<AWSDKHealthPlan>> *_Nullable healthPlans, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKHealthPlan result is expected.

 @discussion Will contain the expected AWSDKHealthPlan result, otherwise an optional NSError if there are any problems with the request.

 @param healthPlan  The expected AWSDKHealthPlan object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^HealthPlanCompletionBlock)(_Nullable id<AWSDKHealthPlan> healthPlan, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKOnDemandSpecialty results are expected.

 @discussion Will contain the expected array of AWSDKOnDemandSpecialty results, otherwise an optional NSError if there are any problems with the request.

 @param onDemandSpecialties  The expected array of AWSDKOnDemandSpecialty objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^OnDemandSpecialtyResultsCompletionBlock)(NSArray<id<AWSDKOnDemandSpecialty>> *_Nullable onDemandSpecialties, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKPharmacy results are expected.

 @discussion Will contain the expected array of AWSDKPharmacy results, otherwise an optional NSError if there are any problems with the request.

 @param pharmacies  The expected array of AWSDKPharmacy objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^PharmaciesCompletionBlock)(NSArray<id<AWSDKPharmacy>> *_Nullable pharmacies, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKPharmacy result is expected.

 @discussion Will contain the expected AWSDKPharmacy result, otherwise an optional NSError if there are any problems with the request.

 @param pharmacy  The expected AWSDKPharmacy object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^PharmacyCompletionBlock)(_Nullable id<AWSDKPharmacy> pharmacy, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKMedication results are expected.

 @discussion Will contain the expected array of AWSDKMedication results, otherwise an optional NSError if there are any problems with the request.

 @param medications  The expected array of AWSDKMedication objects.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^MedicationsCompletionBlock)(NSArray<id<AWSDKMedication>> *_Nullable medications, NSError *_Nullable error);

/**
 Used for requests where the AWCoreVisitConsoleController result is expected.

 @discussion Will contain the expected AWCoreVisitConsoleController result, otherwise an optional NSError if there are any problems with the request.

 @param console  The expected AWCoreVisitConsoleController object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^VisitConsoleCompletionBlock)(AWCoreVisitConsoleController *_Nullable console, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKConsumer results are expected.

 @discussion Will contain the expected array of AWSDKConsumer results, otherwise an optional NSError if there are any problems with the request.

 @param consumers  The expected array of AWSDKConsumer objects.
 @param error   NSError explaining why the request failed.

 @since 4.1.0
 */
typedef void (^ConsumerResultsCompletionBlock)(NSArray<id<AWSDKConsumer>> *_Nullable consumers, NSError *_Nullable error);

/**
 Used for requests where the AWSDKDependentAccessRequest result is expected.

 @discussion Will contain the expected AWSDKDependentAccessRequest result, otherwise an optional NSError if there are any problems with the request.

 @param notification  The expected AWSDKDependentAccessRequest object.
 @param error   NSError explaining why the request failed.

 @since 4.1.0
 */
typedef void (^DependentAccessRequestCompletionBlock)(id<AWSDKDependentAccessRequest> _Nullable notification, NSError *_Nullable error);

/**
 Used for requests where the AWSDKSpeedPass result is expected.

 @discussion Will contain the expected AWSDKSpeedPass result, otherwise an optional NSError if there are any problems with the request.

 @param speedPass  The expected AWSDKSpeedPass object.
 @param error   NSError explaining why the request failed.

 @since 4.1.0
 */
typedef void (^SpeedPassCompletionBlock)(id<AWSDKSpeedPass> _Nullable speedPass, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKTrackerTemplate results are expected.

 @discussion Will contain the expected array of AWSDKTrackerTemplate results, otherwise an optional NSError if there are any problems with the request.

 @param trackerTemplates  The expected array of AWSDKTrackerTemplates objects.
 @param error   NSError explaining why the request failed.

 @since 4.3.0
 */
typedef void (^TrackerTemplatesCompletionBlock)(NSArray<id<AWSDKTrackerTemplate>> *_Nullable trackerTemplates, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKTrackerEntry results are expected.

 @discussion Will contain the expected array of AWSDKTrackerEntry results, otherwise an optional NSError if there are any problems with the request.

 @param trackerEntries  The expected array of AWSDKTrackerEntry objects.
 @param error   NSError explaining why the request failed.

 @since 4.3.0
 */
typedef void (^TrackerEntriesCompletionBlock)(NSArray<id<AWSDKTrackerEntry>> *_Nullable trackerEntries, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKPlatformType results are expected.

 @discussion Will contain the expected array of AWSDKPlatformType results, otherwise an optional NSError if there are any problems with the request.

 @param platformTypes  The expected array of AWSDKPlatformType objects.
 @param error   NSError explaining why the request failed.

 @since 4.3.0
 */
typedef void (^PlatformTypesCompletionBlock)(NSArray<id<AWSDKPlatformType>> *_Nullable platformTypes, NSError *_Nullable error);

#pragma mark - Native Types

/**
 Used for requests where no specific return is expected.

 @discussion Will contain _TRUE_ if the method was successful, otherwise _FALSE_ and an optional NSError if there are any problems with the request.

 @param success _TRUE_ if the method was successful, otherwise _FALSE_ if failed.
 @param error   NSError explaining why the request failed.

 @since 1.0.0
 */
typedef void (^GenericCompletionBlock)(BOOL success, NSError *_Nullable error);

/**
 Used for requests where a single NSString result is expected.

 @discussion Will contain the expected NSString result, otherwise an optional NSError if there are any problems with the request.

 @param result  The expected NSString object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^StringResultCompletionBlock)(NSString *_Nullable result, NSError *_Nullable error);

/**
 Used for requests where a single NSTimeInterval result is expected.

 @discussion Will contain the expected NSTimeInterval timeInterval, otherwise an optional NSError if there are any problems with the request.

 @param timeInterval  The expected NSTimeInterval.
 @param error   NSError explaining why the request failed.

 @since 5.1.0
 */
typedef void (^TimeIntervalCompletionBlock)(NSTimeInterval timeInterval, NSError *_Nullable error);

/**
 Used for requests where a single NSData result is expected.

 @discussion Will contain the expected NSData result, otherwise an optional NSError if there are any problems with the request.

 @param data  The expected NSData object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^DataResultCompletionBlock)(NSData *_Nullable data, NSError *_Nullable error);

/**
 Used for requests where a single UIImage result is expected.

 @discussion Will contain the expected UIImage result, otherwise an optional NSError if there are any problems with the request.

 @param image  The expected UIImage object.
 @param error   NSError explaining why the request failed.

 @since 4.0.0
 */
typedef void (^ImageCompletionBlock)(UIImage *_Nullable image, NSError *_Nullable error);

/**
 Used for requests where all we care about is success or failure.

 @discussion Will contain _TRUE_ if the method was successful, otherwise _FALSE_ .

 @param success _TRUE_ if the method was successful, otherwise _FALSE_ if failed.

 @since 3.1.0
 */
typedef void (^SuccessCompletionBlock)(BOOL success);

/**
 Used to contain generic completion blocks without any passed state

 @since 3.1.0
 */
typedef void (^CompletionBlock)(void);

/**
 Used for requests where a AWSDKConsumerNotifications object is expected

 @param notifications The expected AWSDKConsumerNotifications object
 @param error NSError explaining why the request failed

 @since 4.2.0
 */
typedef void (^ActionableNotificationBlock)(AWSDKConsumerNotifications *_Nullable notifications, NSError *_Nullable error);

/**
 Used for requests where an array of AWSDKDeviceIntegration results are expected.

 @discussion Will contain the expected array of AWSDKDeviceIntegration results, otherwise an optional NSError if there are any problems with the request.

 @param deviceIntegrations  The expected array of AWSDKDeviceIntegration objects.
 @param error   NSError explaining why the request failed.

 @since 4.3.0
 */
typedef void (^DeviceIntegrationsCompletionBlock)(NSArray<id<AWSDKDeviceIntegration>> *_Nullable deviceIntegrations, NSError *_Nullable error);

/**
 Used for requests where a single AWSDKDeviceIntegration result is expected.

 @discussion Will contain the expected AWSDKDeviceIntegration result, otherwise an optional NSError if there are any problems with the request.

 @param deviceIntegration  The expected AWSDKDeviceIntegration object.
 @param error   NSError explaining why the request failed.

 @since 4.3.0
 */
typedef void (^DeviceIntegrationCompletionBlock)(id<AWSDKDeviceIntegration> _Nullable deviceIntegration, NSError *_Nullable error);
