//
//  AWSDKPrivate.h
//  AWSDK
//
//  Created by Stephen Ciauri on 3/22/19.
//  Copyright © 2019 American Well. All rights reserved.
//

#ifndef AWSDKPrivate_h
#define AWSDKPrivate_h

    #import "AWSDKAddressPrivate.h"
    #import "AWSDKAllergyPrivate.h"
    #import "AWSDKAppointmentPrivate.h"
    #import "AWSDKAppointmentReadinessPrivate.h"
    #import "AWSDKAppointmentRecordFormPrivate.h"
    #import "AWSDKAppointmentReadinessOverridesPrivate.h"
    #import "AWSDKAttachmentPrivate.h"
    #import "AWSDKAuthenticationServicePrivate.h"
    #import "AWSDKAvailableProviderSearchResultPrivate.h"
    #import "AWSDKAvailableProviderSearchResultsPrivate.h"
    #import "AWSDKBaseVisitSummaryPrivate.h"
    #import "AWSDKChatItemPrivate.h"
    #import "AWSDKChatReportPrivate.h"
    #import "AWSDKConditionPrivate.h"
    #import "AWSDKConsumerDemographicFormPrivate.h"
    #import "AWSDKConsumerEnrollmentFormPrivate.h"
    #import "AWSDKConsumerPrivate.h"
    #import "AWSDKConsumerServicePrivate.h"
    #import "AWSDKConsumerUpdateFormPrivate.h"
    #import "AWSDKConsumerNotificationsPrivate.h"
    #import "AWSDKConsumerVitalsFormPrivate.h"
    #import "AWSDKConsumerVitalsPrivate.h"
    #import "AWSDKContactPrivate.h"
    #import "AWSDKCostPrivate.h"
    #import "AWSDKCountryPrivate.h"
    #import "AWSDKCreditCardTypePrivate.h"
    #import "AWSDKDataObjectPrivate.h"
    #import "AWSDKDemographicFormPrivate.h"
    #import "AWSDKDependentAccessRequestPrivate.h"
    #import "AWSDKDependentDemographicFormPrivate.h"
    #import "AWSDKDependentEnrollmentFormPrivate.h"
    #import "AWSDKDependentUpdateFormPrivate.h"
    #import "AWSDKDeviceIntegrationPrivate.h"
    #import "AWSDKEnrollmentServicePrivate.h"
    #import "AWSDKFeedbackQuestionPrivate.h"
    #import "AWSDKFollowUpItemPrivate.h"
    #import "AWSDKForcedVisitTransferPrivate.h"
    #import "AWSDKFormPrivate.h"
    #import "AWSDKHealthDocumentPrivate.h"
    #import "AWSDKHealthPlanPrivate.h"
    #import "AWSDKHealthSummaryPrivate.h"
    #import "AWSDKHealthSummaryRecordPrivate.h"
    #import "AWSDKHealthTrackerRecordFormPrivate.h"
    #import "AWSDKHealthTrackerTypePrivate.h"
    #import "AWSDKInboxMessageDetailsPrivate.h"
    #import "AWSDKInboxMessagePrivate.h"
    #import "AWSDKLanguagePrivate.h"
    #import "AWSDKLegalTextPrivate.h"
    #import "AWSDKLocalePrivate.h"
    #import "AWSDKPlatformTypePrivate.h"
    #import "AWSDKModalityPrivate.h"
    #import "AWSDKRemoteLogMessageParamPrivate.h"
    #import "AWSDKRemoteLogMessagePrivate.h"
    #import "AWSDKRolePrivate.h"
    #import "AWSDKLogServicePrivate.h"
    #import "AWSDKMedicationPrivate.h"
    #import "AWSDKMedicationServicePrivate.h"
    #import "AWSDKMessageDraftPrivate.h"
    #import "AWSDKMessageFetchOptionsPrivate.h"
    #import "AWSDKMessageFolderInboxPrivate.h"
    #import "AWSDKMessageFolderPrivate.h"
    #import "AWSDKMessageFolderSentPrivate.h"
    #import "AWSDKMessagePrivate.h"
    #import "AWSDKMessageTopicPrivate.h"
    #import "AWSDKConferencePrivate.h"
    #import "AWSDKConferenceParticipantPrivate.h"
    #import "AWSDKOnDemandSpecialtyPrivate.h"
    #import "AWSDKPartialConsumerPrivate.h"
    #import "AWSDKConsumerOverridesPrivate.h"
    #import "AWSDKPaymentMethodFormPrivate.h"
    #import "AWSDKPaymentMethodPrivate.h"
    #import "AWSDKPharmacyPrivate.h"
    #import "AWSDKPharmacyServicePrivate.h"
    #import "AWSDKPracticePrivate.h"
    #import "AWSDKPracticeSearchResultPrivate.h"
    #import "AWSDKPracticeServicePrivate.h"
    #import "AWSDKPrescriptionPrivate.h"
    #import "AWSDKProviderPrivate.h"
    #import "AWSDKProviderSearchOptionsPrivate.h"
    #import "AWSDKProviderSearchResultPrivate.h"
    #import "AWSDKProviderServicePrivate.h"
    #import "AWSDKProviderTypePrivate.h"
    #import "AWSDKRelationshipToSubscriberPrivate.h"
    #import "AWSDKReminderOptionPrivate.h"
    #import "AWSDKSchedulePrivate.h"
    #import "AWSDKSentMessageDetailsPrivate.h"
    #import "AWSDKSentMessagePrivate.h"
    #import "AWSDKServicePrivate.h"
    #import "AWSDKStatePrivate.h"
    #import "AWSDKSubscriptionFormPrivate.h"
    #import "AWSDKSubscriptionPrivate.h"
    #import "AWSDKSuggestedVisitTransferPrivate.h"
    #import "AWSDKSpeedPassPrivate.h"
    #import "AWSDKSystemConfigurationPrivate.h"
    #import "AWSDKTrackerComponentTemplatePrivate.h"
    #import "AWSDKTrackerDataPointPrivate.h"
    #import "AWSDKTrackerDataPointRequestEntryPrivate.h"
    #import "AWSDKTrackerEntryRequestPrivate.h"
    #import "AWSDKTrackerTemplatePrivate.h"
    #import "AWSDKTrackersRequestPrivate.h"
    #import "AWSDKTriageQuestionPrivate.h"
    #import "AWSDKUserPrivate.h"
    #import "AWSDKNetworkInfoPrivate.h"
    #import "AWSDKVideoGuestPrivate.h"
    #import "AWSDKVisitContextPrivate.h"
    #import "AWSDKVisitDiagnosisPrivate.h"
    #import "AWSDKVisitExtensionPrivate.h"
    #import "AWSDKVisitFlowStatePrivate.h"
    #import "AWSDKVisitPrivate.h"
    #import "AWSDKVisitProcedurePrivate.h"
    #import "AWSDKVisitReportPrivate.h"
    #import "AWSDKVisitReportSummaryPrivate.h"
    #import "AWSDKVisitServicePrivate.h"
    #import "AWSDKVisitSummaryPrivate.h"
    #import "AWSDKVisitTopicPrivate.h"
    #import "AWSDKVisitTransferPrivate.h"
    #import "NSError+AWSDKErrorPrivate.h"


#endif /* AWSDKPrivate_h */