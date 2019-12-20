//
//  AWSDKAvailableProviderSearchResultsPrivate.h
//  AWSDK
//
//  Created by Stephen Ciauri on 8/9/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKAvailableProviderSearchResults.h>

/**
 Results of [AWSDKProviderService fetchAvailableProvidersWithOptions:withCompletion:] containing the day fetched and the array of available providers and their schedule.

 @since 3.0.0
 */
@interface AWSDKAvailableProviderSearchResults : AWSDKDataObject <AWSDKAvailableProviderSearchResults>
@end
