//
//  AWSDKSuggestedVisitTransfer.h
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

#import <AWSDK/AWSDKVisitTransfer.h>

/**
 While the consumer waits for a visit to start, the server may suggest a new provider for the consumer to transfer to if available after a configurable wait time.

 @discussion If a suggested visit transfer is offered, the consumer can either accept the transfer by calling [AWSDKVisitTransfer acceptTransfer:] or decline the transfer by calling declineTransfer to
 remain waiting for the current provider. If the consumer accepts the transfer, a new AWSDKVisitContext or AWSDKVisit will be populated for the new provider depending on if quick transfer is
 supported. See [AWSDKVisitTransfer acceptTransfer:] for more details.

 @since 3.1.0
 */
@protocol AWSDKSuggestedVisitTransfer <AWSDKVisitTransfer>
/**
 Boolean value indicating if the consumer wishes not to be given visit transfer suggestions anymore.

 @discussion If enabled by the consumer, the server will no longer send visit transfer suggestions while the consumer is waiting for a visit to begin.  Default value is false.

 @since 3.2.0
 */
@property (assign) BOOL dontSuggestTransferAgain;

/**
 Declines the transfer to continue waiting for the current visit.

 @param completion GenericCompletionBlock containing _TRUE_ if the transfer was successfully declined, otherwise _FALSE_ and an NSError explaining why.

 @since 2.1.0
 */
- (void)declineTransfer:(nullable GenericCompletionBlock)completion;
@end
