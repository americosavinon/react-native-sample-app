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
import com.americanwell.sdk.entity.provider.Provider;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.MatchmakerCallback;

import io.reactivex.ObservableEmitter;

/**
 * Extension of the base callback to provide support for the MatchmakerCallback
 */
public class ObservableEmitterSDKMatchmakerCallback
        extends ObservableEmitterSDKCallback<SDKMatchmakerResponse<Void, SDKError>, Void, SDKError>
        implements MatchmakerCallback {

    public ObservableEmitterSDKMatchmakerCallback(
            final ObservableEmitter<SDKMatchmakerResponse<Void, SDKError>> emitter,
            final AWSDKLogger log) {
        super(emitter, log);
    }

    @Override
    public void onProviderFound(@NonNull Provider provider) {
        final SDKMatchmakerResponse<Void, SDKError> response = new SDKMatchmakerResponse<>();
        response.setProvider(provider);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onProviderListExhausted() {
        final SDKMatchmakerResponse<Void, SDKError> response = new SDKMatchmakerResponse<>();
        response.setProviderListExhausted(true);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onRequestGone() {
        final SDKMatchmakerResponse<Void, SDKError> response = new SDKMatchmakerResponse<>();
        response.setRequestGone(true);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public SDKMatchmakerResponse getResponse(Void aVoid, SDKError sdkError) {
        return new SDKMatchmakerResponse<>(aVoid, sdkError);
    }

}
