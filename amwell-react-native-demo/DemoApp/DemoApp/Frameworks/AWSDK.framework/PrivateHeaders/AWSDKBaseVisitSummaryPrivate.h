//
//  AWSDKBaseVisitSummaryPrivate.h
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

#import <AWSDK/AWSDKBaseVisitSummary.h>
#import <AWSDK/AWSDKVisitDisposition.h>

@class AWSDKConsumer;

/**
 Parent visit summary class containing properties shared between AWSDKVisitSummary and AWSDKVisitReportSummary.

 @since 2.1.0
 */
@interface AWSDKBaseVisitSummary : AWSDKDataObject <AWSDKBaseVisitSummary>

@property (nonatomic, readwrite, nullable) NSURL *providerURL;
/**
 AWSDKConsumer consumer for the visit

 @since 4.1.0
 */
@property (nonatomic, readwrite, nonnull) id<AWSDKConsumer> consumer;

/**
 AWSDKConsumer parent for the visit if the consumer is a dependent

 @since 4.1.0
 */
@property (nonatomic, readwrite, nullable) id<AWSDKConsumer> consumerProxy;

@property (nonatomic, readwrite) AWSDKVisitDisposition disposition;

@end
