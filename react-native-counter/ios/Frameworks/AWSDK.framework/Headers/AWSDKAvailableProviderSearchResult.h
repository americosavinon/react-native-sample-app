//
//  AWSDKAvailableProviderSearchResult.h
//  AWSDK
//
//  Created by Steven Uy on 12/23/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKProviderSearchResult.h>
#import <AWSDK/AWSDKSchedule.h>

/**
 Provider search result protocol containing information about the provider and their availability on a single day.

 @discussion [AWSDKAvailableProviderSearchResults date] contains day fetched for the provider's availability.

 @since 3.1.0
 */
@protocol AWSDKAvailableProviderSearchResult <AWSDKProviderSearchResult>

/**
 Array of available appointment times represented as AWSDKSchedule object.

 @note These only represent the provider's availability. It does not take into account if the consumer is available at this [AWSDKSchedule scheduledStartTime].

 @since 3.0.0
 */
@property (nonatomic, nonnull, readonly) NSArray<id<AWSDKSchedule>> *availableAppointmentSchedules;

@end
