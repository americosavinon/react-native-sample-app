//
//  AWSDKVisitReport.h
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

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>
#import <AWSDK/AWSDKSchedule.h>
#import <AWSDK/AWSDKVisitDisposition.h>

/**
 A report of a past visit summary.

 @note As of 2.1.0, AWSDKVisitSummaryReport was renamed to AWSDKVisitReport.

 @since 2.1.0
 */
@protocol AWSDKVisitReport <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSDate representing the date the visit occurred.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSDate *visitDate;

/**
 NSString representing the full name of the provider involved in the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSString *providerName;

/**
 NSString representing the full name of the consumer involved in the visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSString *consumerName;

/**
 NSString representing the full name of the dependent the visit was for, _nil_ if not a dependent visit.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSString *dependentName;

/**
 AWSDKSchedule representing the relevant date/duration information pertinent to the summarized visit.

 @since 3.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKSchedule> schedule;

/**
 _TRUE_ if visit completed successfully, otherwise _FALSE_.

 @since 2.1.0
 */
@property (readonly) BOOL visitCompleted;

/**
 AWSDKVisitDisposition of the summarized visit.

 @since 4.2.0
 */
@property (readonly) AWSDKVisitDisposition disposition;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Fetches the full data representation of the report.

 @param completion DataResultCompletionBlock containing an NSData object, which is the raw data representation of a PDF, otherwise an optional NSError reporting any issues.

 @since 2.1.0
 */
- (void)fetchReportAsData:(nullable DataResultCompletionBlock)completion;

/**
 Fetches the visit report as a AWSDKVisitReportSummary object.

 @param completion VisitReportSummaryCompletionBlock containing the associated AWSDKVisitReportSummary object, otherwise an NSError if there are any issues.

 @since 2.1.0
 */
- (void)fetchReportSummary:(nullable VisitReportSummaryCompletionBlock)completion;

@end
