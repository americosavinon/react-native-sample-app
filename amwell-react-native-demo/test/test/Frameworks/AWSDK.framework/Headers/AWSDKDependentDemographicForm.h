//
//  AWSDKDependentDemographicForm.h
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

/**
 Shared protocol to enroll or update demographics for a dependent.

 @note As of 2.0.0, AWSDKDependentDemographicData was renamed to AWSDKDependentDemographicForm to inherit from AWSDKForm.

 @since 3.1.0
 */
@protocol AWSDKDependentDemographicForm <AWSDKDemographicForm>

@end

/**
 Shared class to enroll or update demographics for a dependent.

 @note As of 2.0.0, AWSDKDependentDemographicData was renamed to AWSDKDependentDemographicForm to inherit from AWSDKForm.

 @since 2.0.0
 */
@interface AWSDKDependentDemographicForm : AWSDKDemographicForm <AWSDKDependentDemographicForm>

@end
