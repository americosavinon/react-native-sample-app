//
//  AWSDKLanguage.h
//  AWSDK
//
//  Created by Steven Uy on 7/14/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 A provider spoken language protocol in the American Well telehealth platform.

 @since 3.1.0
 */
@protocol AWSDKLanguage <AWSDKDataObject>
#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 Displayable name of the language

 @since 2.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;
@end
