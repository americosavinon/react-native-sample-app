//
//  AWSDKTriageQuestionPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/8/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKTriageQuestion.h>

/**
 A triage question to be answered during intake of a visit.

 @since 1.0.0
 */
@interface AWSDKTriageQuestion : AWSDKDataObject <AWSDKTriageQuestion>

+ (nullable NSArray *)questionsFromArray:(nonnull NSArray *)array;

@end
