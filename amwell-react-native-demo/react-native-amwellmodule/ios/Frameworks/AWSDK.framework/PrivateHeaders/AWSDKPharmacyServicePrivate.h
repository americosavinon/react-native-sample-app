//
//  AWSDKPharmacyServicePrivate.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/26/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKPharmacyService.h>

@interface AWSDKPharmacyService ()

#pragma mark - Singleton
/**
 @name Singleton
 */

/**
 Singleton accessor for AWSDKPharmacyService.

 @return The main AWSDKPharmacyService instance

 @since 3.0.0
 */
+ (instancetype)sharedInstance;

#pragma mark - Private Methods
/**
 @name Private Methods
 */

/**
 Fetch a list of pharmacies with the provided parameters.

 @param params      NSDictionary of parameters used to fetch the pharmacies.
 @param completion  Completion block to be called when the network request to the American Well Telehealth Platform is completed.

 */
- (void)fetchPharmaciesWithParameters:(NSDictionary *)params withCompletion:(PharmaciesCompletionBlock)completion;

@end
