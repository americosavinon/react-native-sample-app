//
//  AWSDKServicePrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 4/12/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKService.h>

@class BasicAuthCredentials, AWSDKConsumerAuthentication, I18nService, AWSDKSystemConfiguration, AWSDKDemographicData, AWSDKDemographicForm, AWSDKVisitContext, AWSDKCreditCardType, AWSDKMessageTopic,
    AWSDKProviderType, AWSDKRelationshipToSubscriber, AWSDKHealthPlan, AWSDKConsumer, AWSDKState, AWSDKReminderOption, AWSDKCountry, AWSDKPlatformType, AWSDKModalityVendor, RestLink;

@interface AWSDKService ()

/**
 Singleton accessor for AWSDKService

 @discussion We probably don't want to expose the Singleton instance of AWSDKService, too many private properties and the static methods work well enough. If we ever did want to support multiple
 instances of the SDK pointing to other servers we should just allow the client to

 @return The main AWSDKService instance

 @since 1.0.0
 */
@property (class, nonnull) AWSDKService *sharedInstance;

/**
 Creates a new uninitialized instance of AWSDKService and sets it as the Singleton.

 @discussion Used for testing purposes, run before every test to ensure blank slate

 @since 1.0.0
 */
- (void)clear;

/**
 Single call to load most information the SDK will need about the American Well Telehealth Platform instance.

 @discussion This includes AWSDKState, AWSDKHealthPlan, and AWSDKCreditCardType objects, among others, that are supported by the instance. SystemConfiguration information is also loaded.

 @since 2.1.0
 */
- (void)initializeValuesWithCompletion:(nonnull GenericCompletionBlock)completion;

/**
 Fetches supported AWSDKHealthPlan object to be used for subscriptions

 @discussion This method checks to see if we already have loaded health plans, and kicks off a network request if not. Since we usually will get the health plans during initialization as of 2.1.0, it
 is possible we don't need the fallback and can safely return the stored health plans

 @param completion HealthPlansCompletionBlock will return the array of AWSDKHealthPlan items or an NSError to be forwarded back to the client

 @since 1.0.0
 */
- (void)fetchHealthPlansCompletion:(nonnull HealthPlansCompletionBlock)completion;

/**
 Fetches supported AWSDKMessageTopic objects to be used for new messages

 @discussion This method checks to see if we already have loaded message topics, and kicks off a network request if not. Since we usually will get the message topics during initialization as of 2.1.0,
 it is possible we don't need the fallback and can safely return the stored message topics

 @param completion MessageTopicsCompletionBlock will return the array of AWSDKMessageTopics items or an NSError to be forwarded back to the client

 @since 1.0.0
 */
- (void)fetchMessageTopics:(nonnull MessageTopicsCompletionBlock)completion;

/**
 Fetches supported AWSDKPlatformType objects supported by the American Well telehealth platform

 @param completion PlatformTypesCompletionBlock will return the array of AWSDKPlatformTypes items or an NSError to be forwarded back to the client

 @since 4.3.0
 */
- (void)fetchPlatformTypes:(nonnull PlatformTypesCompletionBlock)completion;

/**
 Retrives a specific AWSDKAppointment with a given engagementID and validates that the given consumer is authorized for the appointment.

 @discussion Typically the enegagementID will be given with a push notification

 @param consumer The consumer who the appointment is for
 @param engagementId The engagementID for the appointment
 @param completion AppointmentCompletionBlock returns the desired Appointment, or an NSError for the client

 @since 2.0.0
 */
- (void)getAppointmentWithConsumer:(nonnull AWSDKConsumer *)consumer engagementId:(nonnull NSString *)engagementId completion:(nonnull AppointmentCompletionBlock)completion;

/**
 Same as above... but with dependents, really don't think this is worth spelling out...
 */
- (void)getAppointmentWithDependent:(nonnull AWSDKConsumer *)dependent engagementId:(nonnull NSString *)engagementId completion:(nonnull AppointmentCompletionBlock)completion;

/**
 Takes a given NSURL and splits the path parameters into a NSDictionary, to make it easier to determine what properties are in a URL.

 @discussion This may be better suited to our NSDictionary extension in the future

 @param url The URL to retrieve parameters from
 @return The NSDictionary containing the keys and values from the URL
 */
+ (nonnull NSDictionary *)paramsFromUrl:(nonnull NSURL *)url;

/**
 Used to retrieve a device token, a unique UUID used to identify this device with the American Well Telehealth Platform

 @discussion If a device token has not been stored in NSUserDefaults, one will be generated and stored there

 @return The stored Device Token
 */
+ (nonnull NSString *)getDeviceToken;

/**
 Used to log key events to the server.

 @param message NSString message to be logged by the server.
 @param parameters NSArray of NSDictionary representation of AWSDKRemoteLogMessageParam with positional parameters in the message.
 @param level NSString representation of AWSDKRmtLogMsgLevel of log message.
 @param completion Returns a boolean value indicating success and an NSError explaining any failures.

 @since 4.2.0
 */
+ (void)logMessage:(nonnull NSString *)message parameters:(nullable NSArray<NSDictionary *> *)parameters level:(nonnull NSString *)level completion:(nullable GenericCompletionBlock)completion;

/**
 Setter for availableModalities.

 @param availableModalities NSArray of AWSDKModality objects.

 @since 4.3.0
 */
+ (void)setAvailableModalities:(nonnull NSArray<id<AWSDKModality>> *)availableModalities;

/**
 The current AWSDKService preferred locale.
 */
@property (nonatomic, nullable) NSLocale *preferredLocale;

/**
 Boolean indicating if the SDK Instance currently has certificate pinning enabled.

 @note If this set to _YES_, all network calls made through the NetworkingService class will adhere to the pinned certificates.
 */
@property BOOL certificatePinningEnabled;

/**
 The duration in seconds before a timed out visit will automatically end.

 @note Defaults to 0. If this value is 0, the visit shall never automatically end. This will always be a positive integer.
 */
@property NSTimeInterval visitTimeoutDuration;

/**
 Sets the desired polling interval (in seconds) for AWSDKVisits.

 @note The default value of this property is 5 seconds.

 @since 4.1.1
 */
@property (nonatomic) NSTimeInterval visitPollingInterval;

/**
 Sets the desired polling interval for guests (in seconds) for AWSDKVisits.

 @note The default value of this property is 15 seconds. This value should be less frequent than visitPollingInterval.

 @since 4.1.1
 */
@property (nonatomic) NSTimeInterval guestVisitPollingInterval;

/**
 Sets the desired polling interval (in seconds) for Find First Available status updates.

 @note The default value of this property is 3 seconds.

 @since 4.1.1
 */
@property (nonatomic) NSTimeInterval findFirstAvailablePollingInterval;

/**
 Sets the desired polling interval (in seconds) for Visit Cost status updates.

 @note The default value of this property is 3 seconds.

 @since 4.1.1
 */
@property (nonatomic) NSTimeInterval costPollingInterval;

/**
 Sets the desired polling interval (in seconds) for Health Plan Eligibility status updates.

 @note The default value of this property is 3 seconds.

 @since 4.1.1
 */
@property (nonatomic) NSTimeInterval healthPlanEligibilityPollingInterval;

/**
 Sets the desired maximum retries for Find First Available status updates.

 @note The default value of this property is 3 retries.

 @since 4.1.1
 */
@property (nonatomic) int findFirstAvailableRetryLimit;

/**
 Sets the desired maximum retries for Health Plan Eligibility status updates.

 @note The default value of this property is 5 retries.

 @since 4.1.1
 */
@property (nonatomic) int healthPlanEligibilityRetryLimit;

/**
 The duration in seconds before a timed out visit will automatically end.

 @note Defaults to 0. If this value is 0, the visit shall never automatically end. This will always be a positive integer.
 */
@property NSTimeInterval backgroundVisitTimeoutDuration;

/**
 Boolean indicating if the SDK Instance is currently in Debug Mode

 @discussion Note, as of now debug mode allows you to use overrides for certain system configuration properties (see below). This functionality can be expanded to potentially provide overrides for
 other SystemConfiguration properties. This was also designed to be used by NetworkingService to determine if we should allow invalid certificates on the American Well Telehealth Platform servers, but
 that part never quite worked...
 */
@property BOOL isDebugMode;

/**
 Boolean used to prevent Update Consumer, Get Visit Context and Create Visit from propagating the consumer's account information to dependents.

 @note The default value of this property is NO.

 @since 4.3.0
 */
@property BOOL accountPropagationDisabled;

/**
 Boolean used to override middleInitialCollected value of SystemConfiguration.

 @discussion Used for unit testing.
 */
@property BOOL middleInitialOverride;

/**
 Boolean used to override addressRequired value of SystemConfiguration.

 @discussion Used for unit testing.
 */
@property BOOL addressOverride;

/**
 NSString value of the stored SDK key used to authenticate the SDK
 */
@property (nonatomic, nonnull) NSString *sdkKey;

/**
 The BundleID of the containing application, to report to the American Well Telehealth Platform
 */
@property (nonatomic, nonnull) NSString *bundleId;

/**
 Property to store the URL that launched the Application, if applicable.

 @discussion This is just a convenience so the client doesn't need to hold onto the LaunchURL while initializeing the SDK and authenticating the Consumer.
 */
@property (nonatomic, nonnull) NSURL *launchUrl;

/**
 Array of ReminderOption options for a Scheduled Appointment
 */
@property (nonatomic, nonnull) NSArray<AWSDKReminderOption *> *reminderOptions;

/**
 Array of States supported by the American Well Telehealth Platform system.

 @discussion Our model allows us to filter this list of states for different purposes depending on what is allowed (for instance if only some states are supported for enrollment), so typically we want
 to share the list of states in context specific areas, giving us an oppertunity to filter.
 */
@property (nonatomic, nonnull) NSArray<AWSDKState *> *states;

/**
 Array of Countries supported by the American Well Telehealth Platform system.
 */
@property (nonatomic, nonnull) NSArray<AWSDKCountry *> *countries;

/**
 Array of Relationship options for a SubscriptionForm
 */
@property (nonatomic, nonnull) NSArray<AWSDKRelationshipToSubscriber *> *relationships;

/**
 Array of CreditCardType options for a PaymentMethodForm
 */
@property (nonatomic, nonnull) NSArray<AWSDKCreditCardType *> *creditCardTypes;

/**
 Array of HealthPlan options for a SubscriptionForm
 */
@property (nonatomic, nonnull) NSArray<AWSDKHealthPlan *> *healthPlans;

/**
 Array of MessageTopic options for a MessageDraft
 */
@property (nonatomic, nonnull) NSArray<AWSDKMessageTopic *> *messageTopics;

/**
 Array of ProviderType options for a Provider Search
 */
@property (nonatomic, nonnull) NSArray<AWSDKProviderType *> *providerTypes;

/**
 Array of Modality options for visit communications
 */
@property (nonatomic, nullable, readwrite) NSArray<id<AWSDKModality>> *availableModalities;

/**
 Array of NSString platform types
 */
@property (nonatomic, nullable, readwrite) NSArray<id<AWSDKPlatformType>> *platformTypes;

/**
 Array of ModalityVendor for visit communications
 */
@property (nonatomic, nullable, readwrite) NSArray<AWSDKModalityVendor *> *modalityVendors;

/**
 SystemConfiguration object to hold configurable information about the American Well Telehealth Platform instance associated with the SDKService
 */
@property (nonatomic, nonnull) AWSDKSystemConfiguration *sysConfig;

@property (nonatomic, nonnull) NSDictionary<NSString *, RestLink *> *links;

@end
