//
//  AWSDKAvailableProviderSearchResults.h
//  AWSDK
//
//  Created by Steven Uy on 12/27/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKAvailableProviderSearchResult.h>
#import <AWSDK/AWSDKDataObject.h>

/**
 Result protocol of [AWSDKProviderService fetchAvailableProvidersWithOptions:withCompletion:] containing the day fetched and the array of available providers and their schedule.

 @since 3.1.0
 */
@protocol AWSDKAvailableProviderSearchResults <AWSDKDataObject>

/**
 NSArray of AWSDKAvailableProviderSearchResult objects containing a provider search result and a list of AWSDKSchedule available times.

 @since 3.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<id<AWSDKAvailableProviderSearchResult>> *providerSearchResults;

/**
 NSDate representing the day of all the available AWSDKSchedule appointment times.

 @discussion If the next available appointment day is fetched, date is automatically populated with the next available day, otherwise it is the day fetched.

 @since 3.0.0
 */
@property (nonatomic, readonly, nullable) NSDate *date;
@end
