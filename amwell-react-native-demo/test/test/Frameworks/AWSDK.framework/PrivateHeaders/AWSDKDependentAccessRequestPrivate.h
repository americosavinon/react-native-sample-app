//
//  AWSDKDependentAccessRequestPrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 4/8/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKConsumer.h>
#import <AWSDK/AWSDKDependentAccessRequest.h>

/**
 Dependent Access Private Interface.

 @since 4.0.2
 */
@interface AWSDKDependentAccessRequest ()

- (void)acceptWithGuardian:(nonnull id<AWSDKConsumer>)guardian dependentIds:(nonnull NSArray<NSString *> *)dependentIds completion:(nullable GenericCompletionBlock)completion;

@end
