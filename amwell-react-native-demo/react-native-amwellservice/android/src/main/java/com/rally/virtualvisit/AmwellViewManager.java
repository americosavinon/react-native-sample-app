package com.rally.virtualvisit;

import com.facebook.react.common.MapBuilder;
import com.facebook.react.uimanager.SimpleViewManager;
import com.facebook.react.uimanager.ThemedReactContext;
import com.facebook.react.uimanager.annotations.ReactProp;

import java.util.Map;

public class AmwellViewManager extends SimpleViewManager<com.rally.virtualvisit.AmwellView> {

    public static final String REACT_CLASS = "AmwellView";

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
                        "statusChange",
                        MapBuilder.of(
                                "phasedRegistrationNames",
                                MapBuilder.of("bubbled", "onStatusChange")))
                .build();
    }
}