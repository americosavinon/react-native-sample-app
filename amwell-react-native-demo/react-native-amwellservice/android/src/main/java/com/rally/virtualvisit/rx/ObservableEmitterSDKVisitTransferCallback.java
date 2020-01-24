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
import com.americanwell.sdk.entity.visit.Visit;
import com.americanwell.sdk.entity.visit.VisitContext;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.americanwell.sdk.manager.VisitTransferCallback;

import java.util.Map;

import io.reactivex.ObservableEmitter;

/**
 * Extension of the base callback to provide support for the {@link VisitTransferCallback}
 */
public class ObservableEmitterSDKVisitTransferCallback
        extends ObservableEmitterSDKCallback<SDKVisitTransferResponse<VisitContext, SDKError>, Void, SDKError>
        implements VisitTransferCallback {

    public ObservableEmitterSDKVisitTransferCallback(
            final ObservableEmitter<SDKVisitTransferResponse<VisitContext, SDKError>> emitter,
            final AWSDKLogger log) {
        super(emitter, log);
    }

    @Override
    public void onVisitTransfer(@NonNull Visit visit) {
        final SDKVisitTransferResponse<VisitContext, SDKError> response
                = new SDKVisitTransferResponse<>();
        response.setVisitRedirect(visit);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onProviderUnavailable() {
        final SDKVisitTransferResponse<VisitContext, SDKError> response
                = new SDKVisitTransferResponse<>();
        response.setProviderUnavailable(true);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onStartNewVisit(@NonNull Visit visit) {
        final SDKVisitTransferResponse<VisitContext, SDKError> response
                = new SDKVisitTransferResponse<>();
        response.setNewVisit(visit);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onNewVisitContext(@NonNull VisitContext visitContext) {
        final SDKVisitTransferResponse<VisitContext, SDKError> response
                = new SDKVisitTransferResponse<>();
        response.setVisitContext(visitContext);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public void onValidationFailure(@NonNull Map<String, String> validationReasons) {
        final SDKVisitTransferResponse<Void, SDKError> response
                = new SDKVisitTransferResponse<>(null, null, validationReasons);
        emitter.onNext(response);
        emitter.onComplete();
    }

    @Override
    public SDKVisitTransferResponse getResponse(Void aVoid, SDKError sdkError) {
        return new SDKVisitTransferResponse<>(aVoid, sdkError, null);
    }
}
