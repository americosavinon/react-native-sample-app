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
import com.americanwell.sdk.logging.AWSDKLogger;

/**
 * This is the base class to bridge the SDK's asynchronous manager calls and RxAndroid.
 */
public abstract class BaseObservableService<T> {

    private AWSDK awsdk;
    protected AWSDKLogger log;

    public BaseObservableService(AWSDK awsdk) {
        this.awsdk = awsdk;
        log = awsdk.getDefaultLogger();
    }

    protected T getManager() {
        return getManager(awsdk);
    }

    protected abstract T getManager(AWSDK awsdk);
}
