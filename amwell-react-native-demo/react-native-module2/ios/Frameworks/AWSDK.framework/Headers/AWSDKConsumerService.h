//
//  AWSDKConsumerService.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/23/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 Service handling consumer related tasks.

 @since 3.0.0
 */
@protocol AWSDKConsumerService <AWSDKDataObject>

#pragma mark - Consumer Methods
/**
 @name Consumer Methods
 */

/**
 Fetches an instance of AWSDKConsumer that represents an authenticated consumer given a consumerAuthKey.

 @param consumerAuthKey  NSString representing a shared unique identifier for an authenticated consumer in American Well's telehealth platform.
 @param completion       ConsumerResultCompletionBlock containing the AWSDKConsumer object for the specified consumer, otherwise an NSError which reports any errors occured.

 Potential Error Codes
 @exception AWSDKErrorCodeConsumerUnauthenticated            The consumer has not yet been authenticated.
 @exception AWSDKErrorCodeAuthenticationAccessDenied         The credentials didn't match a user on the telehealth platform.

 @since 3.0.0
 */
+ (void)getConsumerWithAuthKey:(nonnull NSString *)consumerAuthKey completion:(nonnull ConsumerResultCompletionBlock)completion;

/**
 Forces the SDK to ignore a cached version of the desired AWSDKConsumer and reload all consumer details from the American Well telehealth platform server.

 @param consumerAuthKey  NSString representing a shared unique identifier that representing an authenticated consumer in American Well's telehealth platform.
 @param completion       ConsumerResultCompletionBlock containing the AWSDKConsumer object for the specified consumer, otherwise an NSError which reports any errors occurred.

 Potential Error Codes
 @exception AWSDKErrorCodeConsumerUnauthenticated            The consumer has not yet been authenticated.
 @exception AWSDKErrorCodeAuthenticationAccessDenied         The credentials didn't match a user on the telehealth platform.

 @since 3.0.0
 */
+ (void)reloadDetailsForConsumer:(nonnull NSString *)consumerAuthKey completion:(nonnull ConsumerResultCompletionBlock)completion;

/**
 Fetches a response for a given source ID indicating if a consumer exists or not.

 @param consumerSourceId  NSString representing a unique identifier for a consumer in American Well's telehealth platform.
 @param completion        GenericCompletionBlock containing boolean inidicating if consumer is found or not.  Otherwise, an NSError is returned reporting any errors that may have occured.

 Potential Error Codes
 @exception AWSDKErrorCodeConsumerSourceIdBadRequest            The source ID input parameter is invalid.

 @since 3.1.0
 */
+ (void)checkConsumerExistsWithSourceId:(nonnull NSString *)consumerSourceId completion:(nullable GenericCompletionBlock)completion;

@end

/**
 Service handling consumer related tasks.

 @since 3.0.0
 */
@interface AWSDKConsumerService : AWSDKDataObject <AWSDKConsumerService>
#pragma mark - Appledoc
+ (void)getConsumerWithAuthKey:(nonnull NSString *)consumerAuthKey completion:(nonnull ConsumerResultCompletionBlock)completion;
+ (void)reloadDetailsForConsumer:(nonnull NSString *)consumerAuthKey completion:(nonnull ConsumerResultCompletionBlock)completion;
+ (void)checkConsumerExistsWithSourceId:(nonnull NSString *)consumerSourceId completion:(nullable GenericCompletionBlock)completion;

#pragma mark -
@end
