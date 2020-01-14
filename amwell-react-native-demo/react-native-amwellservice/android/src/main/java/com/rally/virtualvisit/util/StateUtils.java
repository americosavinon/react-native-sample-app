/*
 * Copyright 2016 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */
package com.rally.virtualvisit.util;

import com.americanwell.sdk.entity.consumer.Consumer;

import java.util.ArrayList;

/**
 * Small class used to store state on the "application" level.
 * currently only using this to hang on to the consumer once it's been
 * fetched.  this is just a convenience.  could also just pass it around
 * from activity to activity.
 */
public class StateUtils {
    private ArrayList<Consumer> dependents; // dependents of logged in consumer
    private Consumer consumer; // currently selected consumer
    private Consumer loginConsumer; // consumer that logged in (aka parent)

    public Consumer getConsumer() {
        return consumer;
    }

    public void setConsumer(final Consumer consumer) {
        this.consumer = consumer;
    }

    public Consumer getLoginConsumer() {
        return loginConsumer;
    }

    public void setLoginConsumer(Consumer loginConsumer) {
        this.consumer = loginConsumer; // initialize consumer to login consumer
        this.loginConsumer = loginConsumer;
    }

    public ArrayList<Consumer> getDependents() {
        return dependents;
    }

    public void setDependents(ArrayList<Consumer> dependents) {
        this.dependents = dependents;
    }
}
