//
//  AWSDKAvailableProviderSearchResultPrivate.h
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

#import "AWSDKDataObjectPrivate.h"
#import "AWSDKProviderSearchResultPrivate.h"

#import <AWSDK/AWSDKAvailableProviderSearchResult.h>

/**
 Provider search result containing information about the provider and their availability on a single day.

 @discussion [AWSDKAvailableProviderSearchResults date] contains day fetched for the provider's availability.

 @since 3.0.0
 */
@interface AWSDKAvailableProviderSearchResult : AWSDKProviderSearchResult <AWSDKAvailableProviderSearchResult>

+ (NSArray *)availableProvidersFromSearchResult:(NSArray *)array;

@end
