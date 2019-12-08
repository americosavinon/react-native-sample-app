//
//  AWSDKModalityPrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 11/12/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKModality.h>

@interface AWSDKModality : NSObject <AWSDKModality>

/**
 Converts array of dictionary to array of AWSDKModality.

 @return A new array of AWSDKModality.

 @since 4.3.0
 */
+ (NSArray<AWSDKModality *> *)modalitiesFromArray:(NSArray *)array;

/**
 Converts a modality name to a modality type.

 @return A AWSDKModalityCode enumeration value.

 @since 4.3.0
 */
+ (AWSDKModalityCode)modalityCodeFromName:(NSString *)name;

/**
 Converts a modality type to a modality type.

 @return A AWSDKModalityType enumeration value.

 @since 5.0.0
 */
+ (AWSDKModalityType)modalityTypeFromName:(NSString *)name;

/**
 Converts a modality code to a modality name.

 @return A NSString representing the AWSDKModality name.

 @since 4.3.0
 */
+ (NSString *)modalityNameFromCode:(AWSDKModalityCode)type;

/**
 Converts a modality type to a modality name.

 @return A NSString representing the AWSDKModality name.

 @since 4.3.0
 */
+ (NSString *)modalityNameFromType:(AWSDKModalityType)type;

+ (instancetype)modalityForVideo;
+ (instancetype)modalityForPhone;

#pragma mark - Constructor

/**
 Creates a modality from a dictionary.

 @return A new AWSDKModality instance.

 @since 4.3.0
 */
- (instancetype)initWithDictionary:(NSDictionary *)json;

@end
