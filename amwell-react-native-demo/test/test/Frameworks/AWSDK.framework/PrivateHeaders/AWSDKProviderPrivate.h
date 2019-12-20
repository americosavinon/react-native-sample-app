//
//  AWSDKProviderPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/24/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKUserPrivate.h"

#import <AWCoreSDK/AWCoreNameProtocol.h>
#import <AWCoreSDK/AWCoreVidyoAccountProtocol.h>
#import <AWSDK/AWSDKProvider.h>
@class AWSDKLegalText, AWSDKPractice, AWSDKProviderSearchResult, AWSDKConsumer;

// Provider Availabilities
#define AVL_VIDYO_AVAILABLE (@"VIDYO_AVAILABLE")
#define AVL_VIDYO_BUSY (@"VIDYO_BUSY")
#define AVL_ON_CALL (@"ON_CALL")
#define AVL_PHONE_AVAILABLE (@"PHONE_AVAILABLE")
#define AVL_OFFLINE (@"OFFLINE")
#define WEB_AVAILABLE (@"WEB_AVAILABLE")
#define WEB_BUSY (@"WEB_BUSY")

/**
 A provider in American Well's telehealth platform.

 @discussion To fetch an AWSDKProvider, first fetch the AWSDKProviderSearchResult and then call [AWSDKProviderSearchResult fetchDetails:].

 @since 1.0.0
 */
@interface AWSDKProvider : AWSDKUser <AWSDKProvider, AWCoreNameProtocol, AWCoreVidyoAccountProtocol>

// The consumer that fetched the provider object. Used for credentials only. Nullable.
@property (nonatomic, readwrite) AWSDKConsumer *consumer;

@property (assign, nonatomic) BOOL hasLoadedDetails;
/**
 Legal Entity attached to a Provider, used to get the privacy policy that a consumer must agree to before a visit
 */
@property (nonatomic) AWSDKLegalText *disclaimer;

@property (assign, nonatomic) NSUInteger appointmentDuration;
@property (nonatomic, readonly) NSString *vidyoEntityID;

+ (NSArray<AWSDKProviderSearchResult *> *)providersFromSearchResults:(NSDictionary *)json fromPractice:(AWSDKPractice *)practice consumer:(AWSDKConsumer *)consumer;

+ (NSArray<AWSDKProvider *> *)providersFromArray:(NSArray *)array consumer:(AWSDKConsumer *)consumer;
+ (AWSDKMobileAvailability)availabilityForString:(NSString *)string;

+ (NSString *)stringForAvailability:(AWSDKMobileAvailability)availability;

@property (nonatomic, readwrite) UIImage *image;

- (void)setShowTriageQuestion:(BOOL)show;

@end
