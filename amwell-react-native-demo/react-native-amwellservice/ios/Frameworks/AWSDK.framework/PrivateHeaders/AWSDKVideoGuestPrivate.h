//
//  AWSDKVideoGuestPrivate.h
//  AWSDK
//
//  Created by Calvin Chestnut on 4/29/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import "AWSDKCompletionBlock.h"
#import "AWSDKDataObjectPrivate.h"
#import "AWSDKVisitPrivate.h"

extern NSString *_Nonnull const ConferenceStatusStarted;
extern NSString *_Nonnull const ConferenceStatusWaiting;
extern NSString *_Nonnull const ConferenceStatusEnded;
extern NSString *_Nonnull const ConferenceStatusCancelled;
extern NSString *_Nonnull const ConferenceStatusDisabled;

@class AWCoreVidyoAccountInfo, AWSDKGuestConsoleViewController, AWSDKConference;

@interface AWSDKVideoGuest : AWSDKDataObject <AWCoreGuestUserProtocol>
@property (nonatomic, nonnull) AWCoreVidyoAccountInfo *accountInfo;
@property (nonatomic, nonnull) NSString *videoPortal;
@property (nonatomic, nonnull) NSString *conferenceStatus;
@property (nonatomic, weak, nullable) id<AWCoreVisitPollingDelegate> console;
@property (nonatomic) NSInteger minRemaining;
@property (nonatomic) NSInteger millisecondsRemaining;
@property (nonatomic) BOOL hidePatientTimer;
@property (nonatomic, readonly) BOOL isPolling;

/**
 AWSDKConference representing a meeting space between 2 or more participants.

 @since 5.0.0
 */
@property (nonatomic, readwrite, nonnull) AWSDKConference *conference;

- (void)startPolling;

- (void)stopPolling;

- (void)updateVisitWithCompletion:(nullable GenericCompletionBlock)completion;

- (void)didJoinConferenceWithCompletion:(nullable GenericCompletionBlock)completion;

@end
