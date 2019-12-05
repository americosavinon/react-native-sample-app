//
//  AWSDKConditionPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/15/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKCondition.h>

/**
 A medical condition that may be current for a consumer.

 @since 1.0.0
 */
@interface AWSDKCondition : AWSDKDataObject <AWSDKCondition>

@property int termId;

+ (NSArray *)conditionsFromArray:(NSArray *)array;

@end
