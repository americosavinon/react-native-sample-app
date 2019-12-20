//
//  AWSDKConsumer.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/21/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKUser.h>
#import <AWSDK/AWSDKVisitDisposition.h>

@class AWSDKMessageFetchOptions, AWSDKDeviceIntegrationSearchRequest, AWSDKDeviceIntegrationRequest, AWSDKTrackersRequest;

// clang-format off
@protocol AWSDKSubscription, AWSDKPharmacy,  AWSDKVisitContext, AWSDKMedication, AWSDKMessageDraft, AWSDKAddress, AWSDKAllergy, AWSDKCondition, AWSDKState, AWSDKPaymentMethodForm, AWSDKConsumerVitalsForm, AWSDKSubscriptionForm, AWSDKDemographicForm, AWSDKConsumerUpdateForm, AWSDKDependentUpdateForm, AWSDKHealthTrackerRecordForm, AWSDKPractice, AWSDKProvider, AWSDKSchedule, AWSDKLegalText, AWSDKReminderOption, AWSDKCountry, AWSDKTrackersRequest, AWSDKDeviceIntegration;
// clang-format on

/**
 A consumer or dependent protocol of the American Well telehealth platform.

 @since 3.1.0
 */
@protocol AWSDKConsumer <AWSDKUser>
#pragma mark - Read Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing a shared unique identifier that matches a user in your database to an American Well User, otherwise _nil_ if the consumer is a dependent.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSString *consumerAuthKey;

/**
 NSString representing the outstanding disclaimer text sent by the server that the consumer hasn't accepted yet. If this value is _nil_, there is no outstanding disclaimer

 @since 3.0.1
 */
@property (readonly, nullable) id<AWSDKLegalText> outstandingDisclaimer;

/**
 BOOL describing if appointment reminder text messages are enabled for this consumer

 @since 3.1.0
 */
@property (readonly) BOOL appointmentReminderTextsEnabled;

/**
 NSDate representing the consumer's date of birth.

 @note When representing this field in your UI and to avoid off-by-one errors, be sure you are using the UTC time zone. This field is serialized from "milliseconds since epoch" at 00:00:00.

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) NSDate *dateOfBirth;

/**
 NSString representing the consumer's age.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *age;

/**
 AWSDKState object representing the state which the consumer has legal residence in.

 @since 4.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKState> stateOfLegalResidence;

/**
 AWSDKCountry object representing the country which the consumer has legal residence in.

 @since 4.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKCountry> countryOfLegalResidence;

/**
 NSString representing the consumer's primary email.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *email;

/**
 AWSDKAddress object representing the consumer's physical address.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKAddress> address;

/**
 NSString representing the consumer's unformatted phone number.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *phoneNumber;

/**
 NSString representing the consumer's formatted phone number.

 @since 4.2.0
 */
@property (nonatomic, readonly, nonnull) NSString *formattedPhoneNumber;

/**
 NSArray of the consumer's dependents, otherwise _nil_ if the consumer is a dependent.

 @discussion If the consumer is not a dependent and has no dependents, this is an empty array.

 @since 1.0.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKConsumer>> *dependents;

/**
 NSString representing the consumer's source id.

 @discussion    This optional sourceid can be used as metadata to determine the origin of
     the consumer record.

 @since 3.2.2
 */
@property (nonatomic, readonly, nullable) NSString *sourceId;

/**
 NSLocale representing the consumer's preferred locale, which determines the language and format the American Well telehealth platform uses for system generated messages.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSLocale *preferredLocale;

/**
 If the consumer is a dependent, the associated authenticated parent in the American Well telehealth platform, otherwise _nil_.

 @since 4.1.0
 */
@property (weak, nonatomic, readonly, nullable) id<AWSDKConsumer> authenticatedParent;

/**
 NSArray of the consumer's parents, otherwise _empty_ if the consumer is a parent.

 @discussion If the consumer is not a dependent, this is an empty array.

 @since 4.1.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKConsumer>> *parents;

/**
 The AWSDKSubscription for the consumer.

 @since 4.1.3
 */
@property (nonatomic, readonly, nullable) id<AWSDKSubscription> subscription;

/**
 NSTimeZone representing the consumer's time zone.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSTimeZone *timeZone;

/**
 NSString representing the consumer's sdkUserId.

 @discussion    The sdkUserId is similar to the consumer's source ID, but it's tied to a specific SDK configuration

 @since 5.0.0
 */
@property (nonatomic, readonly, nullable) NSString *sdkUserId;

/**
 NSArray of strings representing a consumer's branding attributes.

 @since 4.4.0
 */
@property (nonatomic, readonly, nullable) NSArray<NSString *> *brandings;

#pragma mark - Configurations
/**
 @name Configurations
 */

/**
 Method used to indicate if the consumer was created with a health plan feed.

 @return Boolean indicating if the consumer was feed generated.

 @since 1.0.0
 */
- (BOOL)wasFeedGenerated;

/**
 Method used to indicate if the consumer's credentials were system generated.

 @return Boolean indicating if the consumer's credentials were system generated

 @since 3.0.0
 */
- (BOOL)hasSystemGeneratedCredentials;

/**
 Adds a practice's service key. These keys determine which practices are visible to the consumer.

 @param key         NSString service key of the practice to add.
 @param completion  GenericCompletionBlock containing _TRUE_ if applied successfully, otherwise _FALSE_ and an NSError explaining why.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing required value

 @since 1.0.0
 */
- (void)applyServiceKey:(nonnull NSString *)key withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Boolean indicating if the consumer can add a dependent.
 @discussion Dependent and HP feed consumers are unable to add dependents.

 @since 2.1.2
 */
- (BOOL)canAddDependent;

/**
 Informs the server that the consumer has accepted the terms of the legal text.

 @param completion GenericCompletionBlock indicating success or an NSError explaining any errors.

 @since 3.0.1
 */
- (void)acceptDisclaimer:(nullable GenericCompletionBlock)completion;

#pragma mark - Notifications
/**
 Fetches an AWSDKConsumerNotifications object that represents actionable notifications that a consumer could respond to

 @param completion ActionableNotificationBlock containing the expected AWSDKConsumerNotifications object

 @since 4.2.0
 */
- (void)fetchActionableNotificationsWithCompletion:(nonnull ActionableNotificationBlock)completion;

#pragma mark - Demographics
/**
 @name Demographics
 */

/**
 Updates the details of the consumer or dependent.

 @discussion If a consumer was generated by a health plan feed, certain properties on the consumer cannot be updated with this method. These fields are as follows:
 [AWSDKDemographicForm firstName],
 [AWSDKDemographicForm middleInitial],
 [AWSDKDemographicForm lastName],
 [AWSDKConsumerDemographicForm address],
 [AWSDKDemographicForm dateOfBirth],
 [AWSDKDemographicForm gender]

 @param form       AWSDKDemographicForm containing new values to set on the consumer or dependent.
 @param completion ConsumerResultCompletionBlock containing a new instance of the AWSDKConsumer with new values populated.

 Potential Error Codes
 @exception AWSDKInvalidValue   The AWSDKConsumerUpdateForm containing either values that cannot be updated as a feed generated consumer or invalid values.

 @since 3.0.2
 */
- (void)updateDemographicsWithForm:(nonnull id<AWSDKDemographicForm>)form withCompletion:(nonnull ConsumerResultCompletionBlock)completion;

#pragma mark - Pharmacy
/**
 @name Pharmacy
 */

/**
 Fetches the consumer's array of pharmacies.

 @param completion  PharmaciesCompletionBlock containing an array of AWSDKPharmacy objects, otherwise an NSError explaining if anything went wrong.

 @discussion        An empty array doesn't exclusively mean successful response.  Always check for an error response before parsing the array.

 @since 3.2.0
 */
- (void)fetchPharmaciesWithCompletion:(nonnull PharmaciesCompletionBlock)completion;

/**
 Fetches the consumer's preferred pharmacy.

 @param completion  PharmacyCompletionBlock containing the AWSDKPharmacy as a populated pharmacy or _nil_ if no preferred pharmacy, otherwise an NSError explaining if anything went wrong.

 @since 1.0.0
 */
- (void)fetchPreferredPharmacyWithCompletion:(nonnull PharmacyCompletionBlock)completion;

/**
 Updates the consumer's preferred pharmacy.

 @discussion A shipping address is required when updating with a mail order pharmacy see [AWSDKPharmacy isMailOrder].

 @param pharmacy    AWSDKPharmacy to set as the preferred pharmacy.
 @param completion  GenericCompletionBlock containing _TRUE_ if the pharmacy was successfully updated, otherwise _FALSE_ and an NSError if the pharmacy was not updated.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidMissingAddress Consumer does not have a saved shipping AWSDKAddress for a mail order pharmacy. Add one using updateShippingAddress:completion:.

 @since 1.0.0
 */
- (void)updatePreferredPharmacy:(nonnull id<AWSDKPharmacy>)pharmacy withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Gets the consumer's preferred shipping AWSDKAddress.

 @param completion  AddressCompletionBlock containing the consumer's shipping AWSDKAddress if one was found, and an NSError explaining any errors encountered.

 @since 1.0.0
 */
- (void)getShippingAddress:(nullable AddressCompletionBlock)completion;

/**
 Updates the shipping AWSDKAddress for the consumer.

 @param newAddress  AWSDKAddress to set
 @param completion  GenericCompletionBlock containing _TRUE_ if the update was successful, otherwise _FALSE_ and an NSError explaining any errors that were encountered.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing required value.
 @exception AWSDKErrorCodeInvalidValue                          Invalid Address.

 @since 1.0.0
 */
- (void)updateShippingAddress:(nonnull id<AWSDKAddress>)newAddress completion:(nullable GenericCompletionBlock)completion;

#pragma mark - Health Information
/**
 @name Health Information
 */

/**
 Gets the most recent vitals for a consumer.

 @param context    AWSDKVisitContext to specify what visit's vitals to retrieve. If context is _nil_ then getVitals:withCompletion: will retrieve the last saved vitals.
 @param completion VitalsCompletionBlock containing the AWSDKConsumerVitals for the consumer or an NSError explaining if anything went wrong.

 @since 2.0.0
 */
- (void)getVitals:(nullable id<AWSDKVisitContext>)context withCompletion:(nonnull VitalsCompletionBlock)completion;

/**
 Updates the consumer's vitals on the American Well telehealth platform.

 @param vitals     The AWSDKConsumerVitalsForm object representing the new vital information.
 @param context    Optional AWSDKVisitContext to update vitals within a particular intake.
 @param completion GenericCompletionBlock containing _TRUE_ if the vitals were successfully updated, otherwise _FALSE_ and an NSError if anything went wrong updating.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing required value.
 @exception AWSDKErrorCodeInvalidValue                          Invalid vitals value.

 @since 2.0.0
 */
- (void)updateVitals:(nonnull id<AWSDKConsumerVitalsForm>)vitals withContext:(nullable id<AWSDKVisitContext>)context withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Fetches the consumer's health summary.

 @param completion HealthSummaryCompletionBlock containing the AWSDKHealthSummary, or an optional NSError explaining if anything went wrong.

 @since 1.0.0
 */
- (void)fetchHealthSummaryWithCompletion:(nonnull HealthSummaryCompletionBlock)completion;

/**
 Fetches a list of allergies defined by the American Well telehealth platform. Allergies reported by the consumer will be marked as current see [AWSDKAllergy isCurrent].

 @param completion AllergiesCompletionBlock containing an NSArray of AWSDKAllergy objects, or an NSError explaining any failures.

 @since 1.0.0
 */
- (void)fetchAllergiesWithCompletion:(nonnull AllergiesCompletionBlock)completion;

/**
 Updates the list of the consumer's reported allergies on the telehealth platform.

 @discussion This does not append the new items to the list of allergies. All allergies passed to this method will be marked as current.

 @param newAllergies NSArray of AWSDKAllergy items to set as current for the consumer.
 @param completion   GenericCompletionBlock containing _TRUE_ if the update was successful, otherwise _FALSE_ and an NSError documenting any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Missing required newAllergies.

 @since 1.0.0
 */
- (void)updateAllergies:(nonnull NSArray<id<AWSDKAllergy>> *)newAllergies withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Fetches a list of conditions defined by the American Well telehealth platform. Conditions reported by the consumer will be marked as current see [AWSDKCondition isCurrent].

 @param completion  ConditionsCompletionBlock containing the NSArray of AWSDKCondition objects, or an NSError explaining any failures.

 @since 1.0.0
 */
- (void)fetchConditionsWithCompletion:(nonnull ConditionsCompletionBlock)completion;

/**
 Updates the list of the consumer's reported conditions on the telehealth platform.

 @discussion This does not append the new items to the existing list of conditions, the new items will completely replace the old list. Any
 conditions passed to this method will be marked as current.

 @param newConditions   NSArray of AWSDKCondition items to set as current for the consumer.
 @param completion      GenericCompletionBlock containing _TRUE_ if the update was successful, otherwise _FALSE_ and an NSError documenting any failures.

 Potential Error Codes
 @exception  AWSDKErrorCodeValidationRequiredParameterMissing  Missing required newConditions.

 @since 1.0.0
 */
- (void)updateConditions:(nonnull NSArray<id<AWSDKCondition>> *)newConditions withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Fetches a list of medications the consumer is reported as taking.

 @param completion MedicationsCompletionBlock containing an NSArray of AWSDKMedication objects, or an NSError documenting any failures.

 @since 1.0.0
 */
- (void)fetchMedicationsWithCompletion:(nonnull MedicationsCompletionBlock)completion;

/**
 Update the consumer's current medications to the given array.

 @discussion Any current medications not in newMedications will be not saved and lost.

 @param newMedications NSArray of new AWSDKMedication objects to add to the consumer's profile.
 @param completion     GenericCompletionBlock containing _TRUE_ if the medications were successfully updated, otherwise _FALSE_ and an optional NSError documenting any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing   Missing required newMedications.

 @since 1.0.0
 */
- (void)updateMedications:(nonnull NSArray<id<AWSDKMedication>> *)newMedications withCompletion:(nullable GenericCompletionBlock)completion;

#pragma mark - Health Trackers
/**
 Adds new AWSDKHealthTrackerRecord objects to the consumer's health summary.

 @discussion Will append, not overwrite existing data.

 @param records The array of AWSDKHealthTrackerRecordForm objects containing information about the tracker records to add to the consumer's health summary
 @param context Optional AWSDKVisitContext, if one is provided the new tracker records will be accessible by the provider in the visit
 @param completion GenericCompletionBlock containing _TRUE_ if the trackers were successfully added, otherwise _FALSE_ and an optional NSError documenting any failures.

 @since 3.0.0
 */
- (void)addHealthTrackerRecords:(nonnull NSArray<id<AWSDKHealthTrackerRecordForm>> *)records
               withVisitContext:(nullable id<AWSDKVisitContext>)context
                     completion:(nullable GenericCompletionBlock)completion;

#pragma mark - General Trackers
/**
 Fetches trackers matching the criteria for a customer.

 @discussion It will return trackers that's within the start and end date matching the templateId.

 @param template    AWSDKTrackerTemplate representing the template of the tracker
 @param dateInterval NSDateInterval representing the start and end date criteria
 @param timeZone    NSTimeZone representing the timezone of the date
 @param completion  TrackerEntriesCompletionBlock containing an array of AWSDKTrackerEntry if the trackers were found, otherwise nil and an optional NSError documenting any failures.

 @since 5.0.0
 */
- (void)fetchTrackersWithTemplate:(nonnull id<AWSDKTrackerTemplate>)template
                     dateInterval:(nonnull NSDateInterval *)dateInterval
                         timeZone:(nonnull NSTimeZone *)timeZone
                       completion:(nonnull TrackerEntriesCompletionBlock)completion;

/**
 Adds trackers for a customer.

 @discussion It will add all trackers within the trackers request.

 @param trackersRequest AWSDKTrackersRequest holding the measurement time and array of AWSDKTrackerEntryRequest entries to add
 @param completion      GenericCompletionBlock containing _TRUE_ if the trackers were successfully added, otherwise _FALSE_ and an optional NSError documenting any failures.

 @since 5.0.0
 */
- (void)addGeneralTrackersForRequest:(nonnull AWSDKTrackersRequest *)trackersRequest completion:(nullable GenericCompletionBlock)completion;

/**
 Deletes trackers matching the criteria for a consumer.

 @discussion It will delete trackers that's within the start and end date matching the templateId.

 @param template    AWSDKTrackerTemplate representing the template of the tracker
 @param dateInterval  NSDateInterval representing the start and end date criteria
 @param timeZone    NSTimeZone representing the timezone of the date
 @param completion  GenericCompletionBlock containing _TRUE_ if the trackers were successfully deleted, otherwise _FALSE_ and an optional NSError documenting any failures.

 @since 5.0.0
 */
- (void)deleteTrackersWithTemplate:(nonnull id<AWSDKTrackerTemplate>)template
                      dateInterval:(nonnull NSDateInterval *)dateInterval
                          timeZone:(nonnull NSTimeZone *)timeZone
                        completion:(nullable GenericCompletionBlock)completion;

#pragma mark - Health Documents
/**
 @name Health Documents
 */

/**
 Fetches a list of health documents from the consumer's profile.

 @param completion HealthDocumentsCompletionBlock containing an NSArray of AWSDKHealthDocument for the consumer, otherwise an NSError documenting any failures.

 @since 2.0.0
 */
- (void)fetchHealthDocumentsWithCompletion:(nonnull HealthDocumentsCompletionBlock)completion;

/**
 Adds a health document to the consumer's profile.

 @param documentData NSData representing the attachment file.
 @param type         NSString representing the standard mime type of the attachment.
 @param name         NSString as the name of the document file.
 @param completion   HealthDocumentCompletionBlock containing the resulting id<AWSDKHealthDocument> if the health document was successfully added, or nil and an NSError if there was an error.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    A required parameter is missing or _nil_.
 @exception AWSDKErrorCodeAttachmentTypeNotAllowed              The MimeType is not allowed for upload.
 @exception AWSDKErrorCodeAttachmentTooBig                      The file size is too large to upload.

 @since 3.1.1
 */
- (void)addHealthDocument:(nonnull NSData *)documentData withMimeType:(nonnull NSString *)type withFilename:(nonnull NSString *)name completion:(nonnull HealthDocumentCompletionBlock)completion;

/**
 Adds a health document to the consumer's profile with the option to associate the document to a visit along with a comment

 @param documentData NSData representing the attachment file.
 @param type         NSString representing the standard mime type of the attachment.
 @param name         NSString as the name of the document file.
 @param visit        Optional AWSDKVisit object to associate with the document.
 @param comment      Optional comment about the document.

 @param completion   HealthDocumentCompletionBlock containing the resulting AWSDKHealthDocument if the health document was successfully added, or nil and an NSError if there was an error.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    A required parameter is missing or _nil_.
 @exception AWSDKErrorCodeAttachmentTypeNotAllowed              The MimeType is not allowed for upload.
 @exception AWSDKErrorCodeAttachmentTooBig                      The file size is too large to upload.

 @since 4.3.0
 */
- (void)addHealthDocument:(nonnull NSData *)documentData
             withMimeType:(nonnull NSString *)type
             withFilename:(nonnull NSString *)name
                 forVisit:(nullable id<AWSDKVisit>)visit
              withComment:(nullable NSString *)comment
               completion:(nonnull HealthDocumentCompletionBlock)completion;

/**
 Adds a file at a local filePath to the consumer's profile.

 @param filePath    NSString representing the exact local path to the specified file.
 @param completion  HealthDocumentCompletionBlock containing the resulting id<AWSDKHealthDocument> if the health document was successfully added, or nil and an NSError if there was an error.

 Potential Error Codes
 @exception AWSDKErrorCodeFileDoesNotExist                      There is no file at the given filePath.
 @exception AWSDKErrorCodeFileExtensionInvalid                  The file path does not include an extension or is not a valid extension type.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    A required parameter is missing or _nil_.
 @exception AWSDKErrorCodeAttachmentTypeNotAllowed              The MimeType is not allowed for upload.
 @exception AWSDKErrorCodeAttachmentTooBig                      The file size is too large to upload.

 @since 3.1.1
 */
- (void)addHealthDocumentFromPath:(nonnull NSString *)filePath completion:(nonnull HealthDocumentCompletionBlock)completion;

/**
 Adds a file at a local filePath to the consumer's profile with the option to associate the document to a visit along with a comment

 @param filePath    NSString representing the exact local path to the specified file.
 @param visit       Optional AWSDKVisit object to associate with the document.
 @param comment     Optional comment about the document.

 @param completion  HealthDocumentCompletionBlock containing the resulting <AWSDKHealthDocument> if the health document was successfully added, or nil and an NSError if there was an error.

 Potential Error Codes
 @exception AWSDKErrorCodeFileDoesNotExist                      There is no file at the given filePath.
 @exception AWSDKErrorCodeFileExtensionInvalid                  The file path does not include an extension or is not a valid extension type.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    A required parameter is missing or _nil_.
 @exception AWSDKErrorCodeAttachmentTypeNotAllowed              The MimeType is not allowed for upload.
 @exception AWSDKErrorCodeAttachmentTooBig                      The file size is too large to upload.

 @since 4.3.0
 */

- (void)addHealthDocumentFromPath:(nonnull NSString *)filePath
                         forVisit:(nullable id<AWSDKVisit>)visit
                      withComment:(nullable NSString *)comment
                       completion:(nonnull HealthDocumentCompletionBlock)completion;

#pragma mark - Health Plans
/**
 @name Health Plans
 */

/**
 Retrieves the consumer's health plan subscription.

 @param completion SubscriptionCompletionBlock containing the consumer's AWSDKSubscription, or an NSError if there was an error.

 @since 1.0.0
 */
- (void)fetchHealthPlanSubscription:(nullable SubscriptionCompletionBlock)completion;

/**
 Updates the consumer's health plan subscription within an optional visit context.

 @param subscription    AWSDKSubscriptionForm object representing the consumer's new subscription information. If a visit context is provided then [AWSDKSubscriptionForm ignoreEligibility] will be set
 to _TRUE_.
 @param context         AWSDKVisitContext passed if the health plan is being updated within intake, otherwise _nil_ if outside intake.
 @param completion      SubscriptionCompletionBlock containing the consumer's new AWSDKSubscription if the subscription was successfully updated, otherwise an NSError which describes any issues.

 Potential Error Codes
 @exception AWSDKErrorCodeEligibilityInaccuratePrimarySubscriberInfo            The subscription in AWSDKNewSubscription is invalid.
 @exception AWSDKErrorCodeValidationEligibilityException                        The subscription cannot be validated at this time. The consumer's subscription will still be updated in this case.
 @exception AWSDKErrorCodeInvalidValue                                          Invalid value.

 @since 2.0.0
 */
- (void)updateHealthPlanSubscription:(nullable id<AWSDKSubscriptionForm>)subscription
                    withVisitContext:(nullable id<AWSDKVisitContext>)context
                      withCompletion:(nonnull SubscriptionCompletionBlock)completion;

#pragma mark - Payment Methods
/**
 @name Payment Methods
 */

/**
 Fetches the consumer's preferred payment method.

 @param completion PaymentMethodCompletionBlock containing the consumer's AWSDKPaymentMethod if a preferred payment method is saved, otherwise a _nil_ if no payment method exists, or an NSError
 indicating a problem with the request.

 @since 1.0.0
 */
- (void)fetchPaymentMethodWithCompletion:(nonnull PaymentMethodCompletionBlock)completion;

/**
 Updates the consumer's preferred payment method.

 @param paymentMethod   AWSDKPaymentMethodForm with the information for the new payment method.
 @param completion      PaymentMethodCompletionBlock containing the AWSDKPaymentMethod saved or an NSError explaining if anything went wrong. The code for the error is AWSDKErrorCodeInvalidValue, and
 the userInfo dictionary describes the error.



 Potential Error Codes
 The method performs validation on the street address, city, state, zip of the card holder, and the credit card number, CVV code and expiration date.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing            Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                                  Invalid required parameter.

 @since 2.0.0
 */
- (void)updatePaymentMethod:(nonnull id<AWSDKPaymentMethodForm>)paymentMethod withCompletion:(nonnull PaymentMethodCompletionBlock)completion;

#pragma mark - Appointments
/**
 @name Appointments
 */

/**
 Fetches the scheduled appointments for the consumer following an optional date.

 @note When the provided consumer is the parent, then the list of appointments will also include the appointments for the dependents.

 @param date       Optional NSDate for completion to contain appointments on and after this date. Note the time is ignored.
 @param completion AppointmentsCompletionBlock containing the NSArray of AWSDKAppointment objects, or an NSError explaining what went wrong.

 @since 4.1.0
 */
- (void)getAppointmentsSinceDate:(nullable NSDate *)date withCompletion:(nonnull AppointmentsCompletionBlock)completion;

/**
 Fetches an appointment from a Telehealth Now URL.

 @param url        NSURL linking to the appointment referenced by Telehealth Now
 @param completion AppointmentCompletionBlock containing AWSDKAppointment for the url or an NSError explaining the error.

 @since 1.0.0
 */
- (void)appointmentFromUrl:(nonnull NSURL *)url withCompletion:(nonnull AppointmentCompletionBlock)completion;

/**
 Gets a specific AWSDKAppointment for a given appointment id.

 @param appointmentId NSString id of the associated appointment.
 @param completion AppointmentCompletionBlock containing an AWSDKAppointment object for the associated id, or an NSError explaining the error.

 @since 4.0.0
 */
- (void)fetchAppointmentWithId:(nonnull NSString *)appointmentId completion:(nonnull AppointmentCompletionBlock)completion;

/**
 Gets a specific AWSDKAppointment for a given visit source id.

 @param sourceId NSString id of the visit source.
 @param completion AppointmentCompletionBlock containing an AWSDKAppointment object for the associated id, or an NSError explaining the error.

 @since 4.1.0
 */
- (void)fetchAppointmentWithSourceId:(nonnull NSString *)sourceId completion:(nonnull AppointmentCompletionBlock)completion;

/**
 Schedules an appointment with a provider on a specified date. Reminder options are available for both the consumer and provider.

 @discussion The server can send an optional reminder email to the provider and the consumer about the appointment. The email can be sent at different time intervals provided by AWSDKReminderOption.

 @param provider                AWSDKProvider to have the appointment with.
 @param practice                AWSDKPractice that the provider belongs to.
 @param schedule                AWSDKSchedule representing the time to schedule for the appointment. This object must be fetched from a provider's calendar by calling [AWSDKProvider
 fetchAvailableAppointmentsOnDate:withCompletion:] .
 @param phoneNumber             NSString representing an optional phone number to update on the consumer's profile in case the provider needs to contact or callback the consumer.
 @param consumerReminderOption  AWSDKReminderOption representing when the server should send a reminder to the consumer prior to the appointment.
 @param providerReminderOption  AWSDKReminderOption representing when the server should send a reminder to the provider prior to the appointment.
 @param completion              GenericCompletionBlock containing _TRUE_ if the appointment was successfully scheduled, otherwise _FALSE_ and an NSError explaining any error cases.

 Error Codes
 @exception AWSDKErrorCodeVisitSchedulingFailure   The appointment schedule is already taken by another appointment.

 @since 3.0.0
 */
- (void)scheduleAppointmentWithProvider:(nonnull id<AWSDKProvider>)provider
                             inPractice:(nonnull id<AWSDKPractice>)practice
                           withSchedule:(nonnull id<AWSDKSchedule>)schedule
                        withPhoneNumber:(nullable NSString *)phoneNumber
             withConsumerReminderOption:(nonnull id<AWSDKReminderOption>)consumerReminderOption
             withProviderReminderOption:(nonnull id<AWSDKReminderOption>)providerReminderOption
                         withCompletion:(nullable GenericCompletionBlock)completion;

/**
 Schedules an appointment with a provider on a specified date using a visit report summary. Reminder options are available for both the consumer and provider.

 @discussion The server can send an optional reminder email to the provider and the consumer about the appointment. The email can be sent at different time intervals provided by AWSDKReminderOption.

 @note When the summary parameter is non-NULL, this method will perform a scheduled visit for the failed visit in the summary report. The failed visit must have one of the following dispositions:
 AWSDKVisitDispositionConsumerCanceled, AWSDKVisitDispositionConsumerDisconnected, AWSDKVisitDispositionDeleted, AWSDKVisitDispositionProviderResponseTimeout,
 AWSDKVisitDispositionProviderDisconnected, AWSDKVisitDispositionProviderCanceled, AWSDKVisitDispositionExpired

 @param provider                AWSDKProvider to have the appointment with.
 @param practice                AWSDKPractice that the provider belongs to.
 @param schedule                AWSDKSchedule representing the time to schedule for the appointment. This object must be fetched from a provider's calendar by calling [AWSDKProvider
 fetchAvailableAppointmentsOnDate:withCompletion:] .
 @param phoneNumber             NSString representing an optional phone number to update on the consumer's profile in case the provider needs to contact or callback the consumer.
 @param consumerReminderOption  AWSDKReminderOption representing when the server should send a reminder to the consumer prior to the appointment.
 @param providerReminderOption  AWSDKReminderOption representing when the server should send a reminder to the provider prior to the appointment.
 @param summary                 AWSDKVisitReportSummary representing a visit summary report in the past that the consumer wants to use as basis of visit.
 @param completion              GenericCompletionBlock containing _TRUE_ if the appointment was successfully scheduled, otherwise _FALSE_ and an NSError explaining any error cases.

 Error Codes
 @exception AWSDKErrorCodeVisitSchedulingFailure   The appointment schedule is already taken by another appointment.
 @exception AWSDKErrorCodeVisitInvalidDisposition   The visit doesn't have a valid disposition.

 @since 5.2.0
 */
- (void)scheduleAppointmentWithProvider:(nonnull id<AWSDKProvider>)provider
                             inPractice:(nonnull id<AWSDKPractice>)practice
                           withSchedule:(nonnull id<AWSDKSchedule>)schedule
                        withPhoneNumber:(nullable NSString *)phoneNumber
             withConsumerReminderOption:(nonnull id<AWSDKReminderOption>)consumerReminderOption
             withProviderReminderOption:(nonnull id<AWSDKReminderOption>)providerReminderOption
                 withVisitSummaryReport:(nullable id<AWSDKVisitReportSummary>)summary
                         withCompletion:(nullable GenericCompletionBlock)completion;



/**
Schedules an appointment with a provider on a specified date using a past visit. Reminder options are available for both the consumer and provider.

@discussion The server can send an optional reminder email to the provider and the consumer about the appointment. The email can be sent at different time intervals provided by AWSDKReminderOption.

@note When the visit parameter is non-NULL, this method will perform a scheduled visit for the past failed visit. The failed visit must have one of the following dispositions:
AWSDKVisitDispositionConsumerCanceled, AWSDKVisitDispositionConsumerDisconnected, AWSDKVisitDispositionDeleted, AWSDKVisitDispositionProviderResponseTimeout,
AWSDKVisitDispositionProviderDisconnected, AWSDKVisitDispositionProviderCanceled, AWSDKVisitDispositionExpired

@param provider                AWSDKProvider to have the appointment with.
@param practice                AWSDKPractice that the provider belongs to.
@param schedule                AWSDKSchedule representing the time to schedule for the appointment. This object must be fetched from a provider's calendar by calling [AWSDKProvider
fetchAvailableAppointmentsOnDate:withCompletion:] .
@param phoneNumber             NSString representing an optional phone number to update on the consumer's profile in case the provider needs to contact or callback the consumer.
@param consumerReminderOption  AWSDKReminderOption representing when the server should send a reminder to the consumer prior to the appointment.
@param providerReminderOption  AWSDKReminderOption representing when the server should send a reminder to the provider prior to the appointment.
@param visit                   AWSDKVisit representing a visit in the past that the consumer wants to use as basis of the new scheduled visit.
@param completion              GenericCompletionBlock containing _TRUE_ if the appointment was successfully scheduled, otherwise _FALSE_ and an NSError explaining any error cases.

Error Codes
@exception AWSDKErrorCodeVisitSchedulingFailure   The appointment schedule is already taken by another appointment.
@exception AWSDKErrorCodeVisitInvalidDisposition   The visit doesn't have a valid disposition.

@since 5.2.0
*/
- (void)scheduleAppointmentWithProvider:(nonnull id<AWSDKProvider>)provider
                             inPractice:(nonnull id<AWSDKPractice>)practice
                           withSchedule:(nonnull id<AWSDKSchedule>)schedule
                        withPhoneNumber:(nullable NSString *)phoneNumber
             withConsumerReminderOption:(nonnull id<AWSDKReminderOption>)consumerReminderOption
             withProviderReminderOption:(nonnull id<AWSDKReminderOption>)providerReminderOption
                          withPastVisit:(nullable id<AWSDKVisit>)visit
                         withCompletion:(nullable GenericCompletionBlock)completion;
     
/**
 Fetches an object indicating the consumer's readiness status for their next visit

 @param completion AppointmentReadinessCompletionBlock containing the AWSDKAppointmentReadiness object

 @since 3.1.0
 */
- (void)fetchAppointmentReadinessStatusWithCompletion:(nonnull AppointmentReadinessCompletionBlock)completion;

#pragma mark - Secure Messages
/**
 @name Secure Messages
 */

/**
 Fetches the inbox messages folder for the consumer.

 @discussion By default the last 25 inbox messages are sent without provided options.

 @param options     Optional AWSDKMessageFetchOptions, otherwise default options will be used if _nil_.
 @param completion  MessageFolderCompletionBlock containing the AWSDKMessageFolderInbox or an NSError detailing failure reasons.

 @since 1.0.0
 */
- (void)fetchMessageInboxWithOptions:(nullable AWSDKMessageFetchOptions *)options completion:(nonnull MessageFolderCompletionBlock)completion;

/**
 Fetches the sent messages folder for the consumer.

 @discussion By default the last 25 sent messages are sent without provided options.

 @param options     Optional AWSDKMessageFetchOptions, otherwise default options will be used if _nil_.
 @param completion  MessageFolderCompletionBlock containing the AWSDKMessageFolderSent or an NSError detailing failure reasons.

 @since 1.0.0
 */
- (void)fetchSentMessageFolderWithOptions:(nullable AWSDKMessageFetchOptions *)options completion:(nonnull MessageFolderCompletionBlock)completion;

/**
 Get a specific AWSDKInboxMessageDetails for a given messageId.

 @param messageId  NSString id of the secure "message" passed from the server after receiving a notification.
 @param completion InboxMessageDetailsCompletionBlock containing the AWSDKInboxMessageDetails object for the associated id or an NSError detailing failure reason.

 @since 2.1.0
 */
- (void)getMessageWithId:(nonnull NSString *)messageId completion:(nonnull InboxMessageDetailsCompletionBlock)completion;

/**

 Fetches all contacts the consumer is allowed to send messages to.

 @param completion ContactsCompletionBlock containing an NSArray of AWSDKContact representing users the consumer may send messages to, or an NSError with any error explanations.

 @since 1.0.0
 */
- (void)fetchMessageContactsWithCompletion:(nonnull ContactsCompletionBlock)completion;

/**
 Attempts to send a given message draft.

 @param draft      The AWSDKMessageDraft to send.
 @param completion GenericCompletionBlock containing _TRUE_ if the message was successfully sent, otherwise _FALSE_ and an NSError if anything went wrong.

 @since 1.0.0
 */
- (void)sendMessage:(nonnull id<AWSDKMessageDraft>)draft withCompletion:(nullable GenericCompletionBlock)completion;

#pragma mark - Past Visits
/**
 @name Past Visits
 */

/**
 Fetches the providers that the consumer has previously had a visit with.

 @param maxResults NSNumber for max results to return in the completion block. If this is _nil_ or 0, the default value will be used.
 @param completion ProviderResultsCompletionBlock containing an NSArray of AWSDKProvider objects, NSError if anything went wrong.

 @since 2.1.0
 */
- (void)fetchPastProvidersWithMaxResults:(nullable NSNumber *)maxResults withCompletion:(nonnull ProviderResultsCompletionBlock)completion;

/**
 Fetches a list of reports for the consumer's past visits.

 @param date          Optional NSDate to fetch visits that have occurred since the given date
 @param scheduled     BOOL representing if you would like to return only scheduled visit reports. If YES, only reports from scheduled visits will be returned. If NO, all visit reports will be
 returned.
 @param completion    VisitReportsCompletionBlock containing an NSArray of AWSDKVisitReport objects, or an NSError with any failures.

 @note fetchVisitReportsSinceDate:completion: was renamed to fetchVisitReportsSinceDate:completion: as of 2.1.0. This method will only fetch visits with the disposition AWSDKVisitDispositionCompleted.

 @since 4.1.0
 */
- (void)fetchVisitReportsSinceDate:(nullable NSDate *)date scheduledOnly:(BOOL)scheduled completion:(nonnull VisitReportsCompletionBlock)completion;

/**
 Fetches a list of reports for the consumer's past visits.

 @param date          Optional NSDate to fetch visits that have occurred since the given date
 @param completed  BOOL representing if you would like to return only visits with the AWSDKVisitDispositionCompleted disposition. If NO, visits with AWSDKVisitDispositionCompleted,
 AWSDKVisitDispositionExpired, and AWSDKVisitDispositionDeleted disposition will be returned.
 @param scheduled     BOOL representing if you would like to return only scheduled visit reports. If YES, only reports from scheduled visits will be returned. If NO, all visit reports will be
 returned.
 @param completion    VisitReportsCompletionBlock containing an NSArray of AWSDKVisitReport objects, or an NSError with any failures.

 @note fetchVisitReportsSinceDate:completion: was renamed to fetchVisitReportsSinceDate:completion: as of 2.1.0.

 @since 4.2.0
 */
- (void)fetchVisitReportsSinceDate:(nullable NSDate *)date completedOnly:(BOOL)completed scheduledOnly:(BOOL)scheduled completion:(nonnull VisitReportsCompletionBlock)completion;

/**
 Gets a specific AWSDKVisitReportSummary for a given visit id

 @param visitId      NSString id of the associated visit. This is sent by the server with a notification.
 @param completion   VisitReportSummaryCompletionBlock containing an AWSDKVisitReportSummary object for the associated id, or an NSError with any failures.

 @since 2.1.0
 */
- (void)getVisitReportSummaryWithId:(nonnull NSString *)visitId completion:(nonnull VisitReportSummaryCompletionBlock)completion;

/**
 Gets a specific PDF as NSData for a given visit id.

 @param visitId        NSString id of the associated visit. This is sent by the server with a notification.
 @param completion     DataResultCompletionBlock containing the PDF for the visit as NSData for the associated id, or an NSError with any failures.

 @since 2.1.0
 */
- (void)getVisitReportPDFWithId:(nonnull NSString *)visitId completion:(nonnull DataResultCompletionBlock)completion;

/**
 Fetches a specific visit given visit id.

 @param visitId        NSString id of the associated visit.
 @param completion     VisitCompletionBlock containing the visit as an AWSDKVisit for the associated id, or an NSError with any failures.

 @since 4.3.0
 */
- (void)fetchVisitWithId:(nonnull NSString *)visitId completion:(nonnull VisitCompletionBlock)completion NS_SWIFT_NAME(fetchVisitWithId(visitId:completion:));

/**
 Fetches a specific visit given source id.

 @param sourceId       NSString visit source id of the associated visit. The source id is an identifier generated outside of the American Well telehealth platform.
 @param completion     VisitCompletionBlock containing the visit as an AWSDKVisit for the associated id, or an NSError with any failures.

 @since 4.3.0
 */
- (void)fetchVisitWithSourceId:(nonnull NSString *)sourceId completion:(nonnull VisitCompletionBlock)completion NS_SWIFT_NAME(fetchVisitWithSourceId(visitId:completion:));

/**
 Fetches the active visit for the given authenticated consumer, if one exists.

 @discussion This will return a visit with the disposition AWSDKVisitDispositionPreVisit or AWSDKVisitDispositionInVisit, depending on whether the consumer was found to be in the provider's waiting room or in an active visit with a provider.

 @param completion     VisitCompletionBlock containing the visit as an AWSDKVisit for the consumer, if applicable, or an NSError with any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeVisitNotFound   An active visit could not be found for the given consumer.

 @since 5.2.0
 */
- (void)fetchActiveVisit:(nonnull VisitCompletionBlock)completion NS_SWIFT_NAME(fetchActiveVisit(completion:));

#pragma mark - SpeedPass
/**
 @name SpeedPass
 */

/**
 Fetches a SpeedPass for a visit with the given provider.

 @discussion If the consumer is not eligible for a SpeedPass with the given provider, the SpeedPass param will be nil and the NSError will reflect the ineligibility.

 @note The consumer is eligible for SpeedPass if the consumer or one of the consumer's dependents had entered the given provider's waiting room within the configured threshold.

 @param provider The provider that the desired SpeedPass is for
 @param completion SpeedPassCompletionBlock containing the SpeedPass, if eligible, or an NSError describing ineligibility or network error.

 Potential Error Codes
 @exception AWSDKErrorCodeIneligibleForSpeedPass  The consumer is not eligible to use SpeedPass for a visit with this provider.

 @since 4.1.0
 */
- (void)fetchSpeedPassForProvider:(nonnull id<AWSDKProvider>)provider completion:(nonnull SpeedPassCompletionBlock)completion;

/**
 Fetches a SpeedPass for a visit with the given OnDemandSpecialty.

 @discussion If the consumer is not eligible for a SpeedPass with the given OnDemandSpecialty, the SpeedPass param will be nil and the NSError will reflect the ineligibility.

 @note The consumer is eligible for SpeedPass if the consumer or one of the consumer's dependents had entered the waiting room of a provider with the given OnDemandSpecialty, within the configured
 threshold.

 @param specialty The OnDemandSpecialty that the desired SpeedPass is for
 @param completion SpeedPassCompletionBlock containing the SpeedPass, if eligible, or an NSError describing ineligibility or network error.

 Potential Error Codes
 @exception AWSDKErrorCodeIneligibleForSpeedPass  The consumer is not eligible to use SpeedPass for a visit with this OnDemandSpecialty.

 @since 4.1.0
 */
- (void)fetchSpeedPassForSpecialty:(nonnull id<AWSDKOnDemandSpecialty>)specialty completion:(nonnull SpeedPassCompletionBlock)completion;

#pragma mark - Dependents
/**
 Fetches a list of dependents associated with the specified consumer.

 @param completion      ConsumerResultsCompletionBlock containing an array of zero or more AWSDKConsumer dependents, otherwise _nil_ if there was an error, and an optional NSError describing
 anything that went wrong.

 @since 4.1.0
 */
- (void)fetchDependentsWithCompletion:(nonnull ConsumerResultsCompletionBlock)completion;

#pragma mark - Dependent Access Requests
/**
 Fetches dependent access requests.

 @param completion      DependentAccessRequestCompletionBlock containing a AWSDKDependentAccessRequest if the consumer has outstanding access requests, otherwise _nil_ if there was an error, and an
 optional NSError describing anything that went wrong.

 @since 4.1.0
 */
- (void)fetchDependentAccessRequestWithCompletion:(nonnull DependentAccessRequestCompletionBlock)completion;

/**
 Request access to dependents from a guardian.

 @param guardianEmail   NSString representing the email address of the current guardian of the dependent.
 @param completion      GenericCompletionBlock containing _TRUE_ if the dependent access request was successfully sent, otherwise _FALSE_ and an NSError explaining the failure.

 @since 4.1.0
 */
- (void)requestDependentAccessFromGuardianEmail:(nonnull NSString *)guardianEmail completion:(nullable GenericCompletionBlock)completion;

#pragma mark - Device Integration
/**
 Adds exam data to a device integration.

 @param request The populated request object containing the exam data and associated AWSDKVisit.
 @param completion DeviceIntegrationCompletionBlock containing the resulting AWSDKDeviceIntegration record and exam data.

 @since 4.3.0
 */
- (void)addDeviceIntegrationData:(nonnull AWSDKDeviceIntegrationRequest *)request completion:(nullable DeviceIntegrationCompletionBlock)completion;

#pragma mark - Find First Available Requests

/**
 Cancels the Find First Available request in progress.

 @param completion   GenericCompletionBlock will return a boolean to indicate the success of the method and an NSError explaining what went wrong.

 Potential Error Codes
 @exception AWSDKErrorCodeValidationRequiredParameterMissing    Required missing parameter.
 @exception AWSDKErrorCodeFindFirstAvailableCannotCancel        Cannot cancel because no request is active.

 @since 4.3.0
 */
- (void)cancelFindFirstAvailableRequest:(nullable GenericCompletionBlock)completion;

#pragma mark - Convenience Methods

/**
 Returns _TRUE_ if the consumer is a dependent and has a parent consumer, otherwise _FALSE_ if not a dependent.

 @return _TRUE_ if a dependent, otherwise _FALSE_ if not a dependent.

 @since 3.0.0
 */
- (BOOL)isDependent;

@end
