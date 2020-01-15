/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.rx;

import androidx.annotation.NonNull;

import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.visit.ConsumerInitiatedIVRStatus;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.IVRCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;

import java.util.Map;

import io.reactivex.ObservableEmitter;

/**
 * Extension of the base callback to provide support for the {@link IVRCallback}
 */
public class ObservableEmitterSDKIVRCallback
        extends ObservableEmitterSDKCallback<SDKIVRResponse<Void, SDKError>, Void, SDKError>
        implements IVRCallback {

    private static final String LOG_TAG = ObservableEmitterSDKIVRCallback.class.getName();

    public ObservableEmitterSDKIVRCallback(final ObservableEmitter<SDKIVRResponse<Void, SDKError>> emitter,
                                           final AWSDKLogger logger) {
        super(emitter, logger);
    }

    @Override
    public void onUpdate(@NonNull @ConsumerInitiatedIVRStatus String status, int retryCount) {
        final SDKIVRResponse<Void, SDKError> response = new SDKIVRResponse<>();
        response.setStatus(status);
        response.setRetryCount(retryCount);
        emitter.onNext(response);
    }

    @Override
    public void onPollFailure(@NonNull Throwable throwable) {
        // no-op - the sample app does not implement this method
        logger.e(LOG_TAG, "onPollFailure", throwable);
    }

    @Override
    public void onValidationFailure(@NonNull Map<String, String> validationReasons) {
        final SDKIVRResponse<Void, SDKError> response = new SDKIVRResponse<>(null, null,
                validationReasons);
        emitter.onNext(response);
        emitter.onComplete();
    }
}
