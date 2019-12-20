//
//  AWSDKDeviceIntegrationSearchRequest.h
//  AWSDK
//
//  Created by Stephen Ciauri on 12/11/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

/**
 Bundle class representing the search params for the AWSDKDeviceIntegration search function

 @since 4.3.0
 */
@interface AWSDKDeviceIntegrationSearchRequest : NSObject

/**
 The date interval, which represents the timespan between the specified start and end date, to use when searching for AWSDKDeviceIntegration records

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSDateInterval *dateRange;

/**
 The maximum number of records to return

 @note Defaults to the telehealth platform's configurable threshold.

 @since 4.3.0
 */
@property (nonatomic, readwrite) int pageSize;

/**
 If true, this will only match records that are not associated with an AWSDKVisit.

 @note Defaults to NO.

 @since 4.3.0
 */
@property (nonatomic, readwrite) BOOL visitlessOnly;

@end
