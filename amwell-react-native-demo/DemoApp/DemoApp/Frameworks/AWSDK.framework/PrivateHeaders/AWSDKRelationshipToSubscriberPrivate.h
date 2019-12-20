//
//  AWSDKRelationshipToProviderPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/11/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKRelationshipToSubscriber.h>

/**
 A relationship to a primary subscriber of a health plan.

 @since 1.0.0
 */
@interface AWSDKRelationshipToSubscriber : AWSDKDataObject <AWSDKRelationshipToSubscriber>

+ (NSArray *)relationshipsFromArray:(NSArray *)array;

@property int value;

@end
