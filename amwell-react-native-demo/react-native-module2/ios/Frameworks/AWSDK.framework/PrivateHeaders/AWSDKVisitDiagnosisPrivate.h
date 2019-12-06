//
//  AWSDKDiagnosisPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/20/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKVisitDiagnosis.h>

/**
 A diagnosis provided by a provider during or after a telehealth visit.

 @since 1.0.0
 */
@interface AWSDKVisitDiagnosis : AWSDKDataObject <AWSDKVisitDiagnosis>

@property NSInteger termId;

@property NSInteger priority;

+ (NSArray *)diagnosisFromArray:(NSArray *)array;

@end
