//
//  AWSDKVisitServicePrivate.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/27/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKVisitService.h>

@class AWSDKVisitContext, AWSDKConsumer, AWSDKProvider, AWSDKOnDemandSpecialty, AWSDKAppointment, AWSDKPractice, AWSDKProviderType, AWSDKConsumerOverrides, AWSDKModality;
/**
 Manages visit context validation, creating visits, starting visits, and creating the video console view controller.

 @since 3.0.0
 */
@interface AWSDKVisitService ()

#pragma mark - Singleton
/**
 @name Singleton
 */

/**
 Singleton accessor for AWSDKVisitService.

 @return The main AWSDKVisitService instance

 @since 3.0.0
 */
+ (instancetype)sharedInstance;

#pragma mark - Private Methods
/**
 @name Private Methods
 */

/**
 Fetches visitConfig information from the American Well Telehealth Platform for a potential visit, and returns an AWSDKVisitContext

 @discussion The AWSDKVisitContext may be a new visit, a dependent visit, a THN appointment, or a Find First Available visit. VisitConfig information is needed for all of these types of visit. The
 AWSDKVisitContext object is not generated in the NetworkingService completion block because there are certain properties that are only partially sent by the American Well Telehealth Platform
 (consumer & provider) which we have full objects for locally that give more complete information.

 @param consumer The consumer for whom the visit is for
 @param consumerProxy The AWSDKConsumer representing the party that is responsible for the dependent consumer having the visit.
 @param provider The AWSDKProvider the visit is targeted at
 @param specialty The AWSDKOnDemandSpecialty the visit is targeted at
 @param appointment The AWSDKAppointment the visit is for
 @param practice The AWSDKPractice source id if the visit is first available
 @param providerTypes The NSArray<NSString *> provider type if the visit is first available
 @param completion VisitContextCompletionBlock containing an AWSDKVisitContext and optionally an NSError

 @note If you provide an appointment to this method, all other fields must be nil. If you provide a consumerProxy, the consumer must be present. Provider and specialty are mutually exclusive in this
 context. Don't worry, we NSAssert all of this in the implementation.

 @since 4.2.0
 */
- (void)createVisitContextWithConsumer:(AWSDKConsumer *)consumer
                         consumerProxy:(AWSDKConsumer *)consumerProxy
                              provider:(AWSDKProvider *)provider
                             specialty:(AWSDKOnDemandSpecialty *)specialty
                           appointment:(AWSDKAppointment *)appointment
                              practice:(AWSDKPractice *)practice
                         providerTypes:(NSArray<AWSDKProviderType *> *)providerTypes
                            completion:(VisitContextCompletionBlock)completion;

/**
 Fetches visitConfig information from the American Well Telehealth Platform for a potential visit, and returns an AWSDKVisitContext

 @discussion The AWSDKVisitContext may be a new visit, a dependent visit, a THN appointment, or a Find First Available visit. VisitConfig information is needed for all of these types of visit. The
 AWSDKVisitContext object is not generated in the NetworkingService completion block because there are certain properties that are only partially sent by the American Well Telehealth Platform
 (consumer & provider) which we have full objects for locally that give more complete information.

 @param consumer The consumer for whom the visit is for
 @param consumerProxy The AWSDKConsumer representing the party that is responsible for the dependent consumer having the visit.
 @param provider The AWSDKProvider the visit is targeted at
 @param specialty The AWSDKOnDemandSpecialty the visit is targeted at
 @param appointment The AWSDKAppointment the visit is for
 @param completion VisitContextCompletionBlock containing an AWSDKVisitContext and optionally an NSError

 @note If you provide an appointment to this method, all other fields must be nil. If you provide a consumerProxy, the consumer must be present. Provider and specialty are mutually exclusive in this
 context. Don't worry, we NSAssert all of this in the implementation.

 @since 4.1.0
 */
- (void)createVisitContextWithConsumer:(AWSDKConsumer *)consumer
                         consumerProxy:(AWSDKConsumer *)consumerProxy
                              provider:(AWSDKProvider *)provider
                             specialty:(AWSDKOnDemandSpecialty *)specialty
                           appointment:(AWSDKAppointment *)appointment
                            completion:(VisitContextCompletionBlock)completion;
@end
