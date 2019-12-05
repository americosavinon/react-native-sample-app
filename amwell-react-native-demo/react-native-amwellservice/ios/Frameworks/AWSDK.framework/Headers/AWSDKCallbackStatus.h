//
//  AWSDKCallbackStatus.h
//  AWSDK
//
//  Created by Jeremiah.Possion on 1/5/17.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

/**
 NS_ENUM to represent the status of a callback.

 @discussion AWSDKCallbackStatusRequested will be set on the AWSDKVisit object's
 callback Status property if the consumer has initiated a callback. Once each party has
 been successfully connected you will receive the AWSDKCallbackStatusConnected status.

 @since 3.0.0
 */
typedef NS_ENUM(NSInteger, AWSDKCallbackStatus) {

    /**
     There was an unknown status returned.

     @since 3.0.0
     */
    AWSDKCallbackStatusUnknown,

    /**
     The consumer initiated a mobile callback.

     @since 3.0.0
     */
    AWSDKCallbackStatusRequested,

    /**
     The callback has timed out.

     @since 3.0.0
     */
    AWSDKCallbackStatusTimeout,

    /**
     The consumer is being called.

     @since 3.0.0
     */
    AWSDKCallbackStatusDialingConsumer,

    /**
     The Consumer didn't answer.

     @since 3.0.0
     */
    AWSDKCallbackStatusConsumerUnreachable,

    /**
     The consumer could not be reached.

     @since 3.0.0
     */
    AWSDKCallbackStatusConsumerFailed,

    /**
     The provider is being called.

     @since 3.0.0
     */
    AWSDKCallbackStatusDialingProvider,

    /**
     Reserved for future use.

     @since 3.0.0
     */
    AWSDKCallbackStatusProviderUnreachable,

    /**
     The provider could not be reached.

     @since 3.0.0
     */
    AWSDKCallbackStatusProviderFailed,

    /**
     The provider and consumer have successfully connected.

     @since 3.0.0
     */
    AWSDKCallbackStatusConnected,

    /**
     The IVR Request has been queued.

     @since 4.3.0
     */
    AWSDKCallbackStatusQueued,
};
