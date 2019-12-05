//
//  AWSDKModalityVendorPrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 3/5/19.
//  Copyright © 2019 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>
#import <Foundation/Foundation.h>

/**
 Entity for the modality vendor.

 @since 5.0.0
 */

@interface AWSDKModalityVendor : NSObject

/**
 NSString representing the name of the modality vendor.

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *name;

- (nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

/**
 Converts array of dictionary to array of AWSDKModalityVendor.

 @return A new array of AWSDKModalityVendor.

 @since 5.0.0
 */
+ (nonnull NSArray<AWSDKModalityVendor *> *)modalityVendorsFromArray:(nonnull NSArray *)array;

@end
