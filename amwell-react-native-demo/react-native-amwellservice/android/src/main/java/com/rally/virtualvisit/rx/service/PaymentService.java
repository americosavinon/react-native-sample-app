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
import com.americanwell.sdk.entity.billing.CreatePaymentRequest;
import com.americanwell.sdk.entity.billing.PaymentMethod;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.visit.Visit;
import com.americanwell.sdk.manager.ConsumerPaymentManager;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKValidatedCallback;
import com.rally.virtualvisit.rx.SDKResponse;
import com.rally.virtualvisit.rx.SDKValidatedResponse;

import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link ConsumerPaymentManager} calls and RxAndroid.
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
public class PaymentService extends BaseObservableService<ConsumerPaymentManager> {

    public PaymentService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected ConsumerPaymentManager getManager(AWSDK awsdk) {
        return awsdk.getConsumerPaymentManager();
    }

    public Observable<SDKResponse<PaymentMethod, SDKError>> getPaymentMethod(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<PaymentMethod, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<PaymentMethod, SDKError>> emitter) throws Exception {
                        getManager().getPaymentMethod(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<PaymentMethod, SDKError>> getPaymentMethod(
            @NonNull final Visit visit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<PaymentMethod, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<PaymentMethod, SDKError>> emitter) throws Exception {
                        getManager().getPaymentMethod(
                                visit,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<PaymentMethod, SDKError>> updatePaymentMethod(
            @NonNull final CreatePaymentRequest createPaymentRequest) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<PaymentMethod, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<PaymentMethod, SDKError>> emitter) throws Exception {
                        getManager().updatePaymentMethod(
                                createPaymentRequest,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }
}
