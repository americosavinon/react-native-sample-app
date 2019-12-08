//
//  AWSDKConferenceParticipantPrivate.h
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

#import "AWSDKRolePrivate.h"

#import <AWSDK/AWSDKModalityType.h>

/**
 A participant of a conference.

 @since 5.0.0
 */
@interface AWSDKConferenceParticipant : NSObject

/**
 NSDate representing the date the conference was added to the American Well teleheath platform.

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) NSDate *addDate;

/**
 BOOL representing whether or not the participant has joined the conference.

 @since 5.0.0
 */
@property (nonatomic, readonly) BOOL isJoined;

/**
 AWSDKRoleType representing the role of the participant in this conference.

 @since 5.0.0
 */
@property (nonatomic, readonly) AWSDKRoleType roleType;

/**
 NSString representing the unique ID for this participant provided by the vendor.

 @since 5.0.0
 */
@property (nonatomic, readonly, nullable) NSString *vendorId;

/**
 AWSDKModalityCode representing the modality type of the Connection the participant used to initially connect to the conference.

 @since 5.0.0
 */
@property (nonatomic, readonly) AWSDKModalityType modalityType;

/**
 Converts array of dictionary to array of AWSDKConferenceParticipant.

 @return A new array of AWSDKConferenceParticipant.

 @since 5.0.0
 */
+ (nonnull NSArray<AWSDKConferenceParticipant *> *)conferenceParticipantsFromArray:(nonnull NSArray *)array;

- (nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
