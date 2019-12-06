//
//  AWSDKVisitDisposition.h
//  AWSDK
//
//  Created by Steven Uy on 11/18/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

/**
 Visit disposition enum representing the current state of the visit.

 @since 2.0.0
 */
typedef NS_OPTIONS(NSUInteger, AWSDKVisitDisposition) {
    /**
     An unknown failure occurred.

     @since 2.0.0
     */
    AWSDKVisitDispositionUndefined = 0,

    /**
     Internal Use only

     @since 4.2.0
     */
    AWSDKVisitDispositionUnpublished = 1 << 0,
    /**
     The visit has been created but not scheduled yet.

     @since 2.0.0
     */
    AWSDKVisitDispositionUnscheduled = 1 << 1,
    /** The visit has been scheduled.

     @since 2.0.0
     */
    AWSDKVisitDispositionScheduled = 1 << 2,
    /**
     Consumer is waiting for a provider to become available

     @since 4.2.0
     */
    AWSDKVisitDispositionParked = 1 << 3,
    /**
     The consumer canceled the visit before the visit or during the visit before the provider joins the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionConsumerCanceled = 1 << 4,
    /**
     The consumer disconnected from the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionConsumerDisconnected = 1 << 5,
    /**
     The provider declined the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionProviderDeclined = 1 << 6,
    /**
     Internal use only

     @since 4.2.0
     */
    AWSDKVisitDispositionProviderResponseTimeout = 1 << 7,
    /**
     The provider canceled the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionProviderCanceled = 1 << 8,
    /**
     The provider has disconnected from the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionProviderDisconnected = 1 << 9,
    /**
     The visit has ended but the provider is completing the wrap-up.

     @since 2.0.0
     */
    AWSDKVisitDispositionProviderWrapUp = 1 << 10,
    /**
     The consumer has completed intake and is waiting for the provider to join the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionPreVisit = 1 << 11,
    /**
     The consumer and provider are in the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionInVisit = 1 << 12,
    /**
     The provider and consumer have finished the visit and the consumer is with an assistant after the visit.

     @note Post visit chat is not supported by the SDK.

     @since 2.0.0
     */
    AWSDKVisitDispositionPostVisit = 1 << 13,
    /**
     The consulting provider has completed wrap-up but the primary provider hasn't completed wrap-up in a P2P visit.

     @note This is not used by the SDK.

     @since 2.0.0
     */
    AWSDKVisitDispositionConsultingProviderWrappedUp = 1 << 14,
    /**
     The visit has completed.

     @since 2.0.0
     */
    AWSDKVisitDispositionCompleted = 1 << 15,
    /**
     Internal use only

     @since 4.2.0
     */
    AWSDKVisitDispositionError = 1 << 16,
    /**
     The visit was removed and was unscheduled previously.

     @note This is not used by the SDK.

     @since 2.0.0
     */
    AWSDKVisitDispositionDeleted = 1 << 17,
    /**
     The consumer missed the visit.

     @since 2.0.0
     */
    AWSDKVisitDispositionExpired = 1 << 18
};
