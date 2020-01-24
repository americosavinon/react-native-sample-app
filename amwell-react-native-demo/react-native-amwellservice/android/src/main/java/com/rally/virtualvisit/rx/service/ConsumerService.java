/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.rx.service;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.Authentication;
import com.americanwell.sdk.entity.FileAttachment;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.SDKLocalDate;
import com.americanwell.sdk.entity.SDKPasswordError;
import com.americanwell.sdk.entity.State;
import com.americanwell.sdk.entity.UploadAttachment;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.consumer.ConsumerUpdate;
import com.americanwell.sdk.entity.consumer.DependentAccessRequestAnswer;
import com.americanwell.sdk.entity.consumer.DependentUpdate;
import com.americanwell.sdk.entity.consumer.DocumentRecord;
import com.americanwell.sdk.entity.consumer.Notifications;
import com.americanwell.sdk.entity.consumer.RecoverEmailResponse;
import com.americanwell.sdk.entity.consumer.tracker.Tracker;
import com.americanwell.sdk.entity.consumer.tracker.TrackerTemplate;
import com.americanwell.sdk.entity.consumer.tracker.TrackersRequest;
import com.americanwell.sdk.entity.enrollment.ConsumerEnrollment;
import com.americanwell.sdk.entity.enrollment.DependentEnrollment;
import com.americanwell.sdk.entity.health.Allergy;
import com.americanwell.sdk.entity.health.Condition;
import com.americanwell.sdk.entity.health.Medication;
import com.americanwell.sdk.entity.provider.Provider;
import com.americanwell.sdk.entity.visit.VisitContext;
import com.americanwell.sdk.entity.visit.VisitReport;
import com.americanwell.sdk.entity.visit.VisitReportDetail;
import com.americanwell.sdk.entity.visit.Vitals;
import com.americanwell.sdk.manager.ConsumerManager;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKValidatedCallback;
import com.rally.virtualvisit.rx.SDKResponse;
import com.rally.virtualvisit.rx.SDKValidatedResponse;

import java.io.IOException;
import java.util.Date;
import java.util.List;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link ConsumerManager} calls and RxAndroid.
 * Provides Observable wrappers for all calls.
 * <p>
 * This is just one way of handling this, one which we think is a good practice. The use of
 * RxAndroid here, in combination with an MVP framework such as Nucleus, allows for nice handling
 * of long-running asynchronous requests - detached from the tricks of the Activity lifecycle.
 * If you have a preferred pattern, of course give it a try.
 * <p>
 * The ObservableEmitter for the Observable is passed into one of several variations of
 * ObservableEmitterSDKCallback which handles the callback methods and delegates to the ObservableEmitter methods
 */
public class ConsumerService extends BaseObservableService<ConsumerManager> {

    public ConsumerService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected ConsumerManager getManager(AWSDK awsdk) {
        return awsdk.getConsumerManager();
    }

    public Observable<SDKResponse<Consumer, SDKError>> getConsumer(
            @NonNull final Authentication authentication) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Consumer, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Consumer, SDKError>> emitter) throws Exception {
                        getManager().getConsumer(
                                authentication,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Consumer, SDKError>> refreshConsumer(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Consumer, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Consumer, SDKError>> emitter) throws Exception {
                        getManager().refreshConsumer(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Consumer, SDKPasswordError>> updateConsumer(
            @NonNull final ConsumerUpdate consumerUpdate) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Consumer, SDKPasswordError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Consumer, SDKPasswordError>> emitter) throws Exception {
                        getManager().updateConsumer(
                                consumerUpdate,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> requestDependentAccess(
            @NonNull final Consumer consumer,
            @NonNull final String guardianEmailAddress) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().requestDependentAccess(
                                consumer,
                                guardianEmailAddress,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<DependentAccessRequestAnswer, SDKError>> getDependentAccessRequests(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<DependentAccessRequestAnswer, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<DependentAccessRequestAnswer, SDKError>> emitter) throws Exception {
                        getManager().getDependentAccessRequests(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> acceptDependentAccessRequest(
            @NonNull final DependentAccessRequestAnswer dependentAccessRequestAnswer,
            @NonNull final List<Consumer> dependents) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().acceptDependentAccessRequest(
                                dependentAccessRequestAnswer,
                                dependents,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> declineDependentAccessRequest(
            @NonNull final DependentAccessRequestAnswer dependentAccessRequestAnswer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().declineDependentAccessRequest(
                                dependentAccessRequestAnswer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Consumer>, SDKError>> getDependents(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Consumer>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<Consumer>, SDKError>> emitter) throws Exception {
                        getManager().getDependents(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Consumer, SDKError>> updateDependent(
            @NonNull final DependentUpdate dependentUpdate) {
        return Observable.create(
                (emitter) ->
                        getManager().updateDependent(
                                dependentUpdate,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        )
        );
    }

    public Observable<SDKResponse<Consumer, SDKPasswordError>> completeEnrollment(
            @NonNull final Authentication authentication,
            @Nullable final State legalResidence,
            @Nullable final String newUsername,
            @Nullable final String newPassword) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Consumer, SDKPasswordError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Consumer, SDKPasswordError>> emitter) throws Exception {
                        getManager().completeEnrollment(
                                authentication,
                                legalResidence,
                                newUsername,
                                newPassword,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    // forgot email / password
    public Observable<SDKValidatedResponse<RecoverEmailResponse, SDKError>> recoverEmail(
            @NonNull final String lastName,
            @NonNull final SDKLocalDate dob) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<RecoverEmailResponse, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<RecoverEmailResponse, SDKError>> emitter) throws Exception {
                        getManager().recoverEmail(
                                lastName,
                                dob,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> resetPassword(
            @NonNull final String email,
            @NonNull final String lastName,
            @NonNull final SDKLocalDate dob) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().resetPassword(
                                email,
                                lastName,
                                dob,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    // enrollment
    public Observable<SDKValidatedResponse<Consumer, SDKPasswordError>> enrollConsumer(
            @NonNull final ConsumerEnrollment enrollment,
            final boolean acceptedMemberDisclaimer,
            final boolean sendWelcomeEmail) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Consumer, SDKPasswordError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKValidatedResponse<Consumer, SDKPasswordError>> emitter) throws Exception {
                        getManager().enrollConsumer(
                                enrollment,
                                acceptedMemberDisclaimer,
                                sendWelcomeEmail,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Consumer, SDKError>> enrollDependent(
            @NonNull final DependentEnrollment enrollment) {
        return Observable.create(
                (emitter) ->
                        getManager().enrollDependent(
                                enrollment,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        )
        );
    }

    public Observable<SDKResponse<String, SDKError>> getEnrollmentDisclaimer() {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<String, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<String, SDKError>> emitter) throws Exception {
                        getManager().getEnrollmentDisclaimer(
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> addServiceKey(
            @NonNull final Consumer consumer,
            @NonNull final String serviceKey) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().addServiceKey(
                                consumer,
                                serviceKey,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    // visit reports
    public Observable<SDKResponse<List<VisitReport>, SDKError>> getVisitReports(
            @NonNull final Consumer consumer,
            final boolean completedOnly) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<VisitReport>, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<List<VisitReport>, SDKError>> emitter) throws Exception {
                        getManager().getVisitReports(
                                consumer,
                                null,
                                null,
                                completedOnly,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<FileAttachment, SDKError>> getVisitReportAttachment(
            @NonNull final Consumer consumer,
            @NonNull final VisitReport visitReport) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<FileAttachment, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<FileAttachment, SDKError>> emitter) throws Exception {
                        getManager().getVisitReportAttachment(
                                consumer,
                                visitReport,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<VisitReportDetail, SDKError>> getVisitReportDetail(
            @NonNull final Consumer consumer,
            @NonNull final VisitReport visitReport) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<VisitReportDetail, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<VisitReportDetail, SDKError>> emitter) throws Exception {
                        getManager().getVisitReportDetail(
                                consumer,
                                visitReport,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Provider>, SDKError>> getPastProviders(
            @NonNull final Consumer consumer,
            @Nullable final Integer maxResults) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Provider>, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<List<Provider>, SDKError>> emitter) throws Exception {
                        getManager().getPastProviders(
                                consumer,
                                maxResults,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<DocumentRecord>, SDKError>> getHealthDocuments(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<DocumentRecord>, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<List<DocumentRecord>, SDKError>> emitter) throws Exception {
                        getManager().getHealthDocumentRecords(
                                consumer,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<FileAttachment, SDKError>> getHealthDocumentAttachment(
            @NonNull final Consumer consumer,
            @NonNull final DocumentRecord documentRecord) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<FileAttachment, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<FileAttachment, SDKError>> emitter) throws Exception {
                        getManager().getHealthDocumentRecordAttachment(
                                consumer,
                                documentRecord,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> removeHealthDocument(
            @NonNull final Consumer consumer,
            @NonNull final DocumentRecord documentRecord) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().removeHealthDocumentRecord(
                                consumer,
                                documentRecord,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<DocumentRecord, SDKError>> addHealthDocument(
            @NonNull final Consumer consumer,
            @NonNull final UploadAttachment uploadAttachment) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<DocumentRecord, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKValidatedResponse<DocumentRecord, SDKError>> emitter) throws Exception {
                        try {
                            getManager().addHealthDocument(
                                    consumer,
                                    uploadAttachment,
                                    new ObservableEmitterSDKValidatedCallback(emitter, log)
                            );
                        }
                        catch (IOException e) {
                            emitter.onError(e);
                        }
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> setLegalResidence(
            @NonNull final Consumer consumer,
            @NonNull final State legalResidence) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().setLegalResidence(
                                consumer,
                                legalResidence,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }


    // vitals
    public Observable<SDKValidatedResponse<Void, SDKError>> updateVitals(
            @NonNull final Consumer consumer,
            @NonNull final Vitals vitals,
            @Nullable final VisitContext visitContext) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKValidatedResponse<Void,
                                    SDKError>> emitter) throws Exception {
                        getManager().updateVitals(
                                consumer,
                                vitals,
                                visitContext,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    // conditions
    public Observable<SDKResponse<List<Condition>, SDKError>> getConditions(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Condition>, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<List<Condition>, SDKError>> emitter) throws Exception {
                        getManager().getConditions(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> updateConditions(
            @NonNull final Consumer consumer,
            @NonNull final List<Condition> conditions) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().updateConditions(
                                consumer,
                                conditions,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                });
    }

    public Observable<SDKResponse<List<Medication>, SDKError>> getMedications(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Medication>, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<List<Medication>, SDKError>> emitter) throws Exception {
                        getManager().getMedications(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> updateMedications(
            @NonNull final Consumer consumer,
            @NonNull final List<Medication> medications) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().updateMedications(
                                consumer,
                                medications,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<List<Medication>, SDKError>> searchMedications(
            @NonNull final Consumer consumer,
            @NonNull final String searchText) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<List<Medication>, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKValidatedResponse<List<Medication>, SDKError>> emitter) throws Exception {
                        getManager().searchMedications(
                                consumer,
                                searchText,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Allergy>, SDKError>> getAllergies(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Allergy>, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<List<Allergy>, SDKError>> emitter) throws Exception {
                        getManager().getAllergies(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> updateAllergies(
            @NonNull final Consumer consumer,
            @NonNull final List<Allergy> allergies) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().updateAllergies(
                                consumer,
                                allergies,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> acceptOutstandingDisclaimer(
            @NonNull final Authentication authentication) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().acceptOutstandingDisclaimer(authentication, new
                                ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Notifications, SDKError>> getNotifications(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Notifications, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Notifications, SDKError>> emitter) throws Exception {
                        getManager().getNotifications(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<TrackerTemplate>, SDKError>> searchTrackerTemplates(
            @Nullable String searchTerm) {
        return Observable.create((emitter) ->
                getManager().searchTrackerTemplates(
                        searchTerm,
                        new ObservableEmitterSDKCallback(emitter, log))
        );
    }

    public Observable<SDKResponse<Void, SDKError>> addTrackers(
            @NonNull final Consumer consumer,
            @NonNull final TrackersRequest trackersRequest) {
        return Observable.create((emitter) ->
                getManager().addTrackers(
                        consumer,
                        trackersRequest,
                        new ObservableEmitterSDKCallback(emitter, log))
        );
    }

    public Observable<SDKResponse<Void, SDKError>> deleteTrackers(
            @NonNull final Consumer consumer,
            @NonNull final TrackerTemplate template,
            @NonNull final Date startDate,
            @NonNull final Date endDate) {
        return Observable.create((emitter) ->
                getManager().deleteTrackers(
                        consumer,
                        template,
                        startDate,
                        endDate,
                        new ObservableEmitterSDKCallback(emitter, log))
        );
    }

    public Observable<SDKResponse<List<Tracker>, SDKError>> searchTrackers(
            @NonNull final Consumer consumer,
            @NonNull final TrackerTemplate template,
            @NonNull final Date startDate,
            @NonNull final Date endDate) {
        return Observable.create((emitter) ->
                getManager().searchTrackers(
                        consumer,
                        template,
                        startDate,
                        endDate,
                        new ObservableEmitterSDKCallback(emitter, log))
        );
    }

}
