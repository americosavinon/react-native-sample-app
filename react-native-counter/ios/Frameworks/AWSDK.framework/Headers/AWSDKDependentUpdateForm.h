//
//  AWSDKDependentUpdateForm.h
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

/**
 Class used to update demographics for a dependent.

 @since 3.1.0
 */
@protocol AWSDKDependentUpdateForm <AWSDKDependentDemographicForm>

@end

/**
 Class used to update demographics for a dependent.

 @since 2.0.0
 */
@interface AWSDKDependentUpdateForm : AWSDKDependentDemographicForm <AWSDKDependentUpdateForm>

@end
