//
//  AWSDKVisitReportSummaryPrivate.h
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

#import "AWSDKBaseVisitSummaryPrivate.h"

#import <AWSDK/AWSDKVisitReportSummary.h>

/**
 Past visit report containing details about the visit.

 @since 2.1.0
 */
@interface AWSDKVisitReportSummary : AWSDKBaseVisitSummary <AWSDKVisitReportSummary>

@property (nonatomic, nullable) NSString *consumerAuthKey;

/**
 The encryptedID of the visit referenced in the generated report

 @since 5.2.0
 */
@property (nonatomic, readwrite, nullable) NSString *engagementID;


@end
