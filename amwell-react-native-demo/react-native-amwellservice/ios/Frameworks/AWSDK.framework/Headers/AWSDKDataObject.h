//
//  AWSDKDataObject.h
//
//  Created by Calvin Chestnut on 8/31/15.
//  Copyright (c) 2014 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 Root Data Object Protocol for AWSDK Classes.

 @since 3.1.0
 */
@protocol AWSDKDataObject <NSObject>
@end

/**
 Root Data Object for AWSDK Classes.

 @since 1.0.0
 */
@interface AWSDKDataObject : NSObject <NSCopying, AWSDKDataObject>
#pragma mark - Overrides
/**
 @name Overrides
 */

/**
 Init method unavailable, check subclass for info on how to create new instance.

 @return Attempting to use init will result in compiler error.

 @since 1.0.0
 */
- (nonnull instancetype)init __attribute__((unavailable("init not available")));
@end
