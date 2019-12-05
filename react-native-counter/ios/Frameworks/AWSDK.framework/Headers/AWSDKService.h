//
//  AWSDKService.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKURLFeature.h>
#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

// clang-format off
@protocol AWSDKConsumer, AWSDKProviderSearchOptions, AWSDKState, AWSDKLanguage, AWSDKMedication, AWSDKModality, AWSDKPlatformType, AWSDKModalityVendor;
// clang-format on

/**
 A block that will be called when the consumer's authentication is invalidated

 @param consumerAuthKey The consumerAuthKey of the consumer whose authentication is invalidated

 @since 4.0.0
 */
typedef void (^ConsumerAuthenticationInvalidatedBlock)(NSString *_Nonnull consumerAuthKey);

/**
 Manager protocol for initialization, authentication, and fetching objects outside of a consumer context.

 @since 1.0.0
 */
@protocol AWSDKService

#pragma mark - SDK Initialize Methods
/**
 @name SDK Initialize Methods
 */

/**
 Initializes the SDK given launch parameters.

 @param launchParams    NSDictionary containing launch values for the AWSDK. All values should be stored as a NSString and are represented by the constant keys defined in AWSDKLaunchParamKeys.h
 @param completion      GenericCompletionBlock containing _TRUE_ if the SDK was successfully initialized, otherwise _FALSE_ and an NSError explaining the failure.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidClientKey   API Key is invalid.
 @exception AWSDKErrorCodeInvalidURL         URL Does not point to valid server.

 @since 1.0.0
 */
+ (void)initializeWithLaunchParams:(nonnull NSDictionary<NSString *, NSString *> *)launchParams completion:(nonnull GenericCompletionBlock)completion;

/**
 Indicates if the SDK has been properly initialized or not.

 @return _TRUE_ if the SDK has been initialized, otherwise _FALSE_ if not initialized.

 @since 1.0.0
 */
+ (BOOL)isInitialized;

#pragma mark - Authentication

/**
 The block that is executed when a consumer's authentication has expired or has been invalidated.

 @note The block provides the consumerAuthKey of the consumer whose authentication has expired or has been invalidated.
 @since 4.0.0
 */
@property (class, nonatomic, nullable, copy) ConsumerAuthenticationInvalidatedBlock authenticationInvalidatedBlock;

#pragma mark - Convenience Launch URL Methods
/**
 @name Convenience Launch URL Methods
 */

/**
 Gets the launch URL stored in the AWSDKService.

 @discussion Requires either setting a launch URL for key kAWSDKLaunchURL when calling initializeWithLaunchParams:completion: or updating with updateLaunchUrl:

 @return NSURL representing the launch URL stored in AWSDKService.

 @since 2.0.0
 */
+ (nullable NSURL *)launchUrl;

/**
 Sets the launch URL for AWSDKService.

 @param url NSURL representing the launch URL for the app to set for AWSDKService.

 @note Calling this method does not update the server configuration for the SDK launch URL and scheme. This is to only store the launchURL in AWSDKService.

 @since 2.0.0
 */
+ (void)updateLaunchUrl:(nullable NSURL *)url;

/**
 Determine what feature a URL is trying to launch.

 @param url The NSURL for a potential AWSDKURLFeature.

 @return AWSDKURLFeature enum representing the supported feature for the URL.

 @since 2.0.0
 */
+ (AWSDKURLFeature)supportedFeatureForUrl:(nonnull NSURL *)url;

#pragma mark - Misc Settings

/**
 Toggles the certificate pinning behavior of all network calls performed by the AWSDKService.

 @note The AWSDKService will search recursively through the NSBundle's mainBundle for all .cer files and add them to the collection of pinned certificates that will be validated against.

 @discussion For more information on certificate pinning and it's strengths, visit https://www.owasp.org/index.php/Certificate_and_Public_Key_Pinning

 @param enabled The desired state of the AWSDKService's certificate pinning behavior.

 @since 3.1.0
 */
+ (void)setCertificatePinningEnabled:(BOOL)enabled;

/**
 Adds the desired certificate to the set of allowed certificates

 @note Adding a duplicate certificate will have no effect

 @param certificate The certificate to be added

 @since 3.2.1
 */
+ (void)addCertificateToPinnedCertificates:(nonnull NSData *)certificate;

/**
 Sets the amount of time in seconds the visit must be timed out before it is ended automatically. Defaults to 0.

 @note If this value is set to 0, the visit will not have a client side timeout.
 @discussion If this feature is enabled, it is recommended that you set this value no lower than 2 minutes. There are a few cases under poor or inconsistent network conditions where normal video
 functionality could exceed the 2 minute timeout.

 @param timeout The duration in seconds before automatically ending a video visit.

 @since 3.1.0
 */
+ (void)setAutomaticVisitEndWithTimeout:(NSInteger)timeout;

/**
 Sets the amount of time in seconds that an ongoing visit will end while the application is in the background.

 @note This prevents the user from backgrounding the application for too long during a visit.

 @param timeout The duration in seconds before automatically ending a visit that is currently in the background.

 @since 3.1.2
 */
+ (void)setAutomaticBackgroundVisitEndWithTimeout:(NSTimeInterval)timeout;

/**
 Sets the desired background visit behavior. If this value is NO, video visits will be paused when the application enters the background. Defaults to YES.

 @note Your application must have the "audio" Background Mode entitlement in order for visits to continue in the background. This value has no effect if your application does not contain the
 aforementioned entitlement.

 @since 4.0.0
 */
@property (class, nonatomic) BOOL backgroundVisitsEnabled;

/**
 Sets the desired polling interval (in seconds) for AWSDKVisits.

 @note The default value of this property is 5 seconds.

 @since 4.1.1
 */
@property (class, nonatomic) NSTimeInterval visitPollingInterval;

/**
 Sets the desired polling interval for guests (in seconds) for guest AWSDKVisits.

 @note The default value of this property is 15 seconds. This value should be less frequent than visitPollingInterval.

 @since 4.1.1
 */
@property (class, nonatomic) NSTimeInterval guestVisitPollingInterval;

/**
 Sets the desired polling interval (in seconds) for Find First Available status updates.

 @note The default value of this property is 3 seconds.

 @since 4.1.1
 */
@property (class, nonatomic) NSTimeInterval findFirstAvailablePollingInterval;

/**
 Sets the desired polling interval (in seconds) for Visit Cost status updates.

 @note The default value of this property is 3 seconds.

 @since 4.1.1
 */
@property (class, nonatomic) NSTimeInterval costPollingInterval;

/**
 Sets the desired polling interval (in seconds) for Health Plan Eligibility status updates.

 @note The default value of this property is 3 seconds.

 @since 4.1.1
 */
@property (class, nonatomic) NSTimeInterval healthPlanEligibilityPollingInterval;

/**
 Sets the desired maximum retries for Find First Available status updates.

 @note The default value of this property is 3 retries.

 @since 4.1.1
 */
@property (class, nonatomic) int findFirstAvailableRetryLimit;

/**
 Sets the desired maximum retries for Health Plan Eligibility status updates.

 @note The default value of this property is 5 retries.

 @since 4.1.1
 */
@property (class, nonatomic) int healthPlanEligibilityRetryLimit;

/**
 Boolean used to prevent Update Consumer, Get Visit Context and Create Visit from propagating the consumer's account information to dependents.

 @note The default value of this property is NO.

 @since 4.3.0
 */
@property (class, nonatomic) BOOL accountPropagationDisabled;

/**
 Array of Modality options for visit communications

 @since 4.3.0
 */
@property (class, nonatomic, nullable, readonly) NSArray<id<AWSDKModality>> *availableModalities;

/**
 Array of AWSDKPlatformType platform types or Operating Systems supported by the American Well telehealth platform.

 @since 4.3.0
 */
@property (class, nonatomic, nullable, readonly) NSArray<id<AWSDKPlatformType>> *platformTypes;

#pragma mark - Debug Configurations Methods
/**
 @name Debug Configurations Methods
 */

/**
 Turn on debug mode.

 @discussion Debug mode allows calls to unverified https servers. Debug mode must be enabled for any server configuration overrides such as setConsumerMiddleInitialCollectedOverride or
 setConsumerAddressCollectedOverride to be enabled. Debug mode also enables a more detailed set of logs around the video console.

 @since 1.0.0
 */
+ (void)enableDebugMode;

/**
 Turn off debug mode.

 @discussion Debug mode allows calls to unverified https servers. Debug mode must be enabled for any server configuration overrides such as setConsumerMiddleInitialCollectedOverride or
 setConsumerAddressCollectedOverride to be enabled. Debug mode also enables a more detailed set of logs around the video console.

 @since 1.0.0
 */
+ (void)disableDebugMode;

/**
 Check if debug mode is enabled.

 @discussion Debug mode allows calls to unverified https servers. Debug mode must be enabled for any server configuration overrides such as setConsumerMiddleInitialCollectedOverride or
 setConsumerAddressCollectedOverride to be enabled. Debug mode also enables a more detailed set of logs around the video console.

 @return _TRUE_ if debug mode is enabled, otherwise _FALSE_ if debug mode is disabled.

 @since 1.0.0
 */
+ (BOOL)debugEnabled;

/**
 Used in debug mode to force AWSDK to collect middle initial during enrollment.

 @note Debug mode must be enabled for the server configuration override to be enabled.

 @param middleInitialOverride set _TRUE_ if middle initial should be collected during enrollment, otherwise _FALSE_ to use the server's configuration.

 @since 1.0.0
 */
+ (void)setConsumerMiddleInitialCollectedOverride:(BOOL)middleInitialOverride;

/**
 Used in debug mode to force AWSDK to collect address during enrollment.

 @note Debug mode must be enabled for the server configuration override.

 @param addressOverride set _TRUE_ if address should be collected during enrollment, otherwise _FALSE_ to use the server's configuration.

 @since 1.0.0
 */
+ (void)setConsumerAddressCollectedOverride:(BOOL)addressOverride;

/**
Used to initiate an IVR call between a Consumer and a Provider at anytime.

 @param consumer The consumer that will initiate the IVR call.
 @param provider The provider that will be contacted for the IVR call.
 @param overridePhoneNumber A phone number that is used instead of the consumer's phone number on record.
 @param completion Returns a boolean value indicating success and an NSError explaining any failures.

 @since 4.1.0
 */
+ (void)initiateIVRCallBetweenConsumer:(nonnull id<AWSDKConsumer>)consumer
                           andProvider:(nonnull id<AWSDKProvider>)provider
                   overridePhoneNumber:(nullable NSString *)overridePhoneNumber
                            completion:(nonnull GenericCompletionBlock)completion;

/**
 Fetches a list of trackers with names matching a given search string.

 @discussion Search is case-insensitive.

 @param searchString NSString representing the template name to search trackers.
 @param completion   TrackerTemplatesCompletionBlock containing an NSArray of AWSDKTrackerTemplate objects with a name matching the searchString, otherwise an NSError explaining any failures.

 @since 4.3.0
 */
+ (void)searchTrackerTemplatesWithString:(nullable NSString *)searchString completion:(nonnull TrackerTemplatesCompletionBlock)completion;

/**
 Fetches supported AWSDKPlatformType objects supported by the American Well telehealth platform

 @param completion PlatformTypesCompletionBlock will return the array of AWSDKPlatformTypes items or an NSError to be forwarded back to the client

 @since 4.3.0
 */
+ (void)fetchPlatformTypes:(nonnull PlatformTypesCompletionBlock)completion;

@end

/**
 Manager for initialization, authentication, and fetching objects outside of a consumer context.
 @since 1.0.0
 */
@interface AWSDKService : NSObject <AWSDKService>
#pragma mark - Appledoc
+ (void)initializeWithLaunchParams:(nonnull NSDictionary<NSString *, NSString *> *)launchParams completion:(nonnull GenericCompletionBlock)completion;
+ (BOOL)isInitialized;
+ (nullable NSURL *)launchUrl;
+ (void)updateLaunchUrl:(nullable NSURL *)url;
+ (AWSDKURLFeature)supportedFeatureForUrl:(nonnull NSURL *)url;
+ (void)setCertificatePinningEnabled:(BOOL)enabled;
+ (void)setAutomaticVisitEndWithTimeout:(NSTimeInterval)timeout;
+ (void)enableDebugMode;
+ (void)disableDebugMode;
+ (BOOL)debugEnabled;
+ (void)setConsumerMiddleInitialCollectedOverride:(BOOL)middleInitialOverride;
+ (void)setConsumerAddressCollectedOverride:(BOOL)addressOverride;
+ (void)initiateIVRCallBetweenConsumer:(nonnull id<AWSDKConsumer>)consumer
                           andProvider:(nonnull id<AWSDKProvider>)provider
                   overridePhoneNumber:(nullable NSString *)overridePhoneNumber
                            completion:(nonnull GenericCompletionBlock)completion;
+ (void)searchTrackerTemplatesWithString:(nullable NSString *)searchString completion:(nonnull TrackerTemplatesCompletionBlock)completion;
+ (void)fetchPlatformTypes:(nonnull PlatformTypesCompletionBlock)completion;

#pragma mark -
@end
