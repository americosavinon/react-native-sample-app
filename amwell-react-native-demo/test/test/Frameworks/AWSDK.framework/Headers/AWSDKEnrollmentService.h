//
//  AWSDKEnrollmentService.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/30/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

// clang-format off
@protocol AWSDKDemographicForm, AWSDKState, AWSDKCountry;
// clang-format on

/**
 Handles Consumer and Dependent enrollment and validation

 @since 3.0.0
 */
@protocol AWSDKEnrollmentService <AWSDKDataObject>

#pragma mark - Configuration Requirements
/**
 @name Configuration Requirements
 */

/**
 Returns a boolean whether or not address is required for enrollment.

 @discussion This is a system configuration set by the server.

 @return BOOL   _TRUE_ if address is required, _FALSE_ otherwise.

 @since 3.0.0
 */
+ (BOOL)isConsumerAddressRequired;

/**
 Returns a boolean whether or not middle initial is collected for enrollment.

 @discussion This is a system configuration set by the server.

 @return BOOL   _TRUE_ if middle initial is collected, _FALSE_ otherwise.

 @since 3.0.0
 */
+ (BOOL)isConsumerMiddleInitialCollected;

#pragma mark - Getters
/**
 @name Getters
 */

/**
 Returns a list of valid states to use for a consumer's address.

 @since 4.0.0
 */
@property (class, nonatomic, nullable, readonly) NSArray<id<AWSDKState>> *addressStates;

/**
 Returns a list of valid states to use for a consumer's enrollment location.

 @since 4.0.0
 */
@property (class, nonatomic, nullable, readonly) NSArray<id<AWSDKState>> *enrollmentStates;

/**
 Returns a list of valid countries.

 @since 4.0.0
 */
@property (class, nonatomic, nullable, readonly) NSArray<id<AWSDKCountry>> *countries;

/**
 Fetches the privacy policy for American Well's telehealth platform. The consumer must accept this policy before enrolling.

 @param completion  StringResultCompletionBlock containing the privacy policy as an string containing HTML and inline style. This string can be presented in a webview.

 @since 3.0.0
 */
+ (void)fetchEnrollmentPrivacyPolicy:(nullable StringResultCompletionBlock)completion;

#pragma mark - Enrollment
/**
 @name Enrollment
 */

/**
 Enrolls a Consumer or Dependent with a given AWSDKDemographicForm.

 @param form        AWSDKConsumerEnrollmentForm or AWSDKDependentEnrollmentForm containing required and optional information about the consumer.
 @param completion  ConsumerResultCompletionBlock containing the new AWSDKConsumer if the consumer is properly enrolled, otherwise _nil_ if there was an error, and an optional NSError describing
 anything that went wrong.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidEnrollmentData                         Enrollment Data is Invalid.
 @exception AWSDKErrorCodeValidationRequiredParameterMissing            Required missing parameter.
 @exception AWSDKErrorCodeInvalidValue                                  Invalid required parameter.
 @exception AWSDKErrorCodeValidationRequiredParameterTooShort           Value is too short.
 @exception AWSDKErrorCodeTooLarge                                      Value is too long.
 @exception AWSDKErrorCodeDateTooEarly                                  Required parameter is too early in time.
 @exception AWSDKErrorCodeDateTooLate                                   Required parameter is too late in time.
 @exception AWSDKErrorCodeInvalidEmail                                  Email address is invalid.
 @exception AWSDKErrorCodeValidationEmailInUse                          Email is already in use.
 @exception AWSDKErrorCodeConsumerTooYoung                              The consumer is too young
 @exception AWSDKErrorCodeConsumerTooOld                                The dependent is too old.
 @exception AWSDKErrorCodeInvalidDemographicData                        One or more properties of the Enrollment Data supplied does not fulfill requirements.

 @discussion
 When enrollConsumerWithForm is successful the NSError object passed into the completion block will be nil. This means no error has occurred and the user or dependent has been enrolled. If the error
 object is not null we can examine its code and userInfo properties to see what happened.

 Errors can be caught in the client when the form and its contents are validated, or on server.  The demographic data that is checked
 include the address, city, state, zip, date of birth, email, first name, last name, password, state of legal residence, and whether the privacy policy has been accepted. If the error is detected on
 the client the code property of the NSError object will be set to AWSDKErrorCodeInvalidDemographicData, and the userInfo dictionary will describe the fields that were invalid. The
 AWSDKValidationErrorsKey maps an item in the userInfo to field names and corresponding error codes that describe the validation failure(s). Additionally NSLocalizedDescription,
 NSLocalizedFailureReason and NSLocalizedRecoverySuggestion may be set.

 For server side errors the code property will vary based on the the server response, and the userInfo dictionary describes the failure. For example a server side error might be insuffcient password
 complexity. The telehealth platform has certain configurable requirements on password complexity. If the password is invalid an error with a AWSDKErrorCodeInvalidValue code will be returned. This
 error will have the password requirements as the NSLocalizedRecoveryOptionsErrorKey. The entries in the userInfo vary depending on the server side error.

 @since 3.0.0
 */
+ (void)enrollConsumerWithForm:(nonnull id<AWSDKDemographicForm>)form completion:(nonnull ConsumerResultCompletionBlock)completion;

/**
 Enrolls a Consumer or Dependent with a given AWSDKDemographicForm.

 @param form            AWSDKConsumerEnrollmentForm or AWSDKDependentEnrollmentForm containing required and optional information about the consumer.
 @param dependentCheck  BOOL specifying whether to perform an existing dependent validation during enrollment.
 @param completion      ConsumerResultCompletionBlock containing the new AWSDKConsumer if the consumer is properly enrolled, otherwise _nil_ if there was an error, and an optional NSError describing
 anything that went wrong.

 @since 4.1.0
 */
+ (void)enrollConsumerWithForm:(nonnull id<AWSDKDemographicForm>)form dependentCheck:(BOOL)dependentCheck completion:(nonnull ConsumerResultCompletionBlock)completion;

@end

/**
 Handles Consumer and Dependent enrollment and validation

 @since 3.0.0
 */
@interface AWSDKEnrollmentService : AWSDKDataObject <AWSDKEnrollmentService>
#pragma mark - Appledoc
+ (BOOL)isConsumerAddressRequired;
+ (BOOL)isConsumerMiddleInitialCollected;
+ (void)fetchEnrollmentPrivacyPolicy:(nullable StringResultCompletionBlock)completion;
+ (void)enrollConsumerWithForm:(nonnull id<AWSDKDemographicForm>)form completion:(nonnull ConsumerResultCompletionBlock)completion;
+ (void)enrollConsumerWithForm:(nonnull id<AWSDKDemographicForm>)form dependentCheck:(BOOL)dependentCheck completion:(nonnull ConsumerResultCompletionBlock)completion;

@end
