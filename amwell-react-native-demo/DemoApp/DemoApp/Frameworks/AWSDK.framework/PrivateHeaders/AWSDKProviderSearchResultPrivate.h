//
//  AWSDKProviderSearchResultPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 10/30/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"
#import "AWSDKUserPrivate.h"

#import <AWSDK/AWSDKProviderSearchResult.h>

@class AWSDKConsumer;

/**
 A result of a provider search.

 @discussion This is a preview containing basic information about a provider. use fetchDetails: to retrieve the AWSDKProvider object.

 @since 1.0.0
 */
@interface AWSDKProviderSearchResult : AWSDKUser <AWSDKProviderSearchResult>

+ (NSArray<AWSDKProviderSearchResult *> *)providersFromSearchResult:(NSArray *)array consumer:(AWSDKConsumer *)consumer;
@property (nonatomic, readwrite) UIImage *image;

@property (nonatomic, readwrite) AWSDKConsumer *consumer;

@end
