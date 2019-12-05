//
//  AWSDKErrorCode.h
//  AWSDK
//
//  Created by Calvin Chestnut on 9/2/15.
//  Copyright (c) 2015 American Well.
//  All rights reserved.
//
//  It is illegal to use, reproduce or distribute
//  any part of this Intellectual Property without
//  prior written authorization from American Well.
//

#import <Foundation/Foundation.h>

/**
 Expected Error Codes. Most errors returned from AWSDK calls should return one of these predefined error codes if there are any problems with the request.

 @note As of 3.0.0, error codes are now generic and are used across different methods. Refer to the header files and the documentation for more information about the expected error cases.

 @since 1.0.0
 */
typedef NS_ENUM(NSInteger, AWSDKErrorCode) {

    /**
     Generic
     */

    /**
     The request failed for an unspecified reason.

     @since 3.0.0
     */
    AWSDKErrorCodeUnknownFailure,

    /**
     The SDK is unitialized. Initialize it is using [AWSDKService initializeWithLaunchParams:completion:];

     @since 3.0.0
     */
    AWSDKErrorCodeUninitialized,

    /**
     The request timed out.

     @since 2.1.2
     */
    AWSDKErrorCodeTimeout,

    /**
     The request or object is not available and cannot be performed.

     @since 3.0.0
     */
    AWSDKErrorCodeUnavailable,

    /**
     Value is not valid for this parameter.

     @since 1.0.0
     */
    AWSDKErrorCodeInvalidValue,

    /**
     Validation
     */

    /**
     A consumer with the given email address already exists.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationEmailInUse,

    /**
     The email and confirmation email doesn't match.

     @since 4.3.0
     */
    AWSDKErrorCodeValidationEmailMismatch,

    /**
     This consumer is already enrolled and should be directed to login.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationConsumerAlreadyEnrolled,

    /**
     Multiple matches were found when trying to enroll the consumer.

     @since 3.0.0
     */
    AWSDKErrorCodeValidateionMultipleMatchesFound,

    /**
     One or more partial matches were found when trying to enroll the consumer.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationPartialMatchFound,

    /**
     The consumer does not meet the minimum age required to use the system.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationConsumerUnderage,

    /**
     The dependent is over the maximum age allowed.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationDependentOverage,

    /**
     The dependents's DOB is after the current time.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationDependentDOBInFuture,

    /**
     The dependent is an existing dependent.

     @since 4.1.0
     */
    AWSDKErrorCodeValidationDependentMatchFound,

    /**
     The primary subscriber's DOB is after the current time.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationSubscriberDOBInFuture,

    /**
     One or more required parameters was missing or invalid in the request.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationRequiredParameterMissing,

    /**
     One or more required parameters was invalid in the request.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationRequiredParameterInvalid,

    /**
     One or more required parameters was too short in the request.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationRequiredParameterTooShort,

    /**
     The JSON returned from the American Well telehealth platform is malformed

     @since 3.1.0
     */
    AWSDKErrorCodeValidationMalformedJSON,

    /**
     A coordinate was sent in an invalid format.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadCoordinateFormat,

    /**
     An integer was sent in an invalid format.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadIntegerFormat,

    /**
     A date was sent in an invalid format.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadDateFormat,

    /**
     A timezone was sent in an invalid format.

     @since 4.3.0
     */
    AWSDKErrorCodeValidationBadTimezoneFormat,

    /**
     An unacceptable enum was provided.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadEnum,

    /**
     A enum was sent in an invalid format.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadEnumFormat,

    /**
     An unacceptable date was provided.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadDate,

    /**
     The employer code provided is not valid for this installation.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadEmployerCode,

    /**
     The group key provided is not valid for this installation.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadGroupKey,

    /**
     Generic enrollment error.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationEnrollmentError,

    /**
     Contact info is missing (for provider attempting to go on-call).

     @since 3.0.0
     */
    AWSDKErrorCodeValidationContactInfoMissing,

    /**
     Eligibility exception was thrown that the user can potentially fix by updating their information.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadEligibilityInformation,

    /**
     The provided eligibility request ID was invalid.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadEligibilityRequestID,

    /**
     Eligibility exception was thrown that can't be recovered from.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationEligibilityException,

    /**
     User tried to enroll a new account with a feed-controlled health plan.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationHPFeedControlled,

    /**
     The password supplied by the user did not meet one or more validation criteria.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationBadPassword,

    /**
     The user did not supply a valid coupon code.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationInvalidCoupon,

    /**
     The given term (diagnosis, procedure) cannot be added because it is blacklisted.

     @since 3.0.0
     */
    AWSDKErrorCodeValidationTermBlacklisted,

    /**
     Authentication
     */

    /**
     No device record was found for the given account key.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationDeviceNotFound,

    /**
     Required authentication info was not found on the request.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationInformationMissing,

    /**
     Logins are not currently allowed due to a scheduled system downtime.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationScheduledDowntime,

    /**
     The server is unexpectedly unavailable.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationSystemUnstable,

    /**
     The account you're trying to connect to is currently locked.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationAccountLocked,

    /**
     The account you're trying to connect to is currently inactive.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationAccountInactive,

    /**
     The authenticated user has no enrolled accounts.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationAccountNotEnrolled,

    /**
     This system does not currently support IOS.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationIOSDisabled,

    /**
     This system has disallowed DTC access via mobile.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationDTCNotAllowed,

    /**
     No pairing record existed on the Umbrella site.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationPairingNotFound,

    /**
     This device is not allowed to make this request.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationInvalidRequestForDevice,

    /**
     A client attempted to access a resource that it does not have permission to access. For example, a consumer tried
     to get secure messages that belong to another consumer.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationAccessDenied,

    /**
     A client attempted to access a resource but needs to authenticate first. For example, a consumer using a mobile
     client has PHI associated with their account and needs to authenticate first before getting into the app from an
     appointment link.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationRequired,

    /**
     Client attempted to authenticate while a session was already active. Currently only used for browser extensions
     attempting a web login when the user has an active session in another browser.

     @since 3.0.0
     */
    AWSDKErrorCodeAuthenticationConcurrentSession,

    /**
     Self Scheduling
     */

    /**
     Scheduled appointment check-in is early.

     @since 3.0.0
     */
    AWSDKErrorCodeSelfSchedulingCheckInEarly,

    /**
     Scheduled appointment check-in is late.

     @since 3.0.0
     */
    AWSDKErrorCodeSelfSchedulingCheckInLate,

    /**
     IVR (Callback)
     */

    /**
     Consumer outdial failed - either consumer never picked up, or consumer didn't enter correct PIN.

     @since 3.0.0
     */
    AWSDKErrorCodeIVROutdialFailed,

    /**
     External Authentication
     */

    /**
     External Authentication server returned a 204 NO DATA response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationNoContent,

    /**
     External Authentication server returned a 400 INVALID REQUEST response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationInvalidRequest,

    /**
     External Authentication server returned a 401 UNAUTHORIZED response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationUnauthorized,

    /**
     External Authentication server returned a 403 ACCESS DENIED response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationAccessDenied,

    /**
     External Authentication server returned a 404 NOT FOUND response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationNotFound,

    /**
     External Authentication server returned a 409 CONFLICT (Already Existing User) response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationConflict,

    /**
     External Authentication server returned a 500 SYSTEM ERROR (DB or Network) response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationSystemError,

    /**
     External Authentication server returned a 503 SYSTEM UNAVAILABLE response.

     @since 3.0.0
     */
    AWSDKErrorCodeExternalAuthenticationSystemUnavailable,

    /**
     Version Compatibility
     */

    /**
     This version of OnlineCare is not compatible with the client.

     @since 3.0.0
     */
    AWSDKErrorCodeVersionCompatibilityIncompatible,

    /**
     Required version information was missing from the request.

     @since 3.0.0
     */
    AWSDKErrorCodeVersionCompatibilityVersionInformationMissing,

    /**
     Consumer Specific
     */

    /**
     No consumer record was found with the given ID.

     @since 3.0.0
     */
    AWSDKErrorCodeConsumerNotFound,

    /**
     The member's primary pharmacy was not found.

     @since 3.0.0
     */
    AWSDKErrorCodeConsumerPharmacyNotFound,

    /**
     Consumer doesn't have a shipping address on file.

     @since 3.0.0
     */
    AWSDKErrorCodeConsumerShippingAddressNotFound,

    /**
     Consumer was busy.

     @since 3.0.0
     */
    AWSDKErrorCodeConsumerBusy,

    /**
     Secure Message
     */

    /**
     Invalid message type chosen.

     @since 3.0.0
     */
    AWSDKErrorCodeSecureMessageTypeInvalid,

    /**
     Secure Message Missing.

     @since 3.0.0
     */
    AWSDKErrorCodeSecureMessageMissing,

    /**
     Provider Related
     */

    /**
     The provider could not be found.

     @since 3.0.0
     */
    AWSDKErrorCodeProviderNotFound,

    /**
     The provider is not available.

     @since 3.0.0
     */
    AWSDKErrorCodeProviderNotAvailable,

    /**
     The provider is not online.

     @since 3.0.0
     */
    AWSDKErrorCodeProviderOffline,

    /**
     Provider was busy.

     @since 3.0.0
     */
    AWSDKErrorCodeProviderBusy,

    /**
     Provider cannot use Vidyo.

     @since 3.0.0
     */
    AWSDKErrorCodeProviderVidyoNotEnabled,

    /**
     Provider was not licensed for consumer's state.

     @since 3.0.0
     */
    AWSDKErrorCodeProviderNotLicensedForConsumersState,

    /**
     Health Plan
     */

    /**
     The Health Plan could not be found.

     @since 3.0.0
     */
    AWSDKErrorCodeHealthPlanNotFound,

    /**
     The Health Plan card image could not be found.

     @since 3.0.0
     */
    AWSDKErrorCodeHealthPlanCardImageNotFound,

    /**
     Waiting Room
     */

    /**
     Access to the waiting room was denied.

     @since 3.0.0
     */
    AWSDKErrorCodeWaitingRoomAccessDenied,

    /**
     Visit
     */

    /**
     User is already in a visit.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitUserAlreadyActive,

    /**
     No patients waiting for this provider.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitNoPatientsWaiting,

    /**
     Connection to the Vidyo server failed.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitVidyoFailure,

    /**
     Visit not found.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitNotFound,

    /**
     Visit consumer doesn't match user trying to enter visit.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitInitiatorMismatch,

    /**
     Visit consumer doesn't have a valid phone number.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitInitiatorInvalidPhoneNumber,

    /**
     Visit's disposition is no longer valid.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitInvalidDisposition,

    /**
     Visit is expired.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitExpired,

    /**
     Visit couldn't start for some reason.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitGenericFailure,

    /**
     Visit doesn't have multi way video enabled.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitMultiWayVideoNotEnabled,

    /**
     Attempting to invite more than the supported maximum number of guests.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitTooManyVideoInvites,

    /**
     Issue encountered while scheduling a visit.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitSchedulingFailure,

    /**
     Can happen during the start of a visit.

     @since 3.0.0
     */
    AWSDKErrorCodeVisitCostCalculationFailed,

    /**
     Secure Message Attachments
     */

    /**
     Secure message attachment not found.

     @since 3.0.0
     */
    AWSDKErrorCodeSecureMessageAttachmentNotFound,

    /**
     IO Error occurred while reading attachment.

     @since 3.0.0
     */
    AWSDKErrorCodeSecureMessageAttachmentReadError,

    /**
     Payment Method
     */

    /**
     Credit Card Missing.

     @since 3.0.0
     */
    AWSDKErrorCodePaymentMethodCreditCardMissing,

    /**
     Credit Card Validation failed.

     @since 3.0.0
     */
    AWSDKErrorCodePaymentMethodCreditCardValidationError,

    /**
     Credit Card Declined.

     @since 3.0.0
     */
    AWSDKErrorCodePaymentMethodCreditCardDeclined,

    /**
     Credit Card Incorrect cvv.

     @since 3.0.0
     */
    AWSDKErrorCodePaymentMethodCreditCardIncorrectCVV,

    /**
     The user entered an invalid zip code.

     @since 3.0.0
     */
    AWSDKErrorCodePaymentMethodCreditCardInvalidZip,

    /**
     The users CC address doesn't match their location.

     @since 3.0.0
     */
    AWSDKErrorCodePaymentMethodCreditCardResidencyCheckFailed,

    /**
     Find First Available
     */

    /**
     The Find First Available status and report are not in sync.

     @since 3.0.0
     */
    AWSDKErrorCodeFindFirstAvailableInvalidState,

    /**
     No Find First Available ticket was available.

     @since 3.0.0
     */
    AWSDKErrorCodeFindFirstAvailableNoTicketAvailable,

    /**
     File upload
     */

    /**
     File failed virus scan.

     @since 3.0.0
     */
    AWSDKErrorCodeFileUploadVirusScanFailed,

    /**
     Invalid file type.

     @since 3.0.0
     */
    AWSDKErrorCodeFileUploadFileTypeInvalid,

    /**
     Unable to read in the file.

     @since 3.0.0
     */
    AWSDKErrorCodeFileUploadReadError,

    /**
     Eligibility
     */

    /**
     Dependents subscriber info is not accurate.

     @since 3.0.0
     */
    AWSDKErrorCodeEligibilityInaccurateDependentSubscriberInfo,

    /**
     Primary subscriber info is not accurate.

     @note: For inaccurate dependent subscriber info use AWSDKErrorCodeEligibilityInaccurateDependentSubscriberInfo.

     @since 3.0.0
     */
    AWSDKErrorCodeEligibilityInaccuratePrimarySubscriberInfo,

    /**
     Misc
     */

    /**
     Device not found based on deviceKey.
     */
    AWSDKErrorCodeDeviceNotFound,

    /**
     Email address not found or sent with the request.

     @since 3.0.0
     */
    AWSDKErrorCodeEmailAddressNotFound,

    /**
     Email could not be sent when trying to create account.

     @since 3.0.0
     */
    AWSDKErrorCodeEmailWelcomeNotSent,

    /**
     Couldn't find the dependent.

     @since 3.0.0
     */
    AWSDKErrorCodeDependentNotFound,

    /**
     Couldn't find the OnDemandSpecialty.

     @since 3.0.0
     */
    AWSDKErrorCodeOnDemandSpecialtyNotFound,

    /**
     Missing privacy disclaimer.

     @since 3.0.0
     */
    AWSDKErrorCodePrivacyDisclaimerMissing,

    /**
     SDK Configuration exception.

     @since 3.0.0
     */
    AWSDKErrorCodeSDKConfigurationError,

    /**
     SDK Only
     */

    /**
     The authenticated user has not completed the registration process.

     @since 1.0.0
     */
    AWSDKErrorCodePartiallyEnrolledUser,

    /**
     The property does not have an image file associated with it.

     @since 1.0.0
     */
    AWSDKErrorCodeNoSpecifiedImage,

    /**
     Attempting to use a consumer who has not been authenticated.

     @since 1.0.0
     */
    AWSDKErrorCodeConsumerUnauthenticated,

    /**
     The visit for this guest invite has already ended.

     @since 2.0.0
     */
    AWSDKErrorCodeVisitEnded,

    /**
     The value is larger than the maximum size, length, or count.

     @since 3.0.0
     */
    AWSDKErrorCodeTooLarge,

    /**
     The consumer is too old.

     @since 3.0.0
     */
    AWSDKErrorCodeConsumerTooOld,

    /**
     Value is too early in time for this parameter.

     @note: For a users birth date when the user is too old use AWSDKErrorCodeConsumerTooOld.

     @since 3.0.0
     */
    AWSDKErrorCodeDateTooEarly,

    /**
     The consumer is too young.

     @since 3.0.0
     */
    AWSDKErrorCodeConsumerTooYoung,

    /**
     Value is too late in time for this parameter. For a user's birth date, the user is too young.

     @note: For a users birth date when the user is too young use AWSDKErrorCodeConsumerTooYoung.

     @since 3.0.0
     */
    AWSDKErrorCodeDateTooLate,

    /**
     Attempting to set a locale which the SDK does not support.

     @since 1.0.0
     */
    AWSDKErrorCodeLocaleNotSupported,

    /**
     Enrollment form does not pass validation checks.

     @since 1.0.0
     */
    AWSDKErrorCodeInvalidEnrollmentData,

    /**
     Demographics form is invalid.

     @since 1.0.0
     */
    AWSDKErrorCodeInvalidDemographicData,

    /**
     The specified field cannot be edited directly by the consumer.

     @since 1.0.0
     */
    AWSDKErrorCodeInvalidProtectedField,

    /**
     The consumer is not allowed to update their health plan information.

     @since 1.0.0
     */
    AWSDKErrorCodeSubscriptionUpdateDisabled,

    /**
     Cannot add a subscription to the Health Plan.

     @since 1.0.0
     */
    AWSDKErrorCodeHealthPlanEnrollmentDisabled,

    /**
     The specified dependent is not a dependent of the given consumer.

     @since 1.0.0
     */
    AWSDKErrorCodeInvalidDependent,

    /**
     VisitContext given to Visit Manager does not pass validation checks.

     @since 1.0.0
     */
    AWSDKErrorCodeInvalidVisitContext,

    /**
     A coupon code was found applied on the visit, and only one coupon code may be applied per visit.

     @since 3.0.0
     */
    AWSDKErrorCodeCouponCodeAlreadyInUse,

    /**
     The consumer is not connected to the chat or a conversation has not started.

     @since 2.1.0
     */
    AWSDKErrorCodeChatUnavailable,

    /**
     AWSDKVisitSummary was not available for this visit.

     @since 1.0.0
     */
    AWSDKErrorCodeWrapUpUnavailable,

    /**
     Attempting to invite guests on an installation of the American Well telehealth platform that does not allow it.

     @since 2.0.0
     */
    AWSDKErrorCodeGuestsNotAllowed,

    /**
     Attempting to invite one or more guests with invalid emails.

     @since 2.0.0
     */
    AWSDKErrorCodeInvalidGuestEmails,

    /**
     Attempting to cancel a visit in an invalid state.

     @since 1.0.0
     */
    AWSDKErrorCodeCannotCancelVisit,

    /**
     The consumer already has a Find First Available request in progress.

     @since 1.0.0
     */
    AWSDKErrorCodeFindFirstAvailableAlreadyActive,

    /**
     The consumer doesn't have a Find First Available request to cancel.

     @since 1.0.0
     */
    AWSDKErrorCodeFindFirstAvailableCannotCancel,

    /**
     The appointment cannot be started because the status is not OnTime or the appointment has been canceled.

     @since 1.0.0
     */
    AWSDKErrorCodeInvalidAppointmentStatus,

    /**
     The specified message recipient is not in the consumer's contacts.

     @since 1.0.0
     */
    AWSDKErrorCodeRecipientNotAllowed,

    /**
     Cannot change the recipient of the current message draft.

     @since 1.0.0
     */
    AWSDKErrorCodeCannotChangeRecipient,

    /**
     Cannot change the topic of the current message draft.

     @since 1.0.0
     */
    AWSDKErrorCodeCannotChangeTopic,

    /**
     The selected message does not allow replies.

     @since 1.0.0
     */
    AWSDKErrorCodeMessageCannotReply,

    /**
     The given attachment does not have a valid file type.

     @since 1.0.0
     */
    AWSDKErrorCodeAttachmentTypeNotAllowed,

    /**
     The given attachment is too big to attach to the message.

     @since 1.0.0
     */
    AWSDKErrorCodeAttachmentTooBig,

    /**
     A file does not exist at the specified file path.

     @since 1.0.0
     */
    AWSDKErrorCodeFileDoesNotExist,

    /**
     The file's path extension is not valid.

     @since 1.0.0
     */
    AWSDKErrorCodeFileExtensionInvalid,

    /**
     The consumer is not eligible for SpeedPass in this context.

     @since 4.1.0
     */
    AWSDKErrorCodeIneligibleForSpeedPass,

    /**
     The tracker template cannot be found on the platform.

     @since 4.3.0
     */
    AWSDKErrorCodeTrackerTemplateNotFound,

    /**
     The start date is after the end date.

     @since 4.3.0
     */
    AWSDKErrorCodeValidationStartDateAfterEndDate,

    /**
     The tracker cannot be found on the platform.

     @since 4.3.0
     */
    AWSDKErrorCodeTrackerNotFound,

    /**
     The tracker failed deletion on the platform.

     @since 4.3.0
     */
    AWSDKErrorCodeTrackerDeleteEntryFailure,

    /**
     The video modality is not supported on the platform.

     @since 4.3.0
     */
    AWSDKErrorCodeVideoModalityNotSupported,

    /**
     The phone modality is not supported on the platform.

     @since 4.3.0
     */
    AWSDKErrorCodePhoneModalityNotSupported,

    /**
     The desired device integration cannot be found

     @since 4.3.0
     */
    AWSDKErrorCodeDeviceIntegrationNotFound,

    /**
     There are duplicate emails in the invitation request.

     @since 5.0.0
     */
    AWSDKErrorCodeGuestEmailAlreadyInvited,

    /**
     There are invalid emails in the invitation request.

     @since 5.0.0
     */
    AWSDKErrorCodeGuestEmailInvalid,

    /**
     The visit has already been started.

     @since 5.2.0
     */
    AWSDKErrorCodeVisitAlreadyStarted
};
