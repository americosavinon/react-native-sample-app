//
//  AWSDKVisitReportPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 9/9/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"
#import "AWSDKVisitReportSummaryPrivate.h"

#import <AWSDK/AWSDKVisitReport.h>

/**
 A report of a past visit summary.

 @note As of 2.1.0, AWSDKVisitSummaryReport was renamed to AWSDKVisitReport.

 @since 2.1.0
 */
@interface AWSDKVisitReport : AWSDKDataObject <AWSDKVisitReport>
@property (nonatomic) NSString *consumerAuthKey;

+ (NSArray *)summariesFromArray:(NSArray *)array;

@end
