//
//  AWSDKMedicationPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/15/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKMedication.h>

/**
 A medication in the American Well system.

 @since 1.0.0
 */
@interface AWSDKMedication : AWSDKDataObject <AWSDKMedication>

@property (nonatomic) NSString *code;

+ (NSArray *)medicationsFromArray:(NSArray *)array;

@end
