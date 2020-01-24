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
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.SDKCallback;

import io.reactivex.ObservableEmitter;

/**
 * This is the base "wrapper" callback to provide a bridge between the SDK standard
 * callbacks and an Rx ObservableEmitter.
 */
public class ObservableEmitterSDKCallback<R extends SDKResponse, T, E extends SDKError> implements SDKCallback<T, E> {

    protected ObservableEmitter emitter;
    protected AWSDKLogger logger;

    public ObservableEmitterSDKCallback(final ObservableEmitter<R> emitter, final AWSDKLogger logger) {
        this.emitter = emitter;
        this.logger = logger;
    }

    @Override
    public void onResponse(T t, E sdkError) {
        // we take the results of the response... good and bad and wrap them in
        // a response object
        emitter.onNext(getResponse(t, sdkError));
        emitter.onComplete();
    }

    @Override
    public void onFailure(@NonNull Throwable throwable) {
        // here we just pass along the throwable
        if (!emitter.isDisposed()) {
            emitter.onError(throwable);
        }
    }

    @SuppressWarnings("unchecked")
    public R getResponse(T t, E sdkError) {
        return (R) new SDKResponse<>(t, sdkError);
    }
}