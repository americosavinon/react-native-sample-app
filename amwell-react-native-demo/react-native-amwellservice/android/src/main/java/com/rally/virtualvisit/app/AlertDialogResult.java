/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.app;

import androidx.annotation.IntDef;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * Values representing the different request codes when handling dialogs.
 */
public interface AlertDialogResult {
    @Retention(RetentionPolicy.SOURCE)
    @IntDef({
                    Action.NO_ACTION,
                    Action.GO_HOME,
                    Action.FINISH,
                    Action.LEAVE_WAITING_ROOM,
                    Action.GOTO_LOGIN,
                    Action.FATAL_EVENT,
                    Action.SUGGEST_FIND_FIRST_AVAILABLE,
                    Action.GOTO_MY_ACCOUNT
            })
    @interface Action {
        /**
         * Indicates no further action is required
         */
        int NO_ACTION = 550;

        /**
         * Indicates the user should be brought to the home screen upon closure of the error dialog.
         */
        int GO_HOME = 551;

        /**
         * Indicates the current activity should be finished upon closure of the error dialog.
         */
        int FINISH = 552;

        /**
         * Indicates the user should leave the waiting room upon closure of the error dialog.
         */
        int LEAVE_WAITING_ROOM = 553;

        /**
         * Indicates the user should return to login upon closure of the error dialog.
         */
        int GOTO_LOGIN = 554;

        /**
         * Indicates that some fatal event occured and user should return to login.
         */
        int FATAL_EVENT = 555;

        /**
         * Indicates the activity should finish handling the Find First Available Suggestion workflow upon closure of
         * the error dialog.
         */
        int SUGGEST_FIND_FIRST_AVAILABLE = 556;

        /**
         * Indicates the user should goto "My Information" screen.
         */
        int GOTO_MY_ACCOUNT = 557;

    }
}