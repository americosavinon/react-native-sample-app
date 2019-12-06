//
//  AWSDKVisitContext.h
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
@protocol AWSDKConsumer, AWSDKProvider, AWSDKFeedbackQuestion, AWSDKPharmacy, AWSDKVisitTopic, AWSDKLegalText, AWSDKOnDemandSpecialty, AWSDKAppointment, AWSDKTriageQuestion, AWSDKLegalText, AWSDKModality;
// clang-format on

/**
 The context protocol; of an American Well telehealth visit.

 @since 3.1.0
 */
@protocol AWSDKVisitContext <AWSDKDataObject>

#pragma mark - Constructors
/**
 @name Constructors
 */

/**
 Creates a new AWSDKVisitContext instance given an AWSDKConsumer consumer and AWSDKProvider provider for a consumer visit.

 @note This is to be used for a consumer visit. For a dependent visit use createVisitContextForConsumer:dependent:provider:completion .

 @param consumer   AWSDKConsumer for the visit.
 @param provider   AWSDKProvider for the visit.
 @param completion VisitContextCompletionBlock containing the AWSDKVisitContext isntance, otherwise an NSError describing what went wrong.

 @since 1.0.0
 */
+ (void)createVisitContextForConsumer:(nonnull id<AWSDKConsumer>)consumer provider:(nonnull id<AWSDKProvider>)provider completion:(nonnull VisitContextCompletionBlock)completion;

/**
 Creates a new AWSDKVisitContext instance given an AWSDKConsumer parent, AWSDKConsumer dependent, and an AWSDKProvider for a dependent visit.

 @note This is to be used for a dependent visit. For a consumer visit use createVisitContextForConsumer:provider:completion: .

 @param dependent    AWSDKConsumer representing the dependent for whom the visit is for.
 @param parent   AWSDKConsumer representing the account holder and supervising parent.
 @param provider    AWSDKProvider for the visit.
 @param completion  VisitContextCompletionBlock containing the AWSDKVisitContext isntance, otherwise an NSError describing what went wrong.

 @since 4.1.0
 */
+ (void)createVisitContextForDependent:(nonnull id<AWSDKConsumer>)dependent
                                parent:(nonnull id<AWSDKConsumer>)parent
                              provider:(nonnull id<AWSDKProvider>)provider
                            completion:(nonnull VisitContextCompletionBlock)completion;

/**
 Creates a new AWSDKVisitContext instance for a consumer Find First Available visit.

 @note This is not for a dependent visit. For a dependent visit use createVisitContextForConsumer:dependent:specialty:completion: instead.

 @discussion In order to properly leverage the AWSDKOnDemandSpecialty in reducing the consumer drop-off rate after a provider has accepted the visit, practices that use the First Available
 functionality should check that all of the providers (matching the criteria of the First Available feature) have uniform pricing. The First Available feature should only be enabled if the patient’s
 copay responsibility for the visit will be identical for a visit with any provider associated with the First Available feature.

 @param consumer   AWSDKConsumer for the visit.
 @param specialty  AWSDKOnDemandSpecialty to search for providers for.
 @param completion  VisitContextCompletionBlock containing the AWSDKVisitContext isntance, otherwise an NSError describing what went wrong.

 @since 4.1.0
 */
+ (void)createVisitContextForConsumer:(nonnull id<AWSDKConsumer>)consumer specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty completion:(nonnull VisitContextCompletionBlock)completion;

/**
 Creates a new AWSDKVisitContext instance for a consumer Find First Available visit.

 @note This is not for a dependent visit. For a dependent visit use createVisitContextForConsumer:dependent:specialty:completion: instead.

 @discussion In order to properly leverage the AWSDKOnDemandSpecialty in reducing the consumer drop-off rate after a provider has accepted the visit, practices that use the First Available
 functionality should check that all of the providers (matching the criteria of the First Available feature) have uniform pricing. The First Available feature should only be enabled if the patient’s
 copay responsibility for the visit will be identical for a visit with any provider associated with the First Available feature.

 @param consumer    AWSDKConsumer for the visit.
 @param specialty   AWSDKOnDemandSpecialty to search for providers for.
 @param practice    AWSDKPractice to override the practice associated to the specialty.
 @param providerTypes   Array of AWSDKProviderType to combine with the list of provider types associated to the specialty.
 @param completion VisitContextCompletionBlock containing the AWSDKVisitContext isntance, otherwise an NSError describing what went wrong.

 @since 4.2.0
 */
+ (void)createVisitContextForConsumer:(nonnull id<AWSDKConsumer>)consumer
                            specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty
                             practice:(nullable id<AWSDKPractice>)practice
                        providerTypes:(nullable NSArray<id<AWSDKProviderType>> *)providerTypes
                           completion:(nonnull VisitContextCompletionBlock)completion;

/**
 Creates a new AWSDKVisitContext instance for a dependent Find First Available visit.

 @discussion In order to properly leverage the AWSDKOnDemandSpecialty in reducing the consumer drop-off rate after a provider has accepted the visit, practices that use the First Available
 functionality should check that all of the providers (matching the criteria of the First Available feature) have uniform pricing. The First Available feature should only be enabled if the patient’s
 copay responsibility for the visit will be identical for a visit with any provider associated with the First Available feature.

 @param dependent    AWSDKConsumer representing the dependent for whom the visit is for.
 @param parent   AWSDKConsumer representing the account holder and supervising parent.
 @param specialty  AWSDKOnDemandSpecialty to search for providers for.
 @param completion  VisitContextCompletionBlock containing the AWSDKVisitContext isntance, otherwise an NSError describing what went wrong.

 @since 4.1.0
 */
+ (void)createVisitContextForDependent:(nonnull id<AWSDKConsumer>)dependent
                                parent:(nonnull id<AWSDKConsumer>)parent
                             specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty
                            completion:(nonnull VisitContextCompletionBlock)completion;

/**
 Creates a new AWSDKVisitContext instance for a dependent Find First Available visit.

 @discussion In order to properly leverage the AWSDKOnDemandSpecialty in reducing the consumer drop-off rate after a provider has accepted the visit, practices that use the First Available
 functionality should check that all of the providers (matching the criteria of the First Available feature) have uniform pricing. The First Available feature should only be enabled if the patient’s
 copay responsibility for the visit will be identical for a visit with any provider associated with the First Available feature.

 @param dependent   AWSDKConsumer representing the dependent for whom the visit is for.
 @param parent      AWSDKConsumer representing the account holder and supervising parent.
 @param specialty   AWSDKOnDemandSpecialty to search for providers for.
 @param practice    AWSDKPractice to override the practice associated to the specialty.
 @param providerTypes   Array of AWSDKProviderType to combine with the list of provider types associated to the specialty.
 @param completion VisitContextCompletionBlock containing the AWSDKVisitContext isntance, otherwise an NSError describing what went wrong.

 @since 4.2.0
 */
+ (void)createVisitContextForDependent:(nonnull id<AWSDKConsumer>)dependent
                                parent:(nonnull id<AWSDKConsumer>)parent
                             specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty
                              practice:(nullable id<AWSDKPractice>)practice
                         providerTypes:(nullable NSArray<id<AWSDKProviderType>> *)providerTypes
                            completion:(nonnull VisitContextCompletionBlock)completion;

/**
 Creates a new AWSDKVisitContext instance for a scheduled appointment.

 @note The [AWSDKAppointment status] must be OnTime to create the visit context.

 @param appointment AWSDKAppointment representing the scheduled appointment.
 @param completion  VisitContextCompletionBlock containing the AWSDKVisitContext isntance, otherwise an NSError describing what went wrong.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidAppointmentStatus  Appointment is not ready to be started.

 @since 1.0.0
 */
+ (void)createVisitContextForAppointment:(nonnull id<AWSDKAppointment>)appointment completion:(nonnull VisitContextCompletionBlock)completion;

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKConsumer representing the person for whom the visit is for. This can be either the account owner or a dependent.

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKConsumer> consumer;

/**
 NSString representing the consumer's unformatted phone number.

 @since 3.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *phoneNumber;

/**
 NSString representing the consumer's formatted phone number.

 @since 4.2.0
 */
@property (nonatomic, readonly, nonnull) NSString *formattedPhoneNumber;

/**
 AWSDKConsumer representing the party that is responsible for the dependent consumer having the visit.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKConsumer> consumerProxy;

/**
 AWSDKProvider representing the provider selected for the visit, otherwise _nil_ for a first available visit.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKProvider> provider;

/**
 AWSDKOnDemandSpecialty representing the specialty selected for the first available visit, otherwise _nil_ if not a first available visit.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKOnDemandSpecialty> specialty;

#pragma mark - Context Read-Only Flags
/**
 @name Context Flags
 */

/**
 _TRUE_ if the consumer has a health history to share with the provider, otherwise _FALSE_ if no health history is on file.

 @since 1.0.0
 */
@property (assign, readonly) BOOL consumerHasHealthHistory;

/**
 _TRUE_ if the provider can prescribe, otherwise _FALSE_ if they cannot.

 @since 1.0.0
 */
@property (assign, readonly) BOOL providerCanPrescribe;

/**
 _TRUE_ if the provider desires consumer's conditions to be collected for the visit, otherwise _FALSE_ if it is not necessary.

 @note This does not have any effect on the consumer conditions API. This is configurable by the system admin for a provider type.

 @since 2.0.0
 */
@property (assign, readonly) BOOL showConditionsQuestion;

/**
 _TRUE_ if the provider desires consumer's allergies to be collected for the visit, otherwise _FALSE_ if it is not necessary.

 @note This does not have any effect on the consumer allergies API. This is configurable by the system admin for a provider type.

 @since 2.0.0
 */
@property (assign, readonly) BOOL showAllergiesQuestion;

/**
 _TRUE_ if the provider desires consumer's medications to be collected for the visit, otherwise _FALSE_ if it is not necessary.

 @note This does not have any effect on the consumer medications API. This is configurable by the system admin for a provider type.

 @since 2.0.0
 */
@property (assign, readonly) BOOL showMedicationsQuestion;

/**
 _TRUE_ if the provider desires consumer vitals to be collected for the visit, otherwise _FALSE_ if it is not necessary.

 @note This does not have any effect on the consumer vitals API. This is configurable by the system admin for a provider type.

 @since 2.0.0
 */
@property (assign, readonly) BOOL showVitalsQuestion;

/**
 _TRUE_ if the provider desires the consumer to answer triage questions for the visit, otherwise _FALSE_ if it is not necessary.

 @note This is configurable by the system admin.

 @since 3.0.0
 */
@property (assign, readonly) BOOL showTriageQuestions;

#pragma mark - Required Consumer Response Properties
/**
 @name Consumer Response Properties
 */

/**
 Array of all legal documents relevant to the visit.

 @note  Before the visit can be created all legal text marked required must be accepted.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKLegalText>> *legalText;

#pragma mark - Optional Consumer Response Properties
/**
 @name Optional Consumer Response Properties
 */

/**
 NSArray of all available selectable AWSDKVisitTopics.

 @discussion AWSDKVisitTopics cannot be changed, but can be selected by setting [AWSDKVisitTopic selected].

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKVisitTopic>> *visitTopics;

/**
 NSString representing a custom visit topic not covered by visitTopics.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSString *otherTopicText;

/**
 AWSDKFeedbackQuestion for the consumer to respond to.

 @discussion To select a response, set [AWSDKFeedbackQuestion selectedOption];

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKFeedbackQuestion> consumerFeedbackQuestion;

/**
 NSArray of AWSDKTriageQuestion questions to ask the consumer.

 @discussion To set a response, set [AWSDKTriageQuestion response].

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKTriageQuestion>> *triageQuestions;

/**
 NSString representing the consumer's preferred language as a 2 character language code (e.g. @"es", @"en", @"fr").

 @note If this is not set the @"en" will be used by default.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) NSString *visitLanguageCode;

/**
 AWSDKPharmacy representing the selected pharmacy for the visit where prescriptions will be sent.

 @since 1.0.0
 */
@property (nonatomic, readwrite, nullable) id<AWSDKPharmacy> pharmacy;

/**
 Set _TRUE_ if the provider has access to the consumer's health history, otherwise _FALSE_ if this access isn't granted.

 @note By default shareHealthHistory is set to _FALSE_ and access is not granted.

 @since 1.0.0
 */
@property (assign, readwrite) BOOL shareHealthHistory;

#pragma mark - Callback Number
/**
 @name Callback Number
 */

/**
 NSString representing an unformatted override phone number used in the case that the video visit fails and the provider needs to call the consumer to finish the visit.

 @note To check if this feature is enabled, see [AWSDKSystemConfiguration isCallbackViaPhoneEnabled].

 @discussion By default the server uses the consumer's phone number stored in their profile. If the consumer's profile doesn't have a phone number this property is required. It is recommended to
 require the user to provide a callbackNumber.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSString *callbackNumber;

/**
 The AWSDKModality representing the communication mode that the consumer will use for the visit.

 @since 4.3.0
 */
@property (nonatomic, readwrite, nonnull) id<AWSDKModality> selectedModality;

/**
 The AWSDKPractice object associated with the AWSDKVisitContext

 @since 4.3.0
 */
@property (nonatomic, readwrite, nonnull) id<AWSDKPractice> practice;

/**
 Updates the callbackNumber for the visit.

 @note This does not update the consumer's saved phone number.

 @param callbackNumber  NSString for the unformatted phone number.
 @param completion      GenericCompletionBlock containing _TRUE_ if the callbackNumber was successfully updated, otherwise _FALSE_ and an NSError explaining any errors.

 @since 2.1.0
 */
- (void)updateCallbackNumber:(nonnull NSString *)callbackNumber completion:(nullable GenericCompletionBlock)completion;

#pragma mark - Visit Guests
/**
 @name Visit Guests
 */

/**
 NSArray of NSString representing formatted email addresses to send invites to.

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *guestEmails;

/**
 Updates the list of guestEmails to send invites to.

 @param guestEmails NSArray of NSString formatted email addresses to send the invites to. This will replace the previous array of emails.
 @param completion  GenericCompletionBlock containing _TRUE_ if the guest email addresses were successfully updated, otherwise _FALSE_ and an NSError explaining any errors.

 @since 2.0.0
 */
- (void)updateVisitGuestEmails:(nullable NSArray<NSString *> *)guestEmails completion:(nullable GenericCompletionBlock)completion;

@end

/**
 The context of an American Well telehealth visit.

 @discussion To create an AWSDKVisit, first create an AWSDKVisitContext, populate it with details about the visit, then use [AWSDKVisitService createVisitWithContext:completion:] to retrieve the
 associated AWSDKVisit object.

 @since 1.0.0
 */
@interface AWSDKVisitContext : AWSDKDataObject <AWSDKVisitContext>
@property (nonatomic, readonly, nonnull) id<AWSDKConsumer> consumer;
@property (nonatomic, readonly, nonnull) NSString *phoneNumber;
@property (nonatomic, readonly, nullable) id<AWSDKConsumer> consumerProxy;
@property (nonatomic, readonly, nullable) id<AWSDKProvider> provider;
@property (nonatomic, readonly, nullable) id<AWSDKOnDemandSpecialty> specialty;
@property (assign, readonly) BOOL consumerHasHealthHistory;
@property (assign, readonly) BOOL providerCanPrescribe;
@property (assign, readonly) BOOL showConditionsQuestion;
@property (assign, readonly) BOOL showAllergiesQuestion;
@property (assign, readonly) BOOL showMedicationsQuestion;
@property (assign, readonly) BOOL showVitalsQuestion;
@property (assign, readonly) BOOL showTriageQuestions;
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKLegalText>> *legalText;
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKVisitTopic>> *visitTopics;
@property (nonatomic, readwrite, nullable) NSString *otherTopicText;
@property (nonatomic, readonly, nonnull) id<AWSDKFeedbackQuestion> consumerFeedbackQuestion;
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKTriageQuestion>> *triageQuestions;
@property (nonatomic, readwrite, nullable) NSString *visitLanguageCode;
@property (nonatomic, readwrite, nullable) id<AWSDKPharmacy> pharmacy;
@property (assign, readwrite) BOOL shareHealthHistory;
@property (nonatomic, nullable, readonly) NSString *callbackNumber;
@property (nonatomic, readonly, nonnull) NSArray<NSString *> *guestEmails;
@property (nonatomic, readwrite, nonnull) id<AWSDKModality> selectedModality;
@property (nonatomic, readwrite, nonnull) id<AWSDKPractice> practice;

#pragma mark - Appledoc

+ (void)createVisitContextForConsumer:(nonnull id<AWSDKConsumer>)consumer provider:(nonnull id<AWSDKProvider>)provider completion:(nonnull VisitContextCompletionBlock)completion;

+ (void)createVisitContextForDependent:(nonnull id<AWSDKConsumer>)dependent
                                parent:(nonnull id<AWSDKConsumer>)parent
                              provider:(nonnull id<AWSDKProvider>)provider
                            completion:(nonnull VisitContextCompletionBlock)completion;

+ (void)createVisitContextForConsumer:(nonnull id<AWSDKConsumer>)consumer specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty completion:(nonnull VisitContextCompletionBlock)completion;

+ (void)createVisitContextForConsumer:(nonnull id<AWSDKConsumer>)consumer
                            specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty
                             practice:(nullable id<AWSDKPractice>)practice
                        providerTypes:(nullable NSArray<id<AWSDKProviderType>> *)providerTypes
                           completion:(nonnull VisitContextCompletionBlock)completion;

+ (void)createVisitContextForDependent:(nonnull id<AWSDKConsumer>)dependent
                                parent:(nonnull id<AWSDKConsumer>)parent
                             specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty
                            completion:(nonnull VisitContextCompletionBlock)completion;

+ (void)createVisitContextForDependent:(nonnull id<AWSDKConsumer>)dependent
                                parent:(nonnull id<AWSDKConsumer>)parent
                             specialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty
                              practice:(nullable id<AWSDKPractice>)practice
                         providerTypes:(nullable NSArray<id<AWSDKProviderType>> *)providerTypes
                            completion:(nonnull VisitContextCompletionBlock)completion;
+ (void)createVisitContextForAppointment:(nonnull id<AWSDKAppointment>)appointment completion:(nonnull VisitContextCompletionBlock)completion;

- (void)updateCallbackNumber:(nonnull NSString *)callbackNumber completion:(nullable GenericCompletionBlock)completion;
- (void)updateVisitGuestEmails:(nullable NSArray<NSString *> *)guestEmails completion:(nullable GenericCompletionBlock)completion;

@end
