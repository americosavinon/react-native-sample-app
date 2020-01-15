/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.rx;

import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.visit.ConsumerInitiatedIVRStatus;

import java.util.Map;

/**
 * This is a custom variation of SDKResponse used to handle the responses from
 * IVRCallback
 */
public class SDKIVRResponse<T, E extends SDKError> extends SDKValidatedResponse<T, E> {

    private @ConsumerInitiatedIVRStatus String status;
    private int retryCount;

    public SDKIVRResponse(T result, E error, Map<String, String> validationReasons) {
        super(result, error, validationReasons);
    }

    public SDKIVRResponse() {
        super(null, null, null);
    }

    public @ConsumerInitiatedIVRStatus
    String getStatus() {
        return status;
    }

    public void setStatus(@ConsumerInitiatedIVRStatus String status) {
        this.status = status;
    }

    public int getRetryCount() {
        return retryCount;
    }

    public void setRetryCount(int retryCount) {
        this.retryCount = retryCount;
    }
}
