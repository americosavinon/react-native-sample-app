//
//  AWSDKSuggestedVisitTransferPrivate.h
//  AWSDK
//
//  Created by steven.uy on 10/21/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKVisitTransferPrivate.h"

#import <AWSDK/AWSDKSuggestedVisitTransfer.h>

typedef NS_ENUM(NSInteger, AWSDKSuggestedTransferType) {
    AWSDKSuggestedTransferTypeAskMe,
    AWSDKSuggestedTransferTypeAvailableProvider,
};

/**
 While the consumer waits for a visit to start, the server may suggest a new provider for the consumer to transfer to if available after a configurable wait time.

 @discussion If a suggested visit transfer is offered, the consumer can either accept the transfer by calling [AWSDKVisitTransfer acceptTransfer:] or decline the transfer by calling declineTransfer to
 remain waiting for the current provider. If the consumer accepts the transfer, a new AWSDKVisitContext or AWSDKVisit will be populated for the new provider depending on if quick transfer is
 supported. See [AWSDKVisitTransfer acceptTransfer:] for more details.

 @since 2.1.0
 */
@interface AWSDKSuggestedVisitTransfer : AWSDKVisitTransfer <AWSDKSuggestedVisitTransfer>

@property (nonatomic) AWSDKSuggestedTransferType transferType;

@end
