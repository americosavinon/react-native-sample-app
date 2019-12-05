//
//  AWSDKConferencePrivate.h
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

#import <AWSDK/AWSDKModalityType.h>

// clang-format off
@class AWSDKConferenceParticipant, AWSDKConferenceMetrics;
// clang-format on

/**
 * A Conference object that represents a meeting space between 2 or more
 * participants. It provides functionality for linking engagements
 * together (i.e. transfers) and participants with different
 * visit modalities, e.g. ivr or video.

 @since 5.0.0
 */
@interface AWSDKConference : NSObject

/**
 NSDate representing the date the conference was added to the American Well teleheath platform.

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) NSDate *addDate;

/**
 NSString representing the Access Code that should be used to access this Conference.

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *accessCode;

/**
 NSString representing the Unique identifier (aka the room ID).

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) NSString *roomId;

/**
 NSURL representing the URL for Video modality service.

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) NSURL *serviceURL;

/**
 BOOL representing whether a conference is active.

 @since 5.0.0
 */
@property (nonatomic, readonly) BOOL isActive;

/**
 AWSDKModalityType representing the modality type that was selected when setting up this conference.

 @since 5.0.0
 */
@property (nonatomic, readonly) AWSDKModalityType selectedModalityType;

/**
 NSArray representing list of participants in the conference.

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) NSArray<AWSDKConferenceParticipant *> *participants;

/**
 AWSDKConferenceMetrics representing the metrics for this conference.

 @since 5.0.0
 */
@property (nonatomic, readonly, nonnull) AWSDKConferenceMetrics *metrics;

- (nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
