//
//  AWSDKEnrollmentServicePrivate.h
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

#import <AWSDK/AWSDKEnrollmentService.h>

/**
 Handles Consumer and Dependent enrollment and validation

 @since 3.0.0
 */
@interface AWSDKEnrollmentService ()

#pragma mark - Singleton
/**
 @name Singleton
 */

/**
 Singleton accessor for AWSDKVisitService.

 @return The main AWSDKVisitService instance

 @since 3.0.0
 */
+ (instancetype)sharedInstance;

#pragma mark - Private Methods
/**
 @name Private Methods
 */

/**
 Sends enrollment request to the American Well Telehealth Platform using information from the AWSDKDemographicForm

 @param data AWSDKDemographicForm containing information about the user to be enrolled
 @param dependentCheck BOOL specifying whether a existing dependent check should be performed when enrolling dependent consumer
 @param completion ConsumerResultCompletionBlock containing the AWSDKConsumer created, or an NSError with information about the failure

 @since 4.1.0
 */
- (void)enrollUserWithEnrollmentForm:(AWSDKDemographicForm *)data dependentCheck:(BOOL)dependentCheck completion:(ConsumerResultCompletionBlock)completion;

@end
