//
//  AWSDKDependentEnrollmentForm.h
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

#import <AWSDK/AWSDKDependentDemographicForm.h>

@protocol AWSDKConsumer;

/**
 Protocol used to register a dependent.

 @since 3.1.0
 */
@protocol AWSDKDependentEnrollmentForm <AWSDKDependentDemographicForm>
#pragma mark - Read-Write Properties
/**
 @name Read-Write Properties
 */

/**
 The associated authenticated parent in the American Well telehealth platform, otherwise _nil_.

 @since 4.1.0
 */
@property (weak, nonatomic, nullable) id<AWSDKConsumer> authenticatedParent;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Method used to specify the dependent has accepted the required privacy policy.

 @since 2.0.0
 */
- (void)setAcceptedPrivacyPolicy;

@end

/**
 Class used to enroll a dependent.

 @note As of 2.0.0, AWSDKDependentEnrollmentForm was renamed to AWSDKDependentEnrollmentForm to inherit from AWSDKForm.

 @since 2.0.0
 */
@interface AWSDKDependentEnrollmentForm : AWSDKDependentDemographicForm <AWSDKDependentEnrollmentForm>
@end
