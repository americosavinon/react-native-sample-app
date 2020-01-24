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
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.StartConferenceCallback;

import io.reactivex.ObservableEmitter;

/**
 * Extension of base callback to provide support for the StartConferenceCallback
 */
public class ObservableEmitterSDKStartConferenceCallback
        extends ObservableEmitterSDKCallback<SDKStartConferenceResponse<Void, SDKError>, Void, SDKError>
        implements StartConferenceCallback {

    private static final String LOG_TAG = ObservableEmitterSDKStartConferenceCallback.class.getName();

    public ObservableEmitterSDKStartConferenceCallback(
            final ObservableEmitter<SDKStartConferenceResponse<Void, SDKError>> emitter,
            final AWSDKLogger log) {
        super(emitter, log);
    }

    @Override
    public void onConferenceStarted(@NonNull Intent intent) {
        final SDKStartConferenceResponse<Void, SDKError> response = new SDKStartConferenceResponse<>();
        response.setIntent(intent);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onConferenceEnded() {
        final SDKStartConferenceResponse<Void, SDKError> response = new SDKStartConferenceResponse<>();
        response.setConferenceEnded(true);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onConferenceCanceled() {
        final SDKStartConferenceResponse<Void, SDKError> response = new SDKStartConferenceResponse<>();
        response.setConferenceCanceled(true);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onPollFailure(@NonNull Throwable throwable) {
        // no-op - the sample app does not implement this method
        logger.e(LOG_TAG, "onPollFailure", throwable);
    }

    @Override
    public SDKStartConferenceResponse getResponse(Void aVoid, SDKError sdkError) {
        return new SDKStartConferenceResponse<>(aVoid, sdkError);
    }

}
