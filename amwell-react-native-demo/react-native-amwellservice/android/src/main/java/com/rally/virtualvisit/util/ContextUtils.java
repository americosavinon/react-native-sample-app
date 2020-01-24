/*
 * Copyright 2017 American Well Systems
 * All rights reserved.
 * <p/>
 * It is illegal to use, reproduce or distribute
 * any part of this Intellectual Property without
 * prior written authorization from American Well.
 */

package com.rally.virtualvisit.util;

import android.content.Context;
import android.os.Build;
import androidx.annotation.ColorRes;

/**
 * Helper utils for things around the Android {@link Context}
 *
 * @since AWSDK 3.2
 */
public class ContextUtils {

    public ContextUtils() {
    }

    /**
     * Util method to get a color (int) with the correct mechanism per API
     *
     * @param context
     * @param colorId
     * @return
     * @since AWSDK 3.2
     */
    public int getColor(final Context context, @ColorRes int colorId) {
        final int color;
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            color = context.getColor(colorId);
        }
        else {
            //noinspection deprecation
            color = context.getResources().getColor(colorId);
        }
        return color;
    }
}
