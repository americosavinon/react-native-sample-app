//
//  AWSDKDependentAccessRequest.h
//  AWSDK
//
//  Created by Rolin Nelson on 4/8/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKConsumer.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 Dependent Access Request protocol containing parameters in an access request.

 @since 4.1.0
 */
@protocol AWSDKDependentAccessRequest

/**
 @name Read-Only Properties
 */

/**
 AWSDKConsumer representing the guardian of the dependent

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKConsumer> guardian;

/**
 AWSDKConsumer the requestor of the access request

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKConsumer> requestor;

/**
 AWSDKConsumer the dependents the requestor is looking for permission from the guardian to access

 @since 4.1.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKConsumer>> *dependents;

/**
 Accepts the dependent access request.

 @param guardian        AWSDKConsumer the guardian accepting the request.
 @param dependents      NSArray<id<AWSDKConsumer> > the dependents to be granted access to the requestor.
 @param completion      GenericCompletionBlock containing _TRUE_ if the dependent access request was successfully accepted, otherwise _FALSE_ and an NSError explaining the failure.

 @since 4.1.0
 */
- (void)acceptWithGuardian:(nonnull id<AWSDKConsumer>)guardian dependents:(nonnull NSArray<id<AWSDKConsumer>> *)dependents completion:(nullable GenericCompletionBlock)completion;

/**
 Declines the dependent access request.

 @param guardian        AWSDKConsumer the guardian declining the request.
 @param completion      GenericCompletionBlock containing _TRUE_ if the dependent access request was successfully declined, otherwise _FALSE_ and an NSError explaining the failure.

 @since 4.1.0
 */
- (void)declineWithGuardian:(nonnull id<AWSDKConsumer>)guardian completion:(nullable GenericCompletionBlock)completion;

@end

/**
 @since 4.1.0
 */
@interface AWSDKDependentAccessRequest : AWSDKDataObject <AWSDKDependentAccessRequest>

@end
