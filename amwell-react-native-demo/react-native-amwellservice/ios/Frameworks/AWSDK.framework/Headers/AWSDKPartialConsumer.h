//
//  AWSDKPartialConsumer.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/4/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKState;

/**
 A partially registered consumer in the telehealth platform.

 @since 3.1.0
 */
@protocol AWSDKPartialConsumer <AWSDKDataObject>

/**
 Represents the email address used to register the user

 @since 4.1.0
 */
@property (nonnull, nonatomic, readonly) NSString *emailOnFile;
/**
 Completes registration on the telehealth platform.

 @param location   AWSDKState the consumer is located in.
 @param username   Optional NSString new username for the account, which must be an email address.
 @param password   Optional NSString new password for the account.
 @param completion ConsumerResultCompletionBlock containing the enrolled AWSDKConsumer object or an NSError with the failure reasons.

 @since 1.0.0
 */
- (void)completeEnrollmentWithLocation:(nonnull id<AWSDKState>)location
                              username:(nullable NSString *)username
                              password:(nullable NSString *)password
                            completion:(nonnull ConsumerResultCompletionBlock)completion;
@end
