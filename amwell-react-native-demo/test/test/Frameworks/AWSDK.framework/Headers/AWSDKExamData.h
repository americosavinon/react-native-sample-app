//
//  AWSDKExamData.h
//  AWSDK
//
//  Created by Stephen Ciauri on 12/10/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

/**
 Represents the data collected during an exam that occurred using an integrated device.

 @since 4.3.0
 */
@protocol AWSDKExamData

/**
 The date that the exam occurred

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) NSDate *date;

/**
 The unique identifier for the exam

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) NSString *id;

/**
 A NSString describing the type of exam

 @since 4.3.0
 */
@property (nonatomic, readonly, nonnull) NSString *type;

/**
 NSURL pointing to a network location where the exam data resides

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSURL *url;

@end
