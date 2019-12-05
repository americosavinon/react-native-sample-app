//
//  AWSDKPharmacyService.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

@class CLCircularRegion;
@protocol AWSDKState;

/**
 Service handling pharmacy related tasks.

 @since 3.0.0
 */
@protocol AWSDKPharmacyService <AWSDKDataObject>

#pragma mark - Pharmacy Search Methods
/**
 @name Pharmacy Search Methods
 */

/**
 Fetches a list of all states valid for pharmacy search.

 @param completion StatesCompletionBlock with an NSArray of AWSDKState valid states for pharmacy search, otherwise an NSError explaining any failures.

 @since 3.0.0
 */
+ (void)fetchPharmacySearchStates:(nullable StatesCompletionBlock)completion;

/**
 Fetches a list of all pharmacies within a city of a state.

 @param city       NSString representing the city name to search for pharmacies in.
 @param state      AWSDKState representing the state the city is in. Use fetchPharmacySearchStates: to retrieve all valid states.
 @param completion PharmaciesCompletionBlock containing an NSArray of AWSDKPharmacy pharmacies in the city, otherwise an NSError explaining any failures.

 @since 3.0.0
 */
+ (void)fetchPharmaciesWithCity:(nonnull NSString *)city state:(nonnull id<AWSDKState>)state completion:(nonnull PharmaciesCompletionBlock)completion;

/**
 Fetches a list of all pharmacies within a given zip code.

 @param zip        NSString representing the zip code to be searched.
 @param completion PharmaciesCompletionBlock containing an NSArray of AWSDKPharmacy pharmacies in the zip code, otherwise an NSError explaining any failures.

 @since 3.0.0
 */
+ (void)fetchPharmaciesWithZipCode:(nonnull NSString *)zip completion:(nonnull PharmaciesCompletionBlock)completion;

/**
 Fetches a list of all pharmacies within a given latitude, longitude, and radius.

 @param region     CLCircularRegion containing a center latitude, longitude, and a region to search for pharmacies.
 @param completion PharmaciesCompletionBlock containing an NSArray of AWSDKPharmacy pharmacies in the region, otherwise an NSError explaining any failures.

 @since 3.0.0
 */
+ (void)fetchPharmaciesWithRegion:(nonnull CLCircularRegion *)region completion:(nonnull PharmaciesCompletionBlock)completion;

@end

/**
 Service handling pharmacy related tasks.

 @since 3.0.0
 */
@interface AWSDKPharmacyService : AWSDKDataObject <AWSDKPharmacyService>
#pragma mark - Appledoc
+ (void)fetchPharmacySearchStates:(nullable StatesCompletionBlock)completion;
+ (void)fetchPharmaciesWithCity:(nonnull NSString *)city state:(nonnull id<AWSDKState>)state completion:(nonnull PharmaciesCompletionBlock)completion;
+ (void)fetchPharmaciesWithZipCode:(nonnull NSString *)zip completion:(nonnull PharmaciesCompletionBlock)completion;
+ (void)fetchPharmaciesWithRegion:(nonnull CLCircularRegion *)region completion:(nonnull PharmaciesCompletionBlock)completion;
#pragma mark -
@end
