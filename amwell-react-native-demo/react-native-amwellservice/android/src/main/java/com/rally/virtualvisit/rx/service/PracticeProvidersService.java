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
import androidx.annotation.Nullable;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.entity.Language;
import com.americanwell.sdk.entity.PracticesCategories;
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.practice.OnDemandSpecialty;
import com.americanwell.sdk.entity.practice.Practice;
import com.americanwell.sdk.entity.practice.PracticeInfo;
import com.americanwell.sdk.entity.provider.AvailableProviders;
import com.americanwell.sdk.entity.provider.Provider;
import com.americanwell.sdk.entity.provider.ProviderInfo;
import com.americanwell.sdk.manager.PracticeProvidersManager;

import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.SDKResponse;


import java.util.Date;
import java.util.List;

import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link PracticeProvidersManager} calls and RxAndroid.
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
public class PracticeProvidersService extends BaseObservableService<PracticeProvidersManager> {

    public PracticeProvidersService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected PracticeProvidersManager getManager(AWSDK awsdk) {
        return awsdk.getPracticeProvidersManager();
    }

    public Observable<SDKResponse<List<PracticeInfo>, SDKError>> findPractices(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<PracticeInfo>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<PracticeInfo>, SDKError>> emitter) throws Exception {
                        getManager().findPractices(
                                consumer,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<PracticeInfo>, SDKError>> getPractices(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<PracticeInfo>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<PracticeInfo>, SDKError>> emitter) throws Exception {
                        getManager().getPractices(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<PracticesCategories, SDKError>> getPracticesWithCategories(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<PracticesCategories, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<PracticesCategories, SDKError>> emitter) throws Exception {
                        getManager().getPracticesWithCategories(
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Practice, SDKError>> getService(
            @NonNull final PracticeInfo practiceInfo) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Practice, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Practice, SDKError>> emitter) throws Exception {
                        getManager().getPractice(
                                practiceInfo,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<ProviderInfo>, SDKError>> findProviders(
            @NonNull final Consumer consumer,
            @NonNull final PracticeInfo practiceInfo,
            @Nullable final Language languageSpoken) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<ProviderInfo>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<ProviderInfo>, SDKError>> emitter) throws Exception {
                        getManager().findProviders(
                                consumer,
                                practiceInfo,
                                null,
                                null,
                                null,
                                null,
                                null,
                                languageSpoken,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<OnDemandSpecialty>, SDKError>> getSpecialties(
            @NonNull final Consumer consumer,
            @NonNull final PracticeInfo practiceInfo) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<OnDemandSpecialty>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<OnDemandSpecialty>, SDKError>> emitter) throws Exception {
                        getManager().getOnDemandSpecialties(
                                consumer,
                                practiceInfo,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<AvailableProviders, SDKError>> findAvailableProviders(
            @NonNull final Consumer consumer,
            @NonNull final PracticeInfo practiceInfo,
            @Nullable final Date date,
            @Nullable final Language language) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<AvailableProviders, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<AvailableProviders, SDKError>> emitter) throws Exception {
                        getManager().findFutureAvailableProviders(
                                consumer,
                                practiceInfo,
                                null,
                                language,
                                date,
                                null,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Date>, SDKError>> findAvailableDates(
            @NonNull final Consumer consumer,
            @NonNull final PracticeInfo practiceInfo,
            @Nullable final Date date,
            @Nullable final Language language) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Date>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<Date>, SDKError>> emitter) throws Exception {
                        getManager().findFutureAvailableDates(
                                consumer,
                                practiceInfo,
                                null,
                                language,
                                date,
                                null,
                                null,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Provider, SDKError>> getProvider(
            @Nullable final Consumer consumer,
            @NonNull final ProviderInfo providerInfo) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Provider, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Provider, SDKError>> emitter) throws Exception {
                        getManager().getProvider(
                                providerInfo,
                                consumer,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Date>, SDKError>> getProviderAvailability(
            @NonNull Consumer consumer,
            @NonNull Provider provider,
            @Nullable Date appointmentDate,
            @Nullable Integer limitInDays) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Date>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<Date>, SDKError>> emitter) throws Exception {
                        getManager().getProviderAvailability(
                                consumer,
                                provider,
                                appointmentDate,
                                limitInDays,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }
}
