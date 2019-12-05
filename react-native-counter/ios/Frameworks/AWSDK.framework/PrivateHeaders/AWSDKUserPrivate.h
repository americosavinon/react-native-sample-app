//
//  AWSDKUserPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 6/30/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWCoreNameProtocol.h"

#import <AWSDK/AWSDKUser.h>

/**
 A User of American Well's telehealth platform.

 @since 1.0.0
 */
@interface AWSDKUser : AWSDKDataObject <AWSDKUser, AWCoreNameProtocol>

@property (nonatomic, readwrite, nonnull) NSPersonNameComponents *nameComponents;
@property (nonatomic, readonly, nonnull) NSString *fullName;

+ (NSNumber *_Nullable)validateGender:(AWSDKBiologicalSex)gender;

@end
