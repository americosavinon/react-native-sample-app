//
//  AWSDKForcedVisitTransferPrivate.h
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

#import <AWSDK/AWSDKForcedVisitTransfer.h>

/**
 A forced transfer for a visit when the provider declines the visit suggests a new transfer.

 @discussion The previous visit ends and the provider suggests a transfer to another provider. The consumer can decide to accept the transfer by calling the super class method [AWSDKVisitTransfer
 acceptTransfer:] , or decline the transfer where no call is necessary because the previous visit has already ended. If the consumer accepts, they are presented with either a new AWSDKVisitContext or
 AWSDKVisit depending if quick transfer is supported. See [AWSDKVisitTransfer acceptTransfer:] for more details.

 @since 2.1.0
 */
@interface AWSDKForcedVisitTransfer : AWSDKVisitTransfer <AWSDKForcedVisitTransfer>

@end
