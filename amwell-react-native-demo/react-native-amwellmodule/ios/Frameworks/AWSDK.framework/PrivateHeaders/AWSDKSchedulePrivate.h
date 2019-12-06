//
//  AWSDKSchedulePrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/25/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"
#import "AWSDKProviderPrivate.h"

#import <AWSDK/AWSDKSchedule.h>

/**
 The schedule of an appointment or past visit.

 @since 1.0.0
 */
@interface AWSDKSchedule : AWSDKDataObject <AWSDKSchedule>

/**
 Set if the schedule is associated with a provider, nil otherwise
 */
@property (nonatomic) AWSDKProvider *provider;

- (instancetype)initWithISO8601String:(NSString *)string withProvider:(AWSDKProvider *)provider;

- (void)updateScheduledStartTimeWith:(NSDate *)date;

+ (NSArray<AWSDKSchedule *> *)arrayWithISO8601StringArray:(NSArray<NSString *> *)array withProvider:(AWSDKProvider *)provider;

@end
