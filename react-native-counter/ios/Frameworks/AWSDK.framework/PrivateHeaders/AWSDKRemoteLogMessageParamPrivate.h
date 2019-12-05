//
//  AWSDKRemoteLogMessageParamPrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 9/6/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 This class is used by the logging API to send positional parameters used in the logging message.

 @since 4.2.2
 */
@interface AWSDKRemoteLogMessageParam : NSObject

#pragma mark - Constructor
/**
 @name Constructor
 */

/**
 NSString representing the message parameter's encryptedId.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nonnull) NSString *encryptedId;

/**
 NSString representing the message parameter's type.

 @since 4.2.0
 */
@property (nonatomic, readwrite, nonnull) NSString *type;

/**
 Creates a new instance of AWSDKRemoteLogMessageParam.

 @param type    NSString type of the parameter.
 @param dataObject  id representing AWSDKDataObject of the parameter.

 @return A new AWSDKRemoteLogMessageParam instance.

 @since 4.2.0
 */
+ (nonnull instancetype)logMessageParamForType:(nonnull NSString *)type dataObject:(nonnull id)dataObject;

@end
