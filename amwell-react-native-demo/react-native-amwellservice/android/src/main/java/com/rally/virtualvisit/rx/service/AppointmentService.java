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
import com.americanwell.sdk.entity.SDKError;
import com.americanwell.sdk.entity.SDKLaunchParams;
import com.americanwell.sdk.entity.SDKLocalDate;
import com.americanwell.sdk.entity.consumer.AppointmentReadiness;
import com.americanwell.sdk.entity.consumer.AppointmentUpdateRequest;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.consumer.ReminderOption;
import com.americanwell.sdk.entity.provider.ProviderInfo;
import com.americanwell.sdk.entity.visit.Appointment;
import com.americanwell.sdk.entity.visit.Visit;
import com.americanwell.sdk.entity.visit.VisitReportDetail;
import com.americanwell.sdk.manager.ConsumerAppointmentManager;
import com.rally.virtualvisit.rx.ObservableEmitterSDKCallback;
import com.rally.virtualvisit.rx.ObservableEmitterSDKValidatedCallback;
import com.rally.virtualvisit.rx.SDKResponse;
import com.rally.virtualvisit.rx.SDKValidatedResponse;


import java.util.Date;
import java.util.List;

import io.reactivex.Observable;
import io.reactivex.ObservableEmitter;
import io.reactivex.ObservableOnSubscribe;

/**
 * This class bridges the SDK's asynchronous {@link ConsumerAppointmentManager} calls and RxAndroid.
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
public class AppointmentService extends BaseObservableService<ConsumerAppointmentManager> {

    public AppointmentService(AWSDK awsdk) {
        super(awsdk);
    }

    @Override
    protected ConsumerAppointmentManager getManager(AWSDK awsdk) {
        return awsdk.getConsumerAppointmentManager();
    }

    public Observable<SDKResponse<Appointment, SDKError>> getAppointment(
            @NonNull final Consumer consumer,
            @NonNull final SDKLaunchParams sdkLaunchParams) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Appointment, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Appointment, SDKError>> emitter) throws Exception {
                        getManager().getAppointment(
                                consumer,
                                sdkLaunchParams,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<List<Appointment>, SDKError>> getAppointments(
            @NonNull final Consumer consumer) {
        return getAppointments(consumer, null);
    }

    public Observable<SDKResponse<List<Appointment>, SDKError>> getAppointments(
            @NonNull final Consumer consumer,
            @Nullable final SDKLocalDate sinceDate) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<List<Appointment>, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<List<Appointment>, SDKError>> emitter) throws Exception {
                        getManager().getAppointments(
                                consumer,
                                sinceDate,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Void, SDKError>> cancelAppointment(
            @NonNull final Consumer consumer,
            @NonNull final Appointment appointment) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().cancelAppointment(
                                consumer,
                                appointment,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> scheduleAppointment(
            @NonNull final Consumer consumer,
            @NonNull final ProviderInfo provider,
            @NonNull final Date appointmentDate,
            @Nullable final String phoneNumber,
            @Nullable final ReminderOption consumerReminder,
            @Nullable final Visit reconnectedFromVisit) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().scheduleAppointment(
                                consumer,
                                provider,
                                appointmentDate,
                                phoneNumber,
                                consumerReminder,
                                null,
                                reconnectedFromVisit,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKValidatedResponse<Void, SDKError>> scheduleAppointment(
            @NonNull final Consumer consumer,
            @NonNull final ProviderInfo provider,
            @NonNull final Date appointmentDate,
            @Nullable final String phoneNumber,
            @Nullable final ReminderOption consumerReminder,
            @Nullable final VisitReportDetail visitReportDetail) {
        return Observable.create(
                new ObservableOnSubscribe<SDKValidatedResponse<Void, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKValidatedResponse<Void, SDKError>> emitter) throws Exception {
                        getManager().scheduleAppointment(
                                consumer,
                                provider,
                                appointmentDate,
                                phoneNumber,
                                consumerReminder,
                                null,
                                visitReportDetail,
                                new ObservableEmitterSDKValidatedCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<AppointmentReadiness, SDKError>> getAppointmentReadiness(
            @NonNull final Consumer consumer) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<AppointmentReadiness, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<AppointmentReadiness, SDKError>> emitter) throws Exception {
                        getManager().getAppointmentReadiness(consumer, new
                                ObservableEmitterSDKCallback(emitter, log));
                    }
                }
        );
    }

    public Observable<SDKResponse<AppointmentReadiness, SDKError>> updateAppointmentReadiness(
            @NonNull final Consumer consumer,
            @NonNull final AppointmentReadiness appointmentReadiness) {
        return Observable.create(
                new ObservableOnSubscribe<SDKResponse<AppointmentReadiness, SDKError>>() {
                    @Override
                    public void subscribe(
                            @io.reactivex.annotations.NonNull ObservableEmitter
                                    <SDKResponse<AppointmentReadiness, SDKError>> emitter) throws Exception {
                        getManager().updateAppointmentReadiness(
                                consumer,
                                appointmentReadiness,
                                new ObservableEmitterSDKCallback(emitter, log)
                        );
                    }
                }
        );
    }

    public Observable<SDKResponse<Appointment, SDKError>> updateAppointment(
            @NonNull final Consumer consumer,
            @NonNull final AppointmentUpdateRequest updateRequest) {
        return Observable.create(new ObservableOnSubscribe<SDKResponse<Appointment, SDKError>>() {
            @Override
            public void subscribe(@io.reactivex.annotations.NonNull ObservableEmitter<SDKResponse<Appointment, SDKError>> emitter) throws Exception {
                getManager().updateAppointment(
                        consumer,
                        updateRequest,
                        new ObservableEmitterSDKCallback(emitter, log)
                );
            }
        });
    }
}
