//
//  AWSDKMedication.h
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

#import <AWSDK/AWSDKDataObject.h>

/**
 A medication protocol in the American Well system.

 @since 3.1.0
 */
@protocol AWSDKMedication <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the description of the medication.

 @since 1.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *medicationDescription;

/**
 NSString representing the displayable name of the medication.

 @since 1.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *displayName;
@end
