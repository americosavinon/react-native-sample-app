//
//  AWSDKConsumerUpdateForm.h
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
 Protocol representing the form used to update consumer demographics.

 @note As of 2.0.0, AWSDKConsumerUpdateData was renamed to AWSDKConsumerUpdateForm to inherit from AWSDKForm.

 @since 3.1.0
 */
@protocol AWSDKConsumerUpdateForm <AWSDKConsumerDemographicForm>

@end

/**
 Class representing the form used to update consumer demographics.

 @note As of 2.0.0, AWSDKConsumerUpdateData was renamed to AWSDKConsumerUpdateForm to inherit from AWSDKForm.

 @since 2.0.0
 */
@interface AWSDKConsumerUpdateForm : AWSDKConsumerDemographicForm <AWSDKConsumerUpdateForm>

@end
