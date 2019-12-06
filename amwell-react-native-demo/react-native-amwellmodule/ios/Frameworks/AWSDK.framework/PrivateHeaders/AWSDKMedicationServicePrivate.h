//
//  AWSDKMedicationServicePrivate.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/27/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKMedicationService.h>

/**
 Service class to handle medication related tasks.

 @since 3.0.0
 */
@interface AWSDKMedicationService ()

#pragma mark - Singleton
/**
 @name Singleton
 */

/**
 Singleton accessor for AWSDKMedicationService.

 @return The main AWSDKMedicationService instance

 @since 3.0.0
 */
+ (instancetype)sharedInstance;

#pragma mark - Private Methods

/**
 Fetch a list of medications using the provided query.

 @param query       NSString query used to fetch the list of medications.
 @param completion  Completion block to be called when the network request to the American Well Telehealth Platform is completed.

 @since 3.0.0
 */
- (void)performMedSearchWithQuery:(NSString *)query completion:(MedicationsCompletionBlock)completion;

@end
