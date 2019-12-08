//
//  AWSDKCountry.h
//  AWSDK
//
//  Created by Stephen Ciauri on 10/20/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

@protocol AWSDKState;

/**
 A physical Country protocol such as "United States" or "Mexico"

 @since 4.0.0
 */
@protocol AWSDKCountry <AWSDKDataObject>

/**
 NSString representing the displayable name of the country.

 @since 4.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 NSString as the short string to represent the country, e.g. 'US' or 'MX'.

 @since 4.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *code;

/**
 The list of states/political regions within the country.

 @note This field may be null in some cases

 @since 4.0.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKState>> *states;

/**
 The list of states/political regions within the country in which the telehealth platform has licensed providers.

 @note This field may be null in some cases

 @since 4.0.0
 */
@property (nonatomic, readonly, nullable) NSArray<id<AWSDKState>> *enrollmentStates;

@end
