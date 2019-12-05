//
//  AWSDKConferenceMetrics.h
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

/**
 The metrics of a conference.

 @since 5.0.0
 */
@interface AWSDKConferenceMetrics : NSObject

/**
 BOOL representing whether all ConferenceParticipants are connected.

 @since 5.0.0
 */
@property (nonatomic, readonly) BOOL isAllConnected;

/**
 BOOL representing whether at least one consumer and one provider has connected.

 @since 5.0.0
 */
@property (nonatomic, readonly) BOOL hasAProviderAndMemberConnected;

/**
 NSInteger representing the number of participants in the role of provider that have connected.

 @since 5.0.0
 */
@property (nonatomic, readonly) NSInteger providersConnected;

/**
 NSInteger representing the number of participants in the role of facilitator that have connected.

 @since 5.0.0
 */
@property (nonatomic, readonly) NSInteger facilitatorsConnected;

/**
 NSInteger representing the number of participants in the role of translators that have connected.

 @since 5.0.0
 */
@property (nonatomic, readonly) NSInteger translatorsConnected;

/**
 NSInteger representing the number of participants conference communications in flight (still connecting).

 @since 5.0.0
 */
@property (nonatomic, readonly) NSInteger inflightCount;

/**
 NSInteger representing the number of participants who is currently disconnected from the visit (was able to connect at least once).

 @since 5.0.0
 */
@property (nonatomic, readonly) NSInteger disconnected;

/**
 NSInteger representing the number of participants whose communication failed (never successfully connected).

 @since 5.0.0
 */
@property (nonatomic, readonly) NSInteger failed;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
