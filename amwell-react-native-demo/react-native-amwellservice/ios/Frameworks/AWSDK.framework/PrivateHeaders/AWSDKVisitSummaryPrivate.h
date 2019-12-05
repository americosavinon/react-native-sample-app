//
//  AWSDKVisitSummaryPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/18/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKBaseVisitSummaryPrivate.h"
#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKVisitSummary.h>

/**
 The wrap up summary provided at the end of the visit.

 @note This is provided by [AWSDKVisit fetchVisitSummary:].

 @since 1.0.0
 */
@interface AWSDKVisitSummary : AWSDKBaseVisitSummary <AWSDKVisitSummary>
+ (NSArray *)summariesFromArray:(NSArray *)array;

@end
