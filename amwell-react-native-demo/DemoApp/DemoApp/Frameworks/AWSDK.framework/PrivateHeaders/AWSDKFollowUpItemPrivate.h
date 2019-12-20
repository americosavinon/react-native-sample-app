//
//  AWSDKFollowUpItemPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 11/30/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKDataObjectPrivate.h"

#import <AWSDK/AWSDKFollowUpItem.h>

/**
 A suggested follow-up action that the consumer should take.

 @since 1.0.0
 */
@interface AWSDKFollowUpItem : AWSDKDataObject <AWSDKFollowUpItem>
+ (NSArray *)arrayFromItems:(NSArray *)array;

+ (AWSDKFollowUpItemType)typeForString:(NSString *)typeName;

@end
