//
//  AWSDKSystemConfigurationPrivate.h
//  AWSDK
//
//  Created by Steven Uy on 7/14/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKSystemConfiguration.h>

@class AWSDKLanguage, AWSDKHealthTrackerType, AWSDKICEServer;

@interface AWSDKSystemConfiguration ()

@property (nonatomic, assign, readonly, getter=isConsumerMiddleInitialCollected) BOOL consumerMiddleInitialCollected;
@property (nonatomic, assign, readonly, getter=isConsumerAddressRequired) BOOL consumerAddressRequired;
@property (nonatomic, assign, readonly, getter=isMultiWayVideoAllowed) BOOL multiWayVideoAllowed;
@property (nonatomic, assign, readonly, getter=isMultiCountry) BOOL multiCountry;
@property (nonatomic, assign, readonly, getter=areEndVisitRatingsOptional) BOOL endVisitRatingsOptional;
@property (nonatomic, assign, readonly, getter=showProviderRatings) BOOL showProviderRatings;
@property (nonatomic, assign, readonly, getter=isServiceKeyCollected) BOOL serviceKeyCollected;
@property (nonatomic, assign, readonly, getter=isMemberHealthInsuranceCollected) BOOL memberHealthInsuranceCollected;
@property (nonatomic, assign, readonly, getter=isCancelAppointmentEnabled) BOOL cancelAppointmentEnabled;
@property (nonatomic, assign, readwrite, getter=isCallbackViaPhoneEnabled) BOOL callbackViaPhoneEnabled;
@property (nonatomic, assign, readwrite, getter=isOtherTopicEnabled) BOOL otherTopicEnabled;
@property (nonatomic, assign, readwrite, getter=isVibrateOnVisitJoinEnabled) BOOL vibrateOnVisitJoinEnabled;
@property (nonatomic, assign, readwrite, getter=isSoundOnVisitJoinEnabled) BOOL soundOnVisitJoinEnabled;
@property (nonatomic, assign, readwrite, getter=isRefreshAndGuestButtonHiddenWhenDisabled) BOOL refreshAndGuestButtonHiddenWhenDisabled;
@property (nonatomic, assign, readonly, getter=isAppointmentReadinessCheckEnabled) BOOL appointmentReadinessCheckEnabled;
@property (nonatomic, assign, readonly) NSInteger scheduledEngagementMarginMs;
@property (nonatomic, assign, readonly) NSInteger maxVideoInvites;
@property (nonatomic, readonly) NSString *cancelAppointmentDisabledText;
@property (nonatomic, readonly) NSString *currencyCode;
@property (nonatomic, readonly) NSArray *extensionBlacklist;
@property (nonatomic, readonly) NSSet *mimeWhitelist;
@property (nonatomic, readonly) NSArray *supportedLocales;
@property (nonatomic, readonly) NSArray *healthTrackerTypes;
@property (nonatomic, readonly) NSSet *mimeBlacklist;
@property (nonatomic, assign, readonly) NSInteger messageAttachmentMax;
@property (nonatomic, assign, readonly) NSInteger appointmentMarginMS;
@property (nonatomic) NSArray<AWSDKICEServer *> *iceServers;
@property (nonatomic) NSArray<AWSDKLanguage *> *validLanguages;
@property (nonatomic, readwrite) NSString *pathToVisitJoinSound;
@property (nonatomic) NSSet<NSString *> *protectedFields;
@property (nonatomic) AWSDKConsumerMiddleNameHandling middleNameHandling;

- (BOOL)isProtectedField:(NSString *)key;

#pragma mark - Private Static

+ (BOOL)isConsumerAddressRequired;

+ (BOOL)isConsumerMiddleInitialCollected;

+ (BOOL)areEndVisitRatingsOptional;

+ (NSArray *)extensionBlacklist;

+ (NSSet *)mimeBlacklist;

+ (NSSet *)mimeWhitelist;

+ (NSString *)mimeTypeForExtension:(NSString *)ext;

+ (NSInteger)appointmentMarginMS;

+ (NSArray<AWSDKICEServer *> *)iceServers;

+ (void)logVisitConfiguration;

@end
