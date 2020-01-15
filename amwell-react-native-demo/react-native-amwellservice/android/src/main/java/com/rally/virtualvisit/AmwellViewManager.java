package com.rally.virtualvisit;

import android.content.Context;
import android.util.Log;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.AWSDKFactory;
import com.americanwell.sdk.exception.AWSDKInstantiationException;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.facebook.react.common.MapBuilder;
import com.facebook.react.uimanager.SimpleViewManager;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.annotations.ReactProp;

import java.util.Map;

import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_AUDIO;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_DEFAULT;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_MEDIA;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_NETWORKING;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_PERMISSIONS;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_VIDEO;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_VISIT;

public class AmwellViewManager extends SimpleViewManager<com.rally.virtualvisit.AmwellView> {

    public static final String REACT_CLASS = "AmwellView";
    private Context applicationContext = null;
    private final static String LOG_TAG = AmwellViewManager.class.getName();

    @Override
    public String getName() { return REACT_CLASS; }

    @Override
    public com.rally.virtualvisit.AmwellView createViewInstance(ThemedReactContext context) {
        applicationContext = context.getApplicationContext();

        // initialize sdk
        initSDK();

        com.rally.virtualvisit.AmwellView view = new com.rally.virtualvisit.AmwellView(context);
        return view;
    }

    @ReactProp(name="isOn")
    public void setAmwellStatus(com.rally.virtualvisit.AmwellView amwellView, Boolean isOn) {
        amwellView.setIsOn(isOn);
    }

    @Override
    public Map getExportedCustomBubblingEventTypeConstants() {
        return MapBuilder.builder()
                .put(
                        "statusChange",
                        MapBuilder.of(
                                "phasedRegistrationNames",
                                MapBuilder.of("bubbled", "onStatusChange")))
                .build();
    }

    // ================== Start for Amwell SDK ============================
    private AWSDK awsdk = null;

    /**
     * This should be the only place you get the {@link AWSDK} instance object.
     *
     * @return
     */
    public AWSDK getAWSDK() {
        return awsdk;
    }

    private void initSDK() {
        try {
            awsdk = AWSDKFactory.getAWSDK(applicationContext);
            awsdk.getDefaultLogger().setPriority(Log.DEBUG); // set log level to debug

            // Set the categories for the logs you want displayed. Setting this to null will allow all categories to be displayed.
            @AWSDKLogger.AWSDKLogCategory
            String[] categories = {LOG_CATEGORY_DEFAULT, LOG_CATEGORY_VIDEO, LOG_CATEGORY_AUDIO,
                    LOG_CATEGORY_PERMISSIONS, LOG_CATEGORY_MEDIA, LOG_CATEGORY_VISIT, LOG_CATEGORY_NETWORKING};
            awsdk.getDefaultLogger().setLogCategories(categories);

            awsdk.getDefaultLogger().log(0, "Initialized sdk success!", "Category", null);
        }
        catch (AWSDKInstantiationException e) {
            Log.e(LOG_TAG, "Unable to instantiate AWSDK instance", e);// using android log here b/c defaultlogger won't be available
        }
    }

}