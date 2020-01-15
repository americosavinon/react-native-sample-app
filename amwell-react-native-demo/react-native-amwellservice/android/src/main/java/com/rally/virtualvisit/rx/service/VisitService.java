/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.rx.service;

import android.content.Intent;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.Address;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.SDKLaunchParams;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.consumer.VisitSearchRequest;
import com.americanwell.sdk.entity.practice.OnDemandSpecialty;
import com.americanwell.sdk.entity.provider.ProviderInfo;
import com.americanwell.sdk.entity.visit.Appointment;
import com.americanwell.sdk.entity.visit.ChatReport;
import com.americanwell.sdk.entity.visit.ConsumerFeedbackQuestion;
import com.americanwell.sdk.entity.visit.SpeedPass;
import com.americanwell.sdk.entity.visit.Visit;
import com.americanwell.sdk.entity.visit.VisitContext;
import com.americanwell.sdk.entity.visit.VisitSummary;
import com.americanwell.sdk.manager.VisitManager;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKIVRCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKMatchmakerCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKStartConferenceCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKStartVisitCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKValidatedCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKVisitTransferCallback;
import com.rally.virtualvisit.rx.SDKIVRResponse;
import com.rally.virtualvisit.rx.SDKMatchmakerResponse;
import com.rally.virtualvisit.rx.SDKResponse;
import com.rally.virtualvisit.rx.SDKStartConferenceResponse;
import com.rally.virtualvisit.rx.SDKStartVisitResponse;
import com.rally.virtualvisit.rx.SDKValidatedResponse;
import com.rally.virtualvisit.rx.SDKVisitTransferResponse;

import java.util.List;
import java.util.Set;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link VisitManager} calls and RxAndroid.
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
public class VisitService extends BaseObservableService<VisitManager> {

    public VisitService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected VisitManager getManager(AWSDK awsdk) {
        return awsdk.getVisitManager();
    }

    public Observable<SDKStartConferenceResponse<Void, SDKError>> startGuestConference(
            @NonNull final SDKLaunchParams launchParams,
            @NonNull final String email,
            @NonNull final String name,
            @Nullable final Intent visitFinishedIntent) {
        return Observable.create(
                new ObservableOnSubscribe<SDKStartConferenceResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKStartConferenceResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().startGuestConference(
                                launchParams,
                                email,
                                name,
                                visitFinishedIntent,
                                new ObservableEmitterSDKStartConferenceCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<VisitContext, SDKError>> getVisitContext(
            @NonNull final Consumer consumer,
            @NonNull final ProviderInfo provider) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<VisitContext, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<VisitContext, SDKError>> emitter) throws Exception {
                        getManager().getVisitContext(
                                consumer,
                                provider,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<VisitContext, SDKError>> getVisitContext(
            @NonNull final Consumer consumer,
            @NonNull final OnDemandSpecialty specialty) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<VisitContext, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<VisitContext, SDKError>> emitter) throws Exception {
                        getManager().getVisitContext(
                                consumer,
                                specialty,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<VisitContext, SDKError>> getVisitContext(
            @NonNull final Appointment appointment) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<VisitContext, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<VisitContext, SDKError>> emitter) throws Exception {
                        getManager().getVisitContext(
                                appointment,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Visit, SDKError>> buildVisit(
            @NonNull final VisitContext visitContext) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Visit, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Visit, SDKError>> emitter) throws Exception {
                        getManager().buildVisit(
                                visitContext,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Visit, SDKError>> buildVisit(
            @NonNull final SpeedPass speedPass) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Visit, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Visit, SDKError>> emitter) throws Exception {
                        getManager().buildVisit(
                                speedPass,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    /**
     * Create an {@link io.reactivex.Observable} for setting up waiting room alerts
     *
     * @param visit              REQUIRED The {@link Visit} created by
     *                           {@link #buildVisit(VisitContext)}
     * @param phoneNumber        REQUIRED The phoneNumber to use for sending text alerts
     * @param providerReadyAlert REQUIRED Send alert when provider is ready.
     * @param movedUpInQueue     REQUIRED Send alert when this visit moves up in the waiting list.
     * @return An {@link Observable} when subscribed, will call the REST API for setting up
     * waiting room alerts
     * @since AWSDK 4.0
     */
    public Observable<SDKResponse<Void, SDKError>> setupWaitingRoomAlerts(
            @NonNull final Visit visit,
            @NonNull final String phoneNumber,
            final boolean providerReadyAlert,
            final boolean movedUpInQueue) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().setupWaitingRoomAlerts(
                                visit,
                                phoneNumber,
                                providerReadyAlert,
                                movedUpInQueue,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> applyCouponCode(
            @NonNull final Visit visit,
            @NonNull final String couponCode) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().applyCouponCode(
                                visit,
                                couponCode,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKStartVisitResponse<Void, SDKError>> startVisit(
            @NonNull final Visit visit,
            @Nullable final Address location,
            @Nullable final Intent visitFinishedIntent) {
        return Observable.create(
                (emitter) ->
                        getManager().startVisit(
                                visit,
                                location,
                                visitFinishedIntent,
                                new ObservableEmitterSDKStartVisitCallback(emitter, log)
                        )
        );
    }

    public Observable<SDKResponse<Void, SDKError>> cancelVisit(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().cancelVisit(
                                visit,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Visit>, SDKError>> searchVisits(
            @NonNull final Consumer consumer,
            @NonNull final VisitSearchRequest visitSearchRequest) {
        return Observable.create((emitter) ->
                getManager().searchVisits(
                        consumer,
                        visitSearchRequest,
                        new ObservableEmitterSDKCallback(emitter, log)
                )
        );
    }

    public Observable<SDKVisitTransferResponse<VisitContext, SDKError>> acceptSuggestedTransfer(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKVisitTransferResponse<VisitContext, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKVisitTransferResponse<VisitContext, SDKError>> emitter) throws Exception {
                        getManager().acceptSuggestedTransfer(
                                visit,
                                new ObservableEmitterSDKVisitTransferCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKVisitTransferResponse<VisitContext, SDKError>> acceptDeclineAndTransfer(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKVisitTransferResponse<VisitContext, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKVisitTransferResponse<VisitContext, SDKError>> emitter) throws Exception {
                        getManager().acceptDeclineAndTransfer(
                                visit,
                                new ObservableEmitterSDKVisitTransferCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKVisitTransferResponse<VisitContext, SDKError>> acceptPostVisitTransfer(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKVisitTransferResponse<VisitContext, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKVisitTransferResponse<VisitContext, SDKError>> emitter) throws Exception {
                        getManager().acceptPostVisitTransfer(
                                visit,
                                new ObservableEmitterSDKVisitTransferCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> acceptedFindFirstAvailableTransferVisitSuggestion(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().acceptFindFirstAvailableTransferVisitSuggestion(
                                visit,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> declineFindFirstAvailableSuggestion(
            @NonNull final Visit visit,
            final boolean dontSuggestFindFirstAvailableAgain) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().declineFindFirstAvailableSuggestion(
                                visit,
                                dontSuggestFindFirstAvailableAgain,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> declineTransfer(
            @NonNull final Visit visit,
            final boolean dontSuggestTransferAgain) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().declineTransfer(
                                visit,
                                dontSuggestTransferAgain,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKMatchmakerResponse<Void, SDKError>> startMatchmaking(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKMatchmakerResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKMatchmakerResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().startMatchmaking(
                                visit,
                                new ObservableEmitterSDKMatchmakerCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> cancelMatchmaking(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().cancelMatchmaking(
                                visit,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<VisitSummary, SDKError>> getVisitSummary(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<VisitSummary, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<VisitSummary, SDKError>> emitter) throws Exception {
                        getManager().getVisitSummary(
                                visit,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> sendVisitFeedback(
            @NonNull final Visit visit,
            @NonNull final ConsumerFeedbackQuestion consumerFeedbackQuestion) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().sendVisitFeedback(
                                visit,
                                consumerFeedbackQuestion,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> sendEmailSummary(
            @NonNull final Visit visit,
            @Nullable final Set<String> emails,
            final boolean hipaaNoticeAccepted) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Void,
                                            SDKError>> emitter) throws Exception {
                        getManager().sendVisitSummaryReport(
                                visit,
                                emails,
                                hipaaNoticeAccepted,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> sendVisitSummary(
            @NonNull final Visit visit,
            @Nullable final Set<String> emails,
            @Nullable final Set<String> faxNumbers,
            final boolean hipaaNoticeAccepted) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKValidatedResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().sendVisitSummaryReport(
                                visit,
                                emails,
                                faxNumbers,
                                hipaaNoticeAccepted,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> sendRatings(
            @NonNull final Visit visit,
            @Nullable final Integer providerRating,
            @Nullable final Integer visitRating) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().sendRatings(
                                visit,
                                providerRating,
                                visitRating,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<ChatReport, SDKError>> sendChat(
            @NonNull final Visit visit,
            @NonNull final String message) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<ChatReport, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<ChatReport, SDKError>> emitter) throws Exception {
                        getManager().addChatMessage(
                                visit,
                                message,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKIVRResponse<Void, SDKError>> monitorIVRStatus(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKIVRResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter
                            <SDKIVRResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().monitorIVRStatus(
                                visit,
                                new ObservableEmitterSDKIVRCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> retryIVR(@NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().retryIVRCallback(
                                visit,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> cancelIVR(@NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().cancelIVR(visit, new ObservableEmitterSDKCallback(emitter, log));
                    }
                }
        );
    }

    public Observable<SDKResponse<SpeedPass, SDKError>> getSpeedPassEligibilityEngagement(
            @NonNull final Consumer consumer,
            @Nullable final OnDemandSpecialty onDemandSpecialty,
            @Nullable final ProviderInfo provider) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<SpeedPass, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<SpeedPass, SDKError>> emitter) throws Exception {
                        getManager().getSpeedPassEligibleEngagement(
                                consumer,
                                onDemandSpecialty,
                                provider,
                                new ObservableEmitterSDKCallback(emitter, log));
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> initiateIVRRequestCall(
            @NonNull final Consumer consumer,
            @NonNull final ProviderInfo provider,
            @Nullable final String phoneNumber) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().initiateIVRRequestCall(
                                consumer,
                                provider,
                                phoneNumber,
                                new ObservableEmitterSDKCallback(emitter, log));
                    }
                }
        );
    }

    public Observable<SDKResponse<Visit, SDKError>> findActiveVisit(
            @NonNull final Consumer consumer) {
        return Observable.create((emitter) ->
                getManager().findActiveVisit(
                        consumer,
                        new ObservableEmitterSDKCallback(emitter, log)
                )
        );
    }

    public Observable<SDKResponse<Intent, SDKError>> generateIntentForInProgressVisit(
            @NonNull final Visit visit,
            @Nullable final Intent visitFinishedIntent) {
        return Observable.create((emitter) ->
                getManager().generateIntentForInProgressVisit(
                        visit,
                        visitFinishedIntent,
                        new ObservableEmitterSDKCallback(emitter, log)
                )
        );
    }

    public Observable<SDKResponse<Visit, SDKError>> endVisit(
            @NonNull final Visit visit) {
        return Observable.create((emitter) ->
                getManager().endVisit(
                        visit,
                        new ObservableEmitterSDKCallback(emitter, log)
                )
        );
    }
}
