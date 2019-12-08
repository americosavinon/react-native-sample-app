//
//  AWSDKVisitExtension.h
//  AWSDK
//
//  Created by Calvin Chestnut on 12/11/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObject.h"

typedef NS_ENUM(NSInteger, AWSDKExtensionType) { FREE_EXTENSION, PAID_EXTENSION, NO_EXTENSION };

@interface AWSDKVisitExtension : AWSDKDataObject

@property AWSDKExtensionType extensionType;

@property double cost;

@property int extraTime;

@end
