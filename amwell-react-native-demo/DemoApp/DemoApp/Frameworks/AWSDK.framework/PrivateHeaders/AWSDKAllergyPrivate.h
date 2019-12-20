//
//  AWSDKAllergyPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/14/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKAllergy.h>

/**
 An allergy that may be current for a consumer.

 @since 1.0.0
 */
@interface AWSDKAllergy : AWSDKDataObject <AWSDKAllergy>

@property int termId;

+ (NSArray *)allergiesFromArray:(NSArray *)array;

@end
