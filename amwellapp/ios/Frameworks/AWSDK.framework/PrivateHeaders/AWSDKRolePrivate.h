//
//  AWSDKRolePrivate.h
//  AWSDK
//
//  Created by Rolin Nelson on 3/6/18.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

/**
 The role type enum representing the permissable roles a participant may take in a conference.

 @since 5.0.0
 */
typedef NS_ENUM(NSUInteger, AWSDKRoleType) {
    /**
     An unknown role type.

     @since 5.0.0
     */
    AWSDKRoleTypeUndefined,

    /**
     A tester role type.

     @since 5.0.0
     */
    AWSDKRoleTypeTester,

    /**
     A consumer role type.

     @since 5.0.0
     */
    AWSDKRoleTypeMember,

    /**
     A provider role type.

     @since 5.0.0
     */
    AWSDKRoleTypeProvider,

    /**
     A translator role type.

     @since 5.0.0
     */
    AWSDKRoleTypeTranslator,

    /**
     A facilitator role type.

     @since 5.0.0
     */
    AWSDKRoleTypeFacilitator,

    /**
     A guests of the consumer role type.

     @since 5.0.0
     */
    AWSDKRoleTypeMemberGuest,

    /**
     A guests of the provider role type.

     @since 5.0.0
     */
    AWSDKRoleTypeProviderGuest,
};

@interface AWSDKRole : NSObject
/**
 Converts a role name to a role type.

 @return A AWSDKRoleType enumeration value.

 @since 5.0.0
 */
+ (AWSDKRoleType)roleTypeFromName:(NSString *)name;

@end
