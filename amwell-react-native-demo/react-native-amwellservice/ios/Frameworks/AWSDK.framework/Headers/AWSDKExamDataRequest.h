//
//  AWSDKExamDataRequest.h
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
 Used to populate AWSDKDeviceIntegrationRequest objects with exam data records

 @since 4.3.0
 */
@interface AWSDKExamDataRequest : NSObject
/**
 The date that the exam occurred

 @note This value must be populated

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSDate *date;

/**
 The unique identifier for the exam

 @note This value must be populated

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSString *id;

/**
 A NSString describing the type of exam

 @note This value must be populated

 @since 4.3.0
 */
@property (nonatomic, readwrite, nullable) NSString *type;
@end
