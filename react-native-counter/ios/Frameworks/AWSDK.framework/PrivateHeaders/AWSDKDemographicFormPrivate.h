//
//  AWSDKDemographicDataPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 6/2/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKFormPrivate.h"

#import <AWSDK/AWSDKDemographicForm.h>

typedef NS_ENUM(NSUInteger, DemographicFormType) { FormTypeEnrollment = 1, FormTypeUpdate = 2 };

@interface AWSDKDemographicForm ()

- (NSMutableDictionary *)enrollmentErrorDictionary;

- (NSMutableDictionary *)updateErrorDictionary;

- (NSDictionary *)toParams;

@property (nonatomic, assign) DemographicFormType type;

@end
