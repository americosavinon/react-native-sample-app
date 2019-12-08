//
//  AWSDKVisitTransfer.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKProvider;

/**
 A pending transfer request protocol for a consumer sent by a provider or assistant.

 @since 3.1.0
 */
@protocol AWSDKVisitTransfer <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKProvider representing the provider that the consumer would be transferred to.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) id<AWSDKProvider> provider;

/**
 _TRUE_ if quick transfer is supported for the transfer, otherwise _FALSE_ if not supported.

 @discussion If _TRUE_, the consumer can skip intake and will receive an AWSDKVisit from [AWSDKVisitTransfer acceptTransfer:] . If _FALSE_, the consumer will go through intake and receive an
 AWSDKVisitContext from [AWSDKVisitTransfer acceptTransfer:] .

 @since 2.1.0
 */
@property (assign, readonly) BOOL quickTransferSupported;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Accepts the transfer and cancels the current visit request.

 @param completion TransferResultCompletionBlock contains either an AWSDKVisitContext if quick transfer is not supported, or an AWSDKVisit if quick transfer is supported, otherwise an NSError
 explaining any failures.

 @note Valid dispositions for visit: AWSDKVisitDispositionPreVisit and AWSDKVisitDispositionInVisit
 
 @since 2.1.0
 */
- (void)acceptTransfer:(nullable TransferResultCompletionBlock)completion;

@end
