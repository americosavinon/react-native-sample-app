//
//  AWSDKAuthenticationServicePrivate.h
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

#import <AWSDK/AWSDKAuthenticationService.h>

@class BasicAuthCredentials, AWSDKConsumerAuthentication, AWJSONResponse;
@protocol NetworkCredentials;

@interface AWSDKAuthenticationService ()

#pragma mark - Singleton
/**
 @name Singleton
 */

/**
 Singleton accessor for AWSDKAuthenticationService

 @return The main AWSDKAuthenticationService instance

 @since 3.0.0
 */
+ (instancetype)sharedInstance;

#pragma mark - Private Properties
/**
 @name Private Properties
 */

/**
 NSDictionary to cache ConsumerAuthentication objects so we don't need to have the client hold onto them, and so we don't need to reauthenticate the consumer with every call.

 @discussion Formatted with the consumerAuthKey as the Key and the AWSDKConsumerAuthentication as the value

 @since 3.0.0
 */
@property (nonatomic) NSMutableDictionary<NSString *, AWSDKConsumerAuthentication *> *consumerAuthenticationCache;

#pragma mark - Authentication Helpers
/**
 @name Authentication Helpers
 */

/**
 Performs an authentication call with the consumers credentials.

 @param params      NSDictionary of parameters required to authenticate the user against the the American Well Telehealth Platform system.
 @param completion  A completion block to be called once the network request has been completed.

 @since 3.0.0
 */
- (void)performAuthWithCredentialsWithParameters:(NSDictionary *)params completion:(AuthenticationResultCompletionBlock)completion;

/**
 Performs an authentication call with the consumers authentication key.

 @param params      NSDictionary of parameters required to authenticate the user against the the American Well Telehealth Platform system.
 @param completion  A completion block to be called once the network request has been completed.

 @since 3.0.0
 */
- (void)performAuthWithConsumerAuthKeyWithParameters:(NSDictionary *)params completion:(AuthenticationResultCompletionBlock)completion;

/**
 Performs an authentication call to the American Well Telehealth Platform with the appropriate url and parameters.

 @param authURL     NSURL for the authentication endpoint we are authenticating against.
 @param params      NSDictionary of parameters required to authenticate the user against the the American Well Telehealth Platform.
 @param credentials BasicAuthCredential to use with the authentication call. This is optional and can be nil.
 @param completion  A completion block to be called once the network request has been completed.

 @since 3.0.0
 */
- (void)performAuthWithURL:(NSURL *)authURL parameters:(NSDictionary *)params credentials:(id<NetworkCredentials>)credentials completion:(AuthenticationResultCompletionBlock)completion;

/**
 Obtain the BasicAuthCredentials for a consumer based on the consumers authentication key.

 @param consumerAuthKey NSString representation of the consumers authentication key.

 @since 3.0.0
 */
- (id<NetworkCredentials>)credentialsForConsumer:(NSString *)consumerAuthKey;

/**
 Parses the response and extracts any JWT credentials and saves them to the cache keyed on the consumer's userAuthKey

 @param response The successful network response
 @return the AWSDKConsumerAuthentication object parsed from the response
 */
- (AWSDKConsumerAuthentication *)updateCredentialsCacheWithResponse:(AWJSONResponse *)response;

/**
 Clears all state

 @discussion Should be updated every time a new state is added

 @since 3.2.2
 */
- (void)clear;

@end
