/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.rx.service;

import androidx.annotation.NonNull;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.insurance.SubscriptionUpdateRequest;
import com.americanwell.sdk.manager.ConsumerSubscriptionManager;
import com.rally.virtualvisit.rx.ObservableEmitterSDKValidatedCallback;
import com.rally.virtualvisit.rx.SDKValidatedResponse;

import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link ConsumerSubscriptionManager} calls and RxAndroid.
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
public class SubscriptionService extends BaseObservableService<ConsumerSubscriptionManager> {

    public SubscriptionService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected ConsumerSubscriptionManager getManager(AWSDK awsdk) {
        return awsdk.getConsumerSubscriptionManager();
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> updateSubscription(
            @NonNull final SubscriptionUpdateRequest subscriptionUpdateRequest) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().updateInsuranceSubscription(
                                subscriptionUpdateRequest,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }
}
