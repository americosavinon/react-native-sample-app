//
//  AWSDKSubscriptionFormPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 8/09/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKSubscriptionForm.h>

@interface AWSDKSubscriptionForm ()

/**
 When set, server will check EDI one more time before updating subscription for the consumer
 */
@property (nonatomic) NSString *eligibilityRequestId;

@end
