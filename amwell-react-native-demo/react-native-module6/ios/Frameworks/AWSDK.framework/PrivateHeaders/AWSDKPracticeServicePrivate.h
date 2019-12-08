//
//  AWSDKPracticeServicePrivate.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/25/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKPracticeService.h>

@interface AWSDKPracticeService ()

#pragma mark - Singleton
/**
 @name Singleton
 */

/**
 Singleton accessor for AWSDKPracticeService

 @return The main AWSDKPracticeService instance

 @since 3.0.0
 */
+ (instancetype)sharedInstance;

#pragma mark - Private Methods
/**
 @name Private Methods
 */

/**
 Fetch a list of practices with the consumer auth token.

 @param consumerAuthToken   Consumer auth token
 @param params              NSDictionary of parameters used with the fetch.
 @param completion          Completion block to be called when the network request to the American Well Telehealth Platform is completed.

 @since 3.0.0
 */
- (void)fetchPracticesWithConsumerAuthKey:(NSString *)consumerAuthToken parameters:(NSDictionary *)params completion:(PracticeSearchResultsCompletionBlock)completion;

/**
 Fetch a list of practices with the consumer auth token.

 @param consumerAuthToken   Consumer auth token
 @param completion          Completion block to be called when the network request to the American Well Telehealth Platform is completed.

 @since 3.0.0
 */
- (void)fetchPracticesForConsumerAuthKey:(NSString *)consumerAuthToken withCompletion:(PracticeResultsCompletionBlock)completion;

@end
