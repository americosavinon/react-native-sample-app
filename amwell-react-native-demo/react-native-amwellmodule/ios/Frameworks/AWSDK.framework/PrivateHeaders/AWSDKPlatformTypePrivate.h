//
//  AWSDKPlatformTypePrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 12/6/18.
//  Copyright © 2018 American Well. All rights reserved.
//

#import <AWSDK/AWSDKPlatformType.h>

@interface AWSDKPlatformType : NSObject <AWSDKPlatformType>

/**
 Converts array of dictionary to array of AWSDKPlatformType.

 @return A new array of AWSDKPlatformType.

 @since 4.3.0
 */
+ (NSArray<AWSDKPlatformType *> *)platformTypesFromArray:(NSArray *)array;

#pragma mark - Constructor

/**
 Creates a platformType from a dictionary.

 @return A new AWSDKPlatformType instance.

 @since 4.3.0
 */
- (instancetype)initWithDictionary:(NSDictionary *)json;

- (NSDictionary *)toParams;
- (AWSDKPlatformTypeID)typeFromPlatformName:(NSString *)name;
- (NSString *)nameFromPlatformType:(AWSDKPlatformTypeID)type;

@end
