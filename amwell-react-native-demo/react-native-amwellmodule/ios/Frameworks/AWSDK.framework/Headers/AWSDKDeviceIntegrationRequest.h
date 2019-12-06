//
//  AWSDKDeviceIntegrationRequest.h
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

@class AWSDKExamDataRequest;

@protocol AWSDKVisit;

/**
 Used to add device integration data to a consumer's profile

 @since 4.3.0
 */
@interface AWSDKDeviceIntegrationRequest : NSObject

/**
 The exam data that will be uploaded with the device integration

 @note You must populate this value

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSArray<AWSDKExamDataRequest *> *examData;

/**
 The visit that is associated with the desired exam data

 @note You must populate this value

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) id<AWSDKVisit> visit;

@end
