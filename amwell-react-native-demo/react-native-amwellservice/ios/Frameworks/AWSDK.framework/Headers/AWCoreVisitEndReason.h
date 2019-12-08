//
//  AWCoreVisitEndReason.h
//  AWCore
//
//  Created by Calvin Chestnut on 10/22/15.
//  Copyright © 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#ifndef AWCoreVisitEndReason_h
#define AWCoreVisitEndReason_h

/**
 NS_ENUM to represent the reason why a visit ended.
 
 @discussion Successful visits have the following AWCoreVisitEndReasons:
 AWCoreVisitEndReasonConsumerEnd,
 AWCoreVisitEndReasonProviderEnd,
 AWCoreVisitEndReasonVisitExpired,
 AWCoreVisitEndReasonVisitEnded,
 
 @since 1.0.0
 */
typedef NS_ENUM(NSInteger, AWCoreVisitEndReason) {
    /**
     There was an unknown error.
     
     @since 2.1.0
     */
    AWCoreVisitEndReasonUnknown,
    /**
     An assistant declined the visit and the consumer has been transferred to a different provider.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonAssistantDeclineAndTransfer,
    /**
     The consumer has not enabled the necessary permissions for a telehealth visit.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonPermissionsError,
    /**
     The allotted time for the visit has expired.
     
     @note This is a successful visit.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonVisitExpired,
    /**
     Consumer disconnected from the visit after the visit threshold time and will be billed.
     
     @since 2.1.0
     */
    AWCoreVisitEndReasonConsumerDisconnectPostThreshold,
    /**
     Consumer disconnected from the visit before the visit threshold time and will not be billed.
     
     @since 2.1.0
     */
    AWCoreVisitEndReasonConsumerDisconnectPreThreshold,
    /**
     Consumer has been disconnected by an Admin.
     
     @since 2.1.0
     */
    AWCoreVisitEndReasonConsumerForcedDisconnect,
    /**
     Consumer cancelled the visit before it started.
     
     @since 2.1.0
     */
    AWCoreVisitEndReasonConsumerCancel,
    /**
     Consumer ended the visit.
     
     @note This is a successful visit.
     
     @since 2.1.0
     */
    AWCoreVisitEndReasonConsumerEnd,
    /**
     The provider declined the visit.
     
     @note This is a successful visit.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonProviderDeclined,
    /**
     The provider declined the visit and the consumer has been transferred to a different provider.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonProviderDeclineAndTransfer,
    /**
     The provider canceled the visit after the visit timer started.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonProviderBail,
    /**
     The provider has been disconnected from the telehealth platform.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonProviderDisconnect,
    /**
     The provider is no longer available due to a logout event.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonProviderLogout,
    /**
     A provider's assistant declined the visit.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonAssistantDecline,
    /**
     The provider is no longer available due to an availability change event.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonWaitingRoomExpired,
    /**
     The provider has ended the visit.
     
     @note This is a successful visit.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonProviderEnd,
    /**
     There was an unexpected error starting the IVR visit.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonConsumerOutdialFailed,
    /**
     Connection to the video conference service failed
     
     @since 3.2.2
     */
    AWCoreVisitEndReasonVideoHostFailed,
    /**
     The time limit for the application being in the background during a visit has been exceeded
     
     @since 3.2.2
     */
    AWCoreVisitEndReasonBackgroundTimeLimitExceeded,
    /**
     A successful visit has ended and the consumer has been manually transferred to a different provider.
     
     @since 3.2.0
     */
    AWCoreVisitEndReasonPostVisitTransfer,
    /**
     Visit ended without specification for whom ended the visit.
     
     @note This is a successful visit. This end reason typically appears during a visit as a guest.
     
     @since 1.0.0
     */
    AWCoreVisitEndReasonVisitEnded,
    /**
     The consumer failed to connect via IVR (didn't pick up the phone, or wrong PIN).
     
     @since 4.3.0
     */
    AWCoreVisitEndReasonConsumerIVRAuthFailed,
    /**
     The provider failed to connect via IVR (didn't pick up the phone, or wrong PIN).
     
     @since 4.3.0
     */
    AWCoreVisitEndReasonProviderIVRAuthFailed,
    /**
     The initiator logged out during pre-visit screening
     
     @since 4.3.0
     */
    AWCoreVisitEndReasonInitiatorLogoutPreVisit,
    /**
     The initiator logged out after starting the visit with the provider
     
     @since 4.3.0
     */
    AWCoreVisitEndReasonInitiatorLogoutAfterStart,
    /**
     The provider did not respond in time.
     
     @since 4.3.0
     */
    AWCoreVisitEndReasonProviderResponseTimeout,
    /**
     An unexpected exception occurred while calculating the visit cost.
     
     @since 4.3.0
     */
    AWCoreVisitEndReasonCostCalculationFailed,
    /**
     The consumer has chosen to transfer to a different provider.
     
     @since 4.3.0
     */
    AWCoreVisitEndReasonConsumerTransfer,
};
#endif /* AWCoreNameProtocol_h */
