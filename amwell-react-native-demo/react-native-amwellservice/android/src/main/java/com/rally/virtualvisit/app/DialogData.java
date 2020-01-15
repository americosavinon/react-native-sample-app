/*
 * Copyright 2018 American Well Systems
 * All rights reserved.
 * <p>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.app;

import androidx.annotation.StringDef;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

/**
 * StringDef keys used for setting the data in custom Dialog classes.
 *
 * @since 4.1
 */
@Retention(RetentionPolicy.SOURCE)
@StringDef({
                   DialogData.TITLE,
                   DialogData.MESSAGE,
                   DialogData.RESULT_CODE,
                   DialogData.POSITIVE_TEXT,
                   DialogData.NEUTRAL_TEXT,
                   DialogData.NEGATIVE_TEXT,
                   DialogData.CANCEL_ON_TOUCH_OUTSIDE,
           })
public @interface DialogData {

    String TITLE = "TITLE";
    String MESSAGE = "MESSAGE";
    String RESULT_CODE = "RESULT_CODE";
    String POSITIVE_TEXT = "POSITIVE_TEXT";
    String NEUTRAL_TEXT = "NEUTRAL_TEXT";
    String NEGATIVE_TEXT = "NEGATIVE_TEXT";
    String CANCEL_ON_TOUCH_OUTSIDE = "CANCEL_ON_TOUCH_OUTSIDE";
}
