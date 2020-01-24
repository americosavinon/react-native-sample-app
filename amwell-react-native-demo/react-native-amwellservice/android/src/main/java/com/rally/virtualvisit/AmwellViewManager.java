package com.rally.virtualvisit;

import android.util.Log;

import com.facebook.infer.annotation.Assertions;
import com.facebook.react.bridge.ReadableArray;
import com.facebook.react.common.MapBuilder;
import com.facebook.react.uimanager.SimpleViewManager;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.annotations.ReactProp;

import java.util.Map;

public class AmwellViewManager extends SimpleViewManager<com.rally.virtualvisit.AmwellView> {

    public static final String REACT_CLASS = "AmwellView";

    public static final int COMMAND_TEST_VIDEO_CALL = 1;

    @Override
    public String getName() { return REACT_CLASS; }

    @Override
    public com.rally.virtualvisit.AmwellView createViewInstance(ThemedReactContext context) {
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
                    "onChange",
                    MapBuilder.of(
                        "phasedRegistrationNames",
                        MapBuilder.of("bubbled", "onUpdate")))
                .build();
    }


    @Override
    public Map<String,Integer> getCommandsMap() {
        Log.d("React"," View manager getCommandsMap:");
        return MapBuilder.of(
                "testVideoCall",
                COMMAND_TEST_VIDEO_CALL);
    }

    @Override
    public void receiveCommand(
            AmwellView view,
            int commandType,
            ReadableArray args) {

        Assertions.assertNotNull(view);
        Assertions.assertNotNull(args);

        switch (commandType) {
            case COMMAND_TEST_VIDEO_CALL: {
                view.demoVideoCall();
                return;
            }

            default:
                throw new IllegalArgumentException(String.format(
                        "Unsupported command %d received by %s.",
                        commandType,
                        getClass().getSimpleName()));
        }
    }

}