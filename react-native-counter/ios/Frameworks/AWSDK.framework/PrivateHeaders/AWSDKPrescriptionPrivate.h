//
//  AWSDKPrescriptionPrivate.h
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

#import <AWSDK/AWSDKPrescription.h>

/**
 A prescription prescribed by a provider during or after a visit.

 @since 1.0.0
 */
@interface AWSDKPrescription : AWSDKDataObject <AWSDKPrescription>

@property BOOL dispenseAsWritten;

+ (NSArray *)prescriptionsFromArray:(NSArray *)array;

@end
