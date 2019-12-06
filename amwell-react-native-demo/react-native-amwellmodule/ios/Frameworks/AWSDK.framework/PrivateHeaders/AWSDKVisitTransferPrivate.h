//
//  AWSDKVisitTransferPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/15/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKProviderPrivate.h"

#import <AWSDK/AWSDKVisitTransfer.h>

@class AWSDKVisit;

/**
 A pending transfer request for a consumer sent by a provider or assistant.

 @since 2.1.0
 */
@interface AWSDKVisitTransfer : AWSDKDataObject <AWSDKVisitTransfer>

/**
 The provider that the consumer would be transferred to

 @since 2.1.0
 */
@property (nonatomic, readwrite, nonnull) AWSDKProvider *provider;

/**
 Boolean indicating if Quick Transfer is supported for this transfer.

 @discussion If true, the consumer can skip intake and will receive an AWSDKVisit from [AWSDKVisitTransfer acceptTransfer]
 If false, the consumer will go through intake and receive an AWSDKVisitContext from [AWSDKVisitTransfer acceptTransfer]

 @since 2.1.0
 */
@property (assign) BOOL quickTransferSupported;

@property (nonatomic, nonnull) AWSDKVisit *visit;

@end
