//
//  AWSDKChatItem.h
//  AWSDK
//
//  Created by Steven Uy on 9/13/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKDataObject.h>

/**
 User type of the user who created the chat item.

 @since 2.1.0
 */
typedef NS_ENUM(NSInteger, AWSDKChatUserType) {
    /**
     Unknown or anonymous user.

     @since 2.1.0
     */
    AWSDKUserTypeUnknown,
    /**
     Provider of the visit.

     @since 2.1.0
     */
    AWSDKUserTypeProvider,
    /**
     Assistant of the visit.

     @since 2.1.0
     */
    AWSDKUserTypeAssistant,
    /**
     Consumer or dependent of the visit.

     @since 2.1.0
     */
    AWSDKUserTypeConsumer,
    /**
     System or practice admin.

     @since 2.1.0
     */
    AWSDKUserTypeAdmin,
};

@protocol AWSDKUser;

/**
 Individual chat message protocol and associated metadata.

 @since 3.1.0
 */
@protocol AWSDKChatItem <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 AWSDKUser that sent the message, otherwise _nil_ if the chat item is a system "message", see messageType.

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKUser> user;

/**
 NSString representing the unformatted message sent.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSString *message;

/**
 NSUInteger position in the chat log in relation to the other chat items.

 @note These ordinals do not necessarily start from 0 as some system items are not exposed. Ordinals are not guaranteed to be consecutive (1,2,3) but are guaranteed to be in-order (1, 3, 4).

 @since 2.1.0
 */
@property (readonly, nonatomic) NSUInteger ordinal;

/**
 NSDate the message was sent.

 @since 2.1.0
 */
@property (nonatomic, readonly, nonnull) NSDate *timeStamp;

/**
 NSString representing the message type of chat item, otherwise _nil_ by default.

 @discussion Most messageTypes are system messages. Few example types are listed below.

 | messageType  | Description                                             |
 |--------------|:-------------------------------------------------------:|
 | Extend       | System "message" for whom extended the visit.           |
 | Encoder      | System "message" for items being added such as diagnoses|
 | Note         | System "message" for note items added.                  |
 | Followup     | System "message" for follow up items added.             |

 @since 2.1.0
 */
@property (nonatomic, readonly, nullable) NSString *messageType;

/**
 AWSDKChatUserType of the user that created the chat item.

 @since 2.1.0
 */
@property (assign, nonatomic, readonly) AWSDKChatUserType userType;

@end
