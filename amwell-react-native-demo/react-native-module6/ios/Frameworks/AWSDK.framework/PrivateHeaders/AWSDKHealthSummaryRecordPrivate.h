//
//  AWSDKHealthSummaryRecordPrivate.h
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

#import <AWSDK/AWSDKHealthSummaryRecord.h>

/**
 A record in a consumer's health summary such as an allergy or medication.

 @since 1.0.0
 */
@interface AWSDKHealthSummaryRecord : AWSDKDataObject <AWSDKHealthSummaryRecord>

@property (nonatomic) NSString *code;

+ (NSArray *)recordsFromArray:(NSArray *)array;

@end
