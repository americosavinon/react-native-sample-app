//
//  AWSDKConsumerDemographicForm.h
//  AWSDK
//
//  Created by Steven Uy on 8/09/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDemographicForm.h>

// clang-format off
@protocol AWSDKAddress, AWSDKState, AWSDKCountry;
// clang-format on

/**
 Protocol used to register consumers or update consumer demographic data.

 @since 3.1.0
 */
@protocol AWSDKConsumerDemographicForm <AWSDKDemographicForm>

/**
 An enum describing a consumer's potential preference for receiving appointment reminder text messages

 @since 3.1.0
 */
typedef NS_ENUM(NSInteger, AppointmentReminderTextPreference) {
    /**
     Consumer information regarding appointment reminder text preferences has not been communicated
     */
    PreferenceNotSet,
    /**
     Consumer prefers to receive an appointment reminder text
     */
    PreferenceEnabled,
    /**
     Consumer does not want an appointment reminder text
     */
    PreferenceDisabled,
};

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSString representing a user's email 'address'.

 @discussion The string must be formatted as an email 'address'.

 @since 2.0.0
 */
@property (nonatomic, nullable) NSString *email;

/**
 NSString representing a password for a user to authenticate with the American Well telehealth platform.

 @discussion The validation of this field depends on the instance of the telehealth platform, make sure to check validation before sending to the server.

 @since 2.0.0
 */
@property (nonatomic, nullable) NSString *password;

/**
 AWSDKState representing the state a user has legal residence in.

 @since 4.0.0
 */
@property (nonatomic, nullable) id<AWSDKState> stateOfLegalResidence;

/**
 AWSDKCountry representing the country a user has legal residence in.

 @since 4.0.0
 */
@property (nonatomic, nullable) id<AWSDKCountry> countryOfLegalResidence;

/**
 NSString representing a user's unformatted phone number.

 @since 2.0.0
 */
@property (nonatomic, nullable) NSString *phoneNumber;

/**
 AppointmentReminderTextPreference enum representing a consumer's preference to receive appointment reminder text messages. Defaults to PreferenceNotSet.

 @discussion If this value remains PreferenceNotSet, no information regarding the preference will be present in the [AWSDKConsumer updateDemographicsWithForm:withCompletion:] routine.
 @since 3.1.0
 */
@property (nonatomic) AppointmentReminderTextPreference appointmentReminderTextPreference;

/**
 AWSDKAddress representing a user's physical address.

 @since 2.0.0
 */
@property (nonatomic, nullable) id<AWSDKAddress> address;

/**
 NSString representing a non user-facing key to authenticate a user without credentials.

 @since 2.0.0
 */
@property (nonatomic, nullable) NSString *consumerAuthKey;

@end

/**
 Class used to enroll consumers or update consumer demographic data.

 @note This class is only used with consumers, not dependents.

 @since 2.0.0
 */
@interface AWSDKConsumerDemographicForm : AWSDKDemographicForm <AWSDKConsumerDemographicForm>
#pragma mark - Appledoc
@property (nonatomic, nullable) NSString *email;
@property (nonatomic, nullable) NSString *password;
@property (nonatomic, nullable) id<AWSDKState> stateOfLegalResidence;
@property (nonatomic, nullable) id<AWSDKCountry> countryOfLegalResidence;
@property (nonatomic, nullable) NSString *phoneNumber;
@property (nonatomic) AppointmentReminderTextPreference appointmentReminderTextPreference;
@property (nonatomic, nullable) id<AWSDKAddress> address;
@property (nonatomic, nullable) NSString *consumerAuthKey;
#pragma mark -
@end
