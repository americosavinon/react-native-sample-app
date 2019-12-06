//
//  AWSDKProcedurePrivate.h
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

#import <AWSDK/AWSDKVisitProcedure.h>

/**
 A procedure that was or should be performed by a provider.

 @since 1.0.0
 */
@interface AWSDKVisitProcedure : AWSDKDataObject <AWSDKVisitProcedure>
@property NSInteger termId;

@property NSInteger priority;

@property (nonatomic) NSArray *modifiers;

+ (NSArray *)proceduresFromArray:(NSArray *)array;

@end
