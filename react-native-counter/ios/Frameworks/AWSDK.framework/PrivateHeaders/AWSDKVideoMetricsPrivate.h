//
//  AWSDKVideoMetricsPrivatePrivate.h
//  AWSDK
//
//  Created by Stephen Ciauri on 4/4/19.
//  Copyright © 2019 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

/**
 An object that holds onto video metric data used for analytics

 @since 5.0.0
 */
@interface AWSDKVideoMetrics : NSObject

/**
 YES if the consumer has called the AWSDKVisit.joinVisitWithUUID:completion:

 @since 5.0.0
 */
@property (nonatomic) BOOL joined;

/**
 YES if the consumer has started streaming video

 @since 5.0.0
 */
@property (nonatomic) BOOL signedIn;

/**
 YES if the consumer requested to end the conference

 @since 5.0.0
 */
@property (nonatomic) BOOL endRequested;

/**
 If applicable, a string representation of a more specific reason why the video visit failed.

 @note For example, the video vendor endpoints could be failing, or the provider wasn't able to join/rejoin

 @since 5.0.0
 */
@property (nonatomic, nullable) NSString *failureReason;

/**
 Number of times the refresh button has been tapped

 @since 5.0.0
 */
@property (nonatomic) int manualRetryCount;

/**
 Number of automatic retries were necessary in order to initially begin media streaming

 @since 5.0.0
 */
@property (nonatomic) int autoRetryCount;

/**
 Creates a form param representation of the values

 @return NSDictionary to be turned into form params
 */
- (NSDictionary *_Nonnull)formParams;

@end
