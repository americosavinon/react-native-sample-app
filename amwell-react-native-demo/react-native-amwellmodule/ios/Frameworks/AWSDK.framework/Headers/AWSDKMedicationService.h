//
//  AWSDKMedicationService.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 Service protocol to handle medication related tasks.

 @since 3.0.0
 */
@protocol AWSDKMedicationService <AWSDKDataObject>

#pragma mark - Medication Search Methods

/**
 @name Medication Search Methods
 */

/**
 Fetches a list of medications with names matching a given search string.

 @discussion Search is case-insensitive and "starts with" type search e.g. amo -> amoxicillin.

 @param searchString NSString representing the query name to search medications for with minimum length of 3 characters.
 @param completion   MedicationsCompletionBlock containing an NSArray of AWSDKMedication objects with a name matching the searchString, otherwise an NSError explaining any failures.

 Potential Error Codes
 @exception AWSDKErrorCodeInvalidValue  searchString has invalid length.

 @since 3.0.0
 */
+ (void)searchMedicationsWithString:(nonnull NSString *)searchString completion:(nonnull MedicationsCompletionBlock)completion;

@end

/**
 Service class to handle medication related tasks.

 @since 3.0.0
 */
@interface AWSDKMedicationService : AWSDKDataObject <AWSDKMedicationService>
#pragma mark - Appledoc
+ (void)searchMedicationsWithString:(nonnull NSString *)searchString completion:(nonnull MedicationsCompletionBlock)completion;
#pragma mark -
@end
