//
//  AWSDKConsumerEnrollmentForm.h
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

#import <AWSDK/AWSDKConsumerDemographicForm.h>

/**
 Protocol used to register a consumer.

 @note  As of 2.0.0, AWSDKConsumerEnrollmentData was renamed to AWSDKConsumerEnrollmentForm to inherit from AWSDKForm.

 @since 3.1.0
 */
@protocol AWSDKConsumerEnrollmentForm <AWSDKConsumerDemographicForm>
#pragma mark - Methods
/**
 @name Methods
 */

/**
 Method to specify that a consumer has accepted the required privacy policy.

 @since 2.0.0
 */
- (void)setAcceptedPrivacyPolicy;

/**
 BOOL specifying whether or not the American Well telehealth platform should send a Welcome Email to the email address included in this form.

 @since 4.2.0
 */
@property (nonatomic, readwrite) BOOL sendWelcomeEmail;

@end

/**
 Class used to register a consumer.

 @note  As of 2.0.0, AWSDKConsumerEnrollmentData was renamed to AWSDKConsumerEnrollmentForm to inherit from AWSDKForm.

 @since 2.0.0
 */
@interface AWSDKConsumerEnrollmentForm : AWSDKConsumerDemographicForm <AWSDKConsumerEnrollmentForm>
@end
