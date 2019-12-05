//
//  AWSDKProcedure.h
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
 A procedure that was or should be performed by a provider.

 @since 1.0.0
 */
@protocol AWSDKVisitProcedure <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSString representing the displayable name of the procedure.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *displayName;

/**
 NSString representing the description of the procedure.

 @since 1.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *procedureDescription;

/**
 BOOL set _TRUE_ if the procedure is billable, otherwise _FALSE_ if not.

 @note Only one billable procedure is allowed per visit.

 @since 1.0.0
 */
@property (assign, readonly) BOOL billable;

/**
 NSInteger representing the standard procedure code for the procedure.

 @since 1.0.0
 */
@property (assign, readonly) NSInteger code;

@end
