//
//  AWSDKOnDemandSpecialtyPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 2/18/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKOnDemandSpecialty.h>

@class AWSDKPractice, AWSDKVisitTopic;

/**
 A grouping that contains one or more provider types to filter by when performing a 'first available' search.

 @discussion Each practice can configure up to one AWSDKOnDemandSpecialty.

 @since 1.0.0
 */
@interface AWSDKOnDemandSpecialty : AWSDKDataObject <AWSDKOnDemandSpecialty>

+ (NSArray *)specialtiesFromArray:(NSArray *)array withPractice:(AWSDKPractice *)practice;

@property (nonatomic) AWSDKPractice *practice;

@property (nonatomic) NSArray<AWSDKVisitTopic *> *suggestedTopics;

@end
