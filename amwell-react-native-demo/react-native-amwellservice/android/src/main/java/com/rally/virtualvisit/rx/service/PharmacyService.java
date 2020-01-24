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
import com.americanwell.sdk.entity.Address;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.pharmacy.Pharmacy;
import com.americanwell.sdk.manager.ConsumerPharmacyManager;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKValidatedCallback;
import com.rally.virtualvisit.rx.SDKResponse;
import com.rally.virtualvisit.rx.SDKValidatedResponse;

import java.util.List;

import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link ConsumerPharmacyManager} calls and RxAndroid.
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
public class PharmacyService extends BaseObservableService<ConsumerPharmacyManager> {

    public PharmacyService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected ConsumerPharmacyManager getManager(AWSDK awsdk) {
        return awsdk.getConsumerPharmacyManager();
    }

    public Observable<SDKResponse<Void, SDKError>> updatePharmacy(
            @NonNull final Consumer consumer,
            @NonNull final Pharmacy pharmacy) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().updateConsumerPharmacy(
                                consumer,
                                pharmacy,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<List<Pharmacy>, SDKError>> findPharmaciesByZip(
            @NonNull final Consumer consumer,
            @NonNull final String zipCode) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<List<Pharmacy>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<List<Pharmacy>, SDKError>> emitter) throws Exception {

                        getManager().getPharmacies(
                                consumer,
                                null,
                                null,
                                null,
                                zipCode,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Pharmacy>, SDKError>> findPharmaciesNearMe(
            @NonNull final Consumer consumer,
            @NonNull final float latitude,
            @NonNull final float longitude,
            @NonNull final int radius,
            @NonNull final boolean excludeMailOrder) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Pharmacy>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<Pharmacy>, SDKError>> emitter) throws Exception {
                        getManager().getPharmacies(
                                consumer,
                                latitude,
                                longitude,
                                radius,
                                excludeMailOrder,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Pharmacy>, SDKError>> getPharmacies(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Pharmacy>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<Pharmacy>, SDKError>> emitter) throws Exception {
                        getManager().getConsumerPharmacies(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Address, SDKError>> getShippingAddress(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Address, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Address, SDKError>> emitter) throws Exception {
                        getManager().getShippingAddress(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Address, SDKError>> updateShippingAddress(
            @NonNull final Consumer consumer,
            @NonNull final Address address) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Address, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Address, SDKError>> emitter) throws Exception {
                        getManager().updateShippingAddress(
                                consumer,
                                address,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }
}
