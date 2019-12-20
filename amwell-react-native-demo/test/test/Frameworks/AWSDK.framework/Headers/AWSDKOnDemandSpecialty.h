//
//  AWSDKOnDemandSpecialty.h
//  AWSDK
//
//  Created by Calvin Chestnut on 2/18/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A grouping protocol that contains one or more provider types to filter by when performing a 'first available' search.

 @discussion Each practice can configure up to one AWSDKOnDemandSpecialty.

 @since 3.1.0
 */
@protocol AWSDKOnDemandSpecialty <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 BOOL set _TRUE_ if any providers of the specialty are currently on call for a first available visit, otherwise _FALSE_ if none available.

 @since 1.0.0
 */
@property (readonly, assign) BOOL providersOnCall;

@end
