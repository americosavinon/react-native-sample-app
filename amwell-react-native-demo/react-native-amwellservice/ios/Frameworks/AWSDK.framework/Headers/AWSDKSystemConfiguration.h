//
//  SystemConfiguration.h
//
//  Created by Calvin Chestnut on 8/31/15.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 An enum describing how the American Well telehealth platform handles middle names

 - AWSDKConsumerMiddleNameHandlingNone: Middle names are not accepted and will be ignored
 - AWSDKConsumerMiddleNameHandlingInitial: Middle names are expected to be provided as a single character
 - AWSDKConsumerMiddleNameHandlingFullName: Middle names are expected to be provided in full

 @since 4.0.0
 */
typedef NS_ENUM(NSInteger, AWSDKConsumerMiddleNameHandling) {
    /**
     Middle names are not accepted and will be ignored
     @since 4.0.0
     */
    AWSDKConsumerMiddleNameHandlingNone,
    /**
     Middle names are expected to be provided as a single character
     @since 4.0.0
     */
    AWSDKConsumerMiddleNameHandlingInitial,
    /**
     Middle names are expected to be provided in full
     @since 4.0.0
     */
    AWSDKConsumerMiddleNameHandlingFullName
};

@protocol AWSDKLanguage;

/**
 Configuration options protocol on the American Well telehealth platform.

 @discussion Only some configurations can be changed within this class. Others are changed by the system administrator and are reflected here.

 @since 2.0.0
 */
@protocol AWSDKSystemConfiguration <AWSDKDataObject>

#pragma mark - Configuration Setters
/**
 @name Configuration Setters
 */

/**
 Method used to set the "callback the provider via phone feature" (a feature of Interactive Voice Response) as enabled or disabled.

 @discussion If a consumer and provider get disconnected during a visit and the consumer is unable to reconnect to the provider, the AWSDKVisitConsoleViewController can present an option to talk with
 the provider via phone. If selected, the visit will end and the consumer will be called at the [AWSDKVisitContext callbackNumber]. The provider and the consumer can then finish their visit within the
 phone conference.

 @param enabled BOOL set to _TRUE_ to presents the options for the consumer to talk to the provider via phone or _FALSE_ to hide this feature.

 @since 2.1.0
 */
+ (void)setCallbackViaPhoneEnabled:(BOOL)enabled;

/**
 Method used to set whether or not the refresh and invite guest buttons on the video console are hidden when disabled or visible when disabled.

 @param hidden BOOL set to _TRUE_ to hide the refresh and invite guest buttons on the video console or _FALSE_ to only disable the buttons.

 @since 2.1.2
 */
+ (void)setRefreshAndGuestButtonHiddenWhenDisabled:(BOOL)hidden;

/**
 Method used to determine whether the device vibrates or not when joining a visit.

 @param enabled BOOL set to _TRUE_ to vibrate the device when joining a visit or _FALSE_ to disable this feature.

 @since 3.0.0
 */
+ (void)setVibrateOnVisitJoinEnabled:(BOOL)enabled;

/**
 Method used to determine whether or not a sound plays when joining a visit.

 @param enabled BOOL set to _TRUE_ to play a sound when joining a visit or _FALSE_ to disable this feature.

 @since 3.0.0
 */
+ (void)setSoundOnVisitJoinEnabled:(BOOL)enabled;

/**
 Method to set the path to a sound file to play when joining a visit.

 @discussion When set and the configuration to play a sound when joining a visit is enabled the sound will play. If the path is invalid or the configuration
    to play a sound when joining a visit is disabled no sound will play. The audio file must adhere to the following requirements:

    No longer than 30 seconds in duration, in linear PCM or IMA4 (IMA/ADPCM) format, and packaged in a .caf, .aif, or .wav file

    In addition the sound will play at with the following restrictions:

    Sounds play at the current system audio volume, and the sound is played locally on the device speakers

 @param path NSString representing the path to the audio file.

 @since 3.0.0
 */
+ (void)setPathToVisitJoinSound:(nonnull NSString *)path;

/**
 Updates the SDK preferred locale for display strings to be shown in the expected language.

 @discussion use supportedLocales to retrieve the locales supported by the SDK.

 @param locale     NSLocale representing the desired locale for the SDK.
 @return  _TRUE_ if the SDK supports the locale and sets it successfully, otherwise _FALSE_ .

 @since 2.0.0
 */
+ (BOOL)setPreferredLocale:(nonnull NSLocale *)locale;

#pragma mark - Configuration Getters

#pragma mark - Feature Toggles
/**
 @name Configuration Getters
 */

/**
 Returns a BOOL value indicating if the "callback the provider via phone feature" (a feature of Interactive Voice Response) is enabled.

 @note By default, this value is _FALSE_ and IVR is disabled.

 @discussion If _TRUE_, the consumer will be prompted to "Talk via Phone" if disconnected from the visit for an extended duration. If _FALSE_, the consumer will not be presented this option. If a
 consumer and provider get disconnected during a visit and the consumer is unable to reconnect to the provider, the AWSDKVisitConsoleViewController can present an option to talk with the provider via
 phone. If selected, the visit will end and the consumer will be called at the [AWSDKVisitContext callbackNumber]. The provider and the consumer can then finish their visit within the phone
 conference.

 @return _TRUE_ if the IVR feature is available for the consumer or _FALSE_ if the IVR feature is hidden.

 @since 2.1.0
 */
+ (BOOL)isCallbackViaPhoneEnabled;

/**
 Returns a BOOL value indicating if the refresh and invite guest buttons on the video console are hidden when disabled or visible when disabled.

 @note By default, this value is _FALSE_ and the refresh and invite guest buttons are visible when disabled.

 @since 2.1.2
 */
+ (BOOL)isRefreshAndGuestButtonHiddenWhenDisabled;

/**
 Returns a BOOL value indicating if vibration on joining a visit is enabled.

 @note By default, this value is _FALSE_ and no vibration is made when joining a visit.

 @return _TRUE_ if vibration when joining a visit is enabled or _FALSE_ if no vibration will be made when joining a visit.

 @since 3.0.0
 */
+ (BOOL)isVibrateOnVisitJoinEnabled;

/**
 Returns a BOOL value indicating a sound will play on joining a visit is enabled.

 @note By default, this value is _FALSE_ and no sound is played when joining a visit.

 @return _TRUE_ if a sound will play when joining a visit is enabled or _FALSE_ if no sound will play when joining a visit.

 @since 3.0.0
 */
+ (BOOL)isSoundOnVisitJoinEnabled;

/**
 Indicates if the telehealth platform allows inviting guests to a visit.

 @return BOOL set _TRUE_ if guest are supported in a vist, otherwise _FALSE_ if not supported.

 @since 2.0.0
 */
+ (BOOL)areVideoGuestsSupported;

/**
 Returns whether or not the other topic configuration is enabled. This can be used to show the other
 topic field during intake.

 @return BOOL _TRUE_ if enabled, otherise _FALSE_.

 @since 3.0.0
 */
+ (BOOL)isOtherTopicEnabled;

/**
 Returns whether or not the appointment readiness feature is enabled. This is used to determine if
 device permissions and/or health insurance information is requested before the visit.

 @return BOOL _TRUE_ if enabled, otherwise _FALSE_.
 */
+ (BOOL)isAppointmentReadinessCheckEnabled;

#pragma mark - Compatibility
/**
 Returns an integer value of the max number of guests a consumer can invite to a visit.

 @return The max number of guests as an integer.

 @since 2.0.0
 */
+ (NSInteger)maxVideoGuests;

/**
 Returns an integer value of the largest file size allowed for upload by the server's system configuration.

 @return NSInteger of the largest file size allowed for upload in megabytes.

 @since 2.1.2
 */
+ (NSInteger)allowedFileSize;

/**
 Returns an array of all valid locales for the SDK.

 @return NSArray of NSLocale for all locales supported by the SDK.

 @since 2.0.0
 */
+ (nonnull NSArray<NSLocale *> *)supportedLocales;

/**
 Indicates if a particular property of an AWSDKConsumer is protected by the consumer feed or not.

 @discussion The consumer feed is a method used to populate the American Well telehealth platform with information about consumers and as such is expected to be kept up to date. For this reason the
 system can prevent the consumers from updating certain properties which are populated with the consumer feed. This method allows your app to determine which properties are feed controlled and which
 may be updated by the consumers.

 @param propertyKey Key used to determine which property to check protection value for. All valid keys are defined in AWSDKProtectedPropertyKey.h .

 @return BOOL set _TRUE_ if the property for the propertyKey is protected, otherwise _FALSE_ and can be updated.


 @since 2.0.0
 */
+ (BOOL)isPropertyProtected:(nonnull NSString *)propertyKey;

/**
 Retrieves boolean value for whether or not to show provider ratings.

 @discussion This value represents system configuration on the server. If disabled it indicates that it is not suggested to show provider ratings to in the app. The SDK does not enforce whether
 provider ratings are shown or not, but the value is provided to develop a consistent user experience.

 @return BOOL set _TRUE_ if the system configuration recommends to show provider ratings, otherwise _FALSE_ if recommended to hide provider ratings.

 @since 2.0.0
 */
+ (BOOL)showProviderRatings;

/**
 Returns a boolean that indicates whether or not consumers are able to apply a new service key.

 @discussion This value represents a system configuration. This is not enforced by the SDK and is a recommendation to develop a consistent user experience.

 @return BOOL set _TRUE_ if the system configuration recommends allowing consumers to enter service keys, otherwise _FALSE_ to hide this option.

 @since 2.0.0
 */
+ (BOOL)isServiceKeyCollected;

/**
 Returns a boolean that indicates whether one or more than one country is supported by the  American Well telehealth platform servers.

 @discussion This value could be used to determine if country selection should be displayed when registering a user or updating location and address information.

 @return BOOL set _TRUE_ if the system supports more than one country. _FALSE_ otherwise.

 @since 4.0.0
 */
+ (BOOL)isMultiCountry;

/**
 Returns a boolean that indicates whether or not consumers are able to update insurance subscription information.

 @return BOOL set _TRUE_ if the system configuration allows consumers to update insurance information, otherwise _FALSE_ if not allowed.

 @since 2.0.0
 */
+ (BOOL)isMemberHealthInsuranceCollected;

/**
 Returns an NSArray of valid spoken languages.

 @discussion Used by practice, provider search, and provider details.

 @return NSArray of valid AWSDKLanguage objects.

 @since 2.0.0
 */
+ (nonnull NSArray<id<AWSDKLanguage>> *)validLanguages;

/**
 Returns an NSString code defining the currency in which all SDK money amounts are in.

 @return NSString of the currencyCode (e.g. @"USD").

 @since 2.1.0
 */
+ (nonnull NSString *)currencyCode;

/**
 Returns a BOOL value indicating the server's cancellation preference.

 @discussion Your instance of the American Well telehealth platform may be configured to schedule appointments through an external system. If so, then the American Well telehealth platform can be
 configured to prefer that cancellations be done via that external system, making this flag FALSE. Otherwise, all scheduling is handled through the American Well telehealth platform, so this flag will
 be _TRUE_.

 @return _TRUE_ if the American Well telehealth platform prefers an appointment is cancelled through the American Well telehealth platform, _FALSE_ if an external cancellation process is preferred.
 @see AWSDKAppointment

 @since 3.1.0
 */
+ (BOOL)isCancelAppointmentEnabled;

/**
 Optional text to display when the ability to cancel an appointment within the American Well telehealth platform is not preferred.

 @discussion Typically, this text would inform the consumer of the alternate method to cancel an appointment.

 @return NSString of the cancelAppointmentDisabledText, nil if none.

 @since 3.1.0
 */
+ (nullable NSString *)cancelAppointmentDisabledText;

/**
 An enum describing how middle names should be collected and handled.

 @since 4.0.0
 */
@property (class, readonly) AWSDKConsumerMiddleNameHandling middleNameHandling;

/**
 A BOOL indicating if the electronic fax feature is enabled.

 @since 4.1.0
 */
@property (class, readonly) BOOL isEfaxEnabled;

/**
 A BOOL indicating if the SpeedPass feature is enabled.

 @since 4.1.0
 */
@property (class, readonly) BOOL isSpeedPassEnabled;

/**
 A BOOL indicating if the Dependent Linking feature is enabled.

 @since 4.1.0
 */
@property (class, readonly) BOOL isDependentLinkingEnabled;

/**
 The set of special characters that can appear in a password.

 @since 4.1.0
 */
@property (class, nonatomic, readonly, nullable) NSString *specialCharacterSetAllowedInPassword;

/**
 The minimum number of special characters that must appear in a password.

 @since 4.1.0
 */
@property (class, readonly) NSInteger minimumNumberOfSpecialCharactersInPassword;

/**
 The regular expression that can determine if a password is valid. This can be used to perform password validation in the client.

 @since 4.1.0
 */
@property (class, readonly, nullable) NSString *passwordRegularExpression;

/**
 The minimum valid length of a password.

 @since 4.1.0
 */
@property (class, readonly) NSInteger minPasswordLength;

/**
 The maximum valid length of a password.

 @since 4.1.0
 */
@property (class, readonly) NSInteger maxPasswordLength;

/**
 If TRUE the password must contain at least one letter.

 @since 4.1.0
 */
@property (class, readonly) BOOL passwordMustContainLetters;

/**
 If TRUE the password must contain at least one number.

 @since 4.1.0
 */
@property (class, readonly) BOOL passwordMustContainNumbers;

/**
 Localized message that says the password must not contain invalid special characters.

 @since 4.1.0
 */
@property (class, readonly, nullable) NSString *passwordContainsInvalidCharactersMessage;

/**
 Localized message stating that a password must contain valid special characters. This message contains the list of valid special characters, as well as the number of special characters required for
 creating a password. This text can be used to guide users when they are creating passwords.

 @since 4.1.0
 */
@property (class, readonly, nullable) NSString *passwordRequiresSpecialCharactersMessage;

/**
 Localized message that says the password must be no greater than a certain length.

 @since 4.1.0
 */
@property (class, readonly, nullable) NSString *passwordTooLongMessage;

/**
 Localized message that says the password must be at least a certain length.

 @since 4.1.0
 */
@property (class, readonly, nullable) NSString *passwordTooShortMessage;

/**
 Localized message that says the password must contain at least one letter.

 @since 4.1.0
 */
@property (class, readonly, nullable) NSString *passwordRequiresLettersMessage;

/**
 Localized message that says the password must contain at least one number.

 @since 4.1.0
 */
@property (class, readonly, nullable) NSString *passwordRequiresNumbersMessage;

/**
 The message topics that are available for use during secure messaging

 @since 4.3.0
 */
@property (class, readonly, nullable) NSArray<id<AWSDKMessageTopic>> *messageTopics;

/**
 The health plans that are available for use during subscription registration

 @since 4.3.0
 */
@property (class, readonly, nullable) NSArray<id<AWSDKHealthPlan>> *healthPlans;

/**
 A BOOL indicating whether to show the option to send visit summaries.

 @since 5.0.0
 */
@property (class, readonly) BOOL showOptionToSendVisitSummary;

/**
 The customer support phone number with the server configured locale specific format.

 @since 5.0.0
 */
@property (class, readonly, nullable) NSString *formattedCustomerSupportPhoneNumber;

@end

/**
 Configuration options on American Well's telehealth platform.

 @discussion Only some configurations can be changed within this class. Others are changed by the system administrator and are reflected here.

 @since 2.0.0
 */
@interface AWSDKSystemConfiguration : AWSDKDataObject <AWSDKSystemConfiguration>
#pragma mark - Appledoc
+ (void)setCallbackViaPhoneEnabled:(BOOL)enabled;

+ (void)setRefreshAndGuestButtonHiddenWhenDisabled:(BOOL)hidden;

+ (void)setVibrateOnVisitJoinEnabled:(BOOL)enabled;

+ (void)setSoundOnVisitJoinEnabled:(BOOL)enabled;

+ (void)setPathToVisitJoinSound:(nonnull NSString *)path;

+ (BOOL)setPreferredLocale:(nonnull NSLocale *)locale;

+ (BOOL)isCallbackViaPhoneEnabled;

+ (BOOL)isRefreshAndGuestButtonHiddenWhenDisabled;

+ (BOOL)isVibrateOnVisitJoinEnabled;

+ (BOOL)isSoundOnVisitJoinEnabled;

+ (BOOL)areVideoGuestsSupported;

+ (BOOL)isOtherTopicEnabled;

+ (BOOL)isAppointmentReadinessCheckEnabled;

+ (NSInteger)maxVideoGuests;

+ (NSInteger)allowedFileSize;

+ (nonnull NSArray<NSLocale *> *)supportedLocales;

+ (BOOL)isPropertyProtected:(nonnull NSString *)propertyKey;

+ (BOOL)showProviderRatings;

+ (BOOL)isServiceKeyCollected;

+ (BOOL)isMemberHealthInsuranceCollected;

+ (nonnull NSArray<id<AWSDKLanguage>> *)validLanguages;

+ (nonnull NSString *)currencyCode;

+ (BOOL)isCancelAppointmentEnabled;

+ (nullable NSString *)cancelAppointmentDisabledText;
#pragma mark -
@end
