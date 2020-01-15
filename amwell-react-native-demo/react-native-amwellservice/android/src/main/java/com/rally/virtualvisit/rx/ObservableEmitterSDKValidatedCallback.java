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
import com.americanwell.sdk.manager.SDKValidatedCallback;

import java.util.Map;

import io.reactivex.ObservableEmitter;

/**
 * Extension of base callback to add support for validation
 */
public class ObservableEmitterSDKValidatedCallback<T, E extends SDKError>
        extends ObservableEmitterSDKCallback<SDKValidatedResponse, T, E>
        implements SDKValidatedCallback<T, E> {

    public ObservableEmitterSDKValidatedCallback(final ObservableEmitter<SDKValidatedResponse> emitter,
                                                 AWSDKLogger log) {
        super(emitter, log);
    }

    @Override
    public SDKValidatedResponse getResponse(T t, E e) {
        return new SDKValidatedResponse<>(t, e, null);
    }

    @Override
    public void onValidationFailure(@NonNull Map<String, String> validationReasons) {
        emitter.onNext(new SDKValidatedResponse<T, E>(null, null, validationReasons));
        emitter.onComplete();
    }

}