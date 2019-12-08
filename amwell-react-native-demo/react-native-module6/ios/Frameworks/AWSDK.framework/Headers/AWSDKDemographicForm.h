//
//  AWSDKDemographicForm.h
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

#import <AWSDK/AWSDKBiologicalSex.h>
#import <AWSDK/AWSDKForm.h>
#import <AWSDK/AWSDKUser.h>

/**
 Protocol used for enrolling or updating a consumer or dependent.

 @since 3.1.0
 */
@protocol AWSDKDemographicForm <AWSDKForm>

#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 NSString representing a user's first name.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *firstName;

/**
 NSString representing a user's middle initial.

 @note The American Well telehealth platform will use only the middle name type that is mentioned in the AWSDKSystemConfiguration.middleNameHandling. Anything other than the type specified will be
 ignored.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *middleInitial;

/**
 NSString representing a user's middle name.

 @note The American Well telehealth platform will use only the middle name type that is mentioned in the AWSDKSystemConfiguration.middleNameHandling. Anything other than the type specified will be
 ignored.

 @since 4.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *middleName;

/**
 NSString representing a user's last name.

 @since 2.0.0
 */
@property (nonatomic, nullable, readwrite) NSString *lastName;

/**
 NSDate representing the user's date of birth.

 @note Since this value will be converted to an ISO 8601 in UTC string representation upon form submission, the desired dateOfBirth must be correctly represented in that format. For example, if you
 use a UIDatePicker, you may set the timeZone of that date picker to be 0 seconds from GMT, which allows you to set this value directly from the chosen date on that picker.

 @since 4.1.0
 */
@property (nonatomic, nullable, readwrite) NSDate *dateOfBirth;

/**
 AWSDKBiologicalSex representing a user's biological sex.

 @note The "gender" term in this SDK is a legacy term that remains in order to maintain consistency throughout the rest of the products both internally and externally.

 @since 4.1.0
 */
@property (nonatomic, readwrite) AWSDKBiologicalSex gender;

/**
 NSString representing a user's source ID.

 @since 3.1.0
 */
@property (copy, nonatomic, nullable, readwrite) NSString *sourceId;

/**
 NSString representing a user's SDK user ID.

 @note This ID is similar in purpose the sourceId, however it is tied to a specific SDK configuration.

 @since 4.2.0
 */
@property (copy, nonatomic, nullable, readwrite) NSString *sdkUserId;

/**
 NSLocale representing the consumer's preferred locale, which determines the language and format the American Well telehealth platform uses for system generated messages.

 @since 4.1.0
 */
@property (nonatomic, readwrite, nullable) NSLocale *preferredLocale;

/**
 NSString representing a consumer's medical record number.

 @since 4.3.0
 */
@property (nonatomic, nullable, readwrite) NSString *mrnId;

/**
 NSTimeZone representing a consumer's timezone.

 @since 4.3.0
 */
@property (nonatomic, nullable, readwrite) NSTimeZone *timeZone;

/**
 NSArray of strings representing a consumer's branding attributes.

 @since 4.4.0
 */
@property (copy, nonatomic, nullable, readwrite) NSArray<NSString *> *brandings;

@end

/**
 Class used for enrolling or updating a consumer or dependent.

 @discussion This class should not be initialized as AWSDKDemographicForm, only the subclasses such as AWSDKConsumerEnrollmentForm should be used.

 @note As of 2.0.0, AWSDKDemographicData was renamed to AWSDKDemographicForm to inherit AWSDKForm.

 @since 2.0.0
 */
@interface AWSDKDemographicForm : AWSDKForm <AWSDKDemographicForm>
#pragma mark - Appledoc
@property (nonatomic, nullable, readwrite) NSString *firstName;
@property (nonatomic, nullable, readwrite) NSString *middleInitial;
@property (nonatomic, nullable, readwrite) NSString *middleName;
@property (nonatomic, nullable, readwrite) NSString *lastName;
@property (nonatomic, nullable, readwrite) NSDate *dateOfBirth;
@property (nonatomic, readwrite) AWSDKBiologicalSex gender;
@property (copy, nonatomic, nullable, readwrite) NSString *sourceId;
@property (copy, nonatomic, nullable, readwrite) NSString *sdkUserId;
@property (nonatomic, nullable, readwrite) NSString *mrnId;
@property (nonatomic, nullable, readwrite) NSLocale *preferredLocale;
@property (nonatomic, nullable, readwrite) NSTimeZone *timeZone;
@property (copy, nonatomic, nullable, readwrite) NSArray<NSString *> *brandings;

#pragma mark -
@end
