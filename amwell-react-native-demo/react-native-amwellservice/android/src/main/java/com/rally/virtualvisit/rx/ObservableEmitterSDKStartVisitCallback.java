/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.rx;

import android.content.Intent;
import androidx.annotation.NonNull;

import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.visit.ChatReport;
import com.americanwell.sdk.entity.visit.VisitEndReason;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.StartVisitCallback;

import java.util.Map;

import io.reactivex.ObservableEmitter;

/**
 * Extension of the base callback to provide support for the StartVisitCallback
 */
public class ObservableEmitterSDKStartVisitCallback
        extends ObservableEmitterSDKCallback<SDKStartVisitResponse<Void, SDKError>, Void, SDKError>
        implements StartVisitCallback {

    private static final String LOG_TAG = ObservableEmitterSDKStartVisitCallback.class.getName();

    public ObservableEmitterSDKStartVisitCallback(
            final ObservableEmitter<SDKStartVisitResponse<Void, SDKError>> emitter,
            final AWSDKLogger log) {
        super(emitter, log);
    }

    @Override
    public void onProviderEntered(@NonNull Intent videoVisitIntent) {
        final SDKStartVisitResponse<Void, SDKError> response = new SDKStartVisitResponse<>();
        response.setIntent(videoVisitIntent);
        emitter.onNext(response);
    }

    @Override
    public void onStartVisitEnded(@NonNull @VisitEndReason String visitEndReason) {
        final SDKStartVisitResponse<Void, SDKError> response = new SDKStartVisitResponse<>();
        response.setVisitEndReason(visitEndReason);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onPatientsAheadOfYouCountChanged(int count) {
        final SDKStartVisitResponse<Void, SDKError> response = new SDKStartVisitResponse<>();
        response.setPatientsAheadOfYou(count);
        emitter.onNext(response); // this one is repeatable - aka - polling.  so don't call onCompleted()
    }

    @Override
    public void onSuggestedTransfer() {
        final SDKStartVisitResponse<Void, SDKError> response = new SDKStartVisitResponse<>();
        response.setSuggestedTransfer(true);
        emitter.onNext(response); // this one is repeatable - aka - polling.  so don't call onCompleted()
    }

    @Override
    public void onSuggestFindFirstAvailable() {
        final SDKStartVisitResponse<Void, SDKError> response = new SDKStartVisitResponse<>();
        response.setSuggestFindFirstAvailable(true);
        emitter.onNext(response);
    }

    @Override
    public void onChat(@NonNull ChatReport chatReport) {
        final SDKStartVisitResponse<Void, SDKError> response = new SDKStartVisitResponse<>();
        response.setChatReport(chatReport);
        emitter.onNext(response); // this one is repeatable - aka - polling.  so don't call onCompleted()
    }

    @Override
    public void onPollFailure(@NonNull Throwable throwable) {
        // no-op - the sample app does not implement this method
        logger.e(LOG_TAG, "onPollFailure", throwable);
    }

    @Override
    public void onValidationFailure(@NonNull Map<String, String> validationReasons) {
        final SDKStartVisitResponse<Void, SDKError> response = new SDKStartVisitResponse<>(null, null, validationReasons);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public SDKStartVisitResponse getResponse(Void aVoid, SDKError sdkError) {
        return new SDKStartVisitResponse<>(aVoid, sdkError, null);
    }
}
