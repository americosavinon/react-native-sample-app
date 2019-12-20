//
//  AWSDKDiagnosis.h
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

#import <AWSDK/AWSDKDataObject.h>

/**
 A diagnosis provided by a provider during or after a telehealth visit.

 @since 1.0.0
 */
@protocol AWSDKVisitDiagnosis <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the displayable name of the diagnosis.

 @since 1.0.0
 */
@property (nonatomic, nonnull) NSString *displayName;

/**
 NSString representing the description of the diagnosis.

 @since 1.0.0
 */
@property (nonatomic, nonnull) NSString *diagnosisDescription;

/**
 NSInteger representing the standard diagnosis code for the diagnosis.

 @since 1.0.0
*/
@property (assign, readonly) NSInteger code;

@end
