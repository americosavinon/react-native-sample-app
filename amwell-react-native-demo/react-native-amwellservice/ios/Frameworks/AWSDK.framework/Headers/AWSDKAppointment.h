//
//  AWSDKAppointment.h
//  AWSDK
//
//  Created by Calvin Chestnut on 3/11/16.
//  Copyright © 2018 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <AWSDK/AWSDKCompletionBlock.h>
#import <AWSDK/AWSDKDataObject.h>
#import <AWSDK/AWSDKVisitDisposition.h>

// clang-format off
@protocol AWSDKProvider, AWSDKVisitTopic, AWSDKConsumer, AWSDKSchedule, AWSDKProviderType, AWSDKReminderOption, AWSDKModality, AWSDKAppointmentRecordForm;
// clang-format on

/**
 Appointment Status Enum representing the status of the appointment.

 @since 1.0.0
 */
typedef NS_ENUM(NSUInteger, AWSDKAppointmentStatus) {
    /**
     Consumer is early to the appointment

     @since 1.0.0
     */
    Early,
    /**
     Consumer is on time to the appointment and it may be started

     @since 1.0.0
     */
    OnTime,
    /**
     Consumer has missed the appointment

     @since 1.0.0
     */
    Late,
    /**
     Consumer is on time to the appointment with the first available provider, but no provider can be found

     @since 1.0.0
     */
    NoProvider,
    /**
     Unexpected Value

     @since 1.0.0
     */
    Other
};

/**
 An appointment in the telehealth platform.

 @since 3.1.1
 */
@protocol AWSDKAppointment <AWSDKDataObject>

#pragma mark - Read-Only Properties
/**
 @name Read-Only Properties
 */

/**
 NSArray of AWSDKReminderOption objects containing a display string and integer value for each reminder option available.

 @since 3.2.0
 */
@property (class, nonatomic, nonnull, readonly) NSArray<id<AWSDKReminderOption>> *availableReminderOptions;

/**
 AWSDKConsumer representing the person for whom the visit is for. This can be either the account owner or a dependent.

 @since 4.1.0
 */
@property (nonatomic, nonnull, readonly) id<AWSDKConsumer> consumer;

/**
 AWSDKConsumer If this appointment was scheduled for a dependent, consumerProxy represents the parent conducting the visit
 on behalf of their child. Otherwise, this field is nil.

 @since 4.1.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKConsumer> consumerProxy;

/**
 AWSDKProvider representing the provider for the appointment.

 @discussion If the appointment is set as first available provider, the provider will be _nil_ until the start time of the visit. Then the server will attempt to assign an available provider of
 providerType. If no providers are available at this time, status will be _NoProvider_.

 @since 1.0.0
 */
@property (nonatomic, nullable, readonly) id<AWSDKProvider> provider;

/**
 AWSDKProviderType specialty for the provider.

 @discussion If the appointment is set as first available provider, the providerType is populated with the specialty to find a provider for. Otherwise providerType is set as the specialty of the
 provider.

 @since 2.0.0
 */
@property (nonatomic, nonnull, readonly) id<AWSDKProviderType> providerType;

/**
 NSString name of the practice the provider is a member of.

 @since 1.0.0
 */
@property (nonatomic, nonnull, readonly) NSString *practiceName;

/**
 AWSDKSchedule for the appointment, including start time and duration.

 @since 1.0.0
 */
@property (nonatomic, nonnull, readonly) id<AWSDKSchedule> schedule;

/**
 NSString note to the consumer or dependent sent by the provider.

 @since 2.1.0
 */
@property (nonatomic, nullable, readonly) NSString *note;

/**
 NSArray of AWSDKVisitTopic items for the appointment.

 @since 1.0.0
 */
@property (nonatomic, nonnull, readonly) NSArray<id<AWSDKVisitTopic>> *topic;

/**
 AWSDKAppointmentStatus of the appointment.

 @since 1.0.0
 */
@property (readonly) AWSDKAppointmentStatus status;

/**
 AWSDKVisitDisposition of the appointment representing the current state.

 @since 2.0.0
 */
@property (readonly) AWSDKVisitDisposition disposition;

/**
 NSString representing the sourceId of the appointment.

 @since 4.1.1
 */
@property (nonatomic, readonly, nullable) NSString *sourceId;

/**
 AWSDKModality of the visit representing the communication mode.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) id<AWSDKModality> modality;

/**
 NSString of the initiator engagement override phone number.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSString *initiatorEngagementOverridePhone;

/**
 NSString of the formatted initiator engagement override phone number.

 @since 4.3.0
 */
@property (nonatomic, readonly, nullable) NSString *formattedInitiatorEngagementOverridePhone;

#pragma mark - Methods
/**
 @name Methods
 */

/**
 Cancels the appointment.

 @param completion GenericCompletionBlock containing _TRUE_ if successful, otherwise _FALSE_ and an NSError explaining any failures.

 @since 1.0.0
 */
- (void)cancelAppointmentWithCompletion:(nullable GenericCompletionBlock)completion;

/**
 Updates an appointment with records from the form.

 @param form        AWSDKAppointmentRecordForm containing the updated records in the appointment.
 @param completion  GenericCompletionBlock containing _TRUE_ if the appointment was successfully updated, otherwise _FALSE_ and an NSError explaining any error cases.

 @since 4.3.0
 */
- (void)updateAppointmentWithForm:(nonnull id<AWSDKAppointmentRecordForm>)form completion:(nullable GenericCompletionBlock)completion;

/**
 Fetches the appointment.

 @discussion Used to obtain a new instance of an appointment

 @param completion containing an AWSDKAppointment object, or an NSError explaining the error.

 @since 4.3.0
 */
- (void)fetchUpdated:(nonnull AppointmentCompletionBlock)completion;

#pragma mark - Helper Methods
/**
 @name Helper Methods
 */

/**
 Determines if the appointment is ready to start.

 @discussion The server sends a configurable value indicating the margin around the visit start time during which the visit can be started. This method will check the scheduled time against the start
 time and return a boolean value indicating if the current time is within that margin.

 @return Boolean value indicating if the visit start time is within the allowed margin.

 @since 1.0.0
 */
- (BOOL)readyToStart;
@end

/**
 An appointment in the telehealth platform.

 @since 1.0.0
 */
@interface AWSDKAppointment : AWSDKDataObject <AWSDKAppointment>
#pragma mark - Appledoc
@property (readonly) AWSDKAppointmentStatus status;
#pragma mark -
@end
