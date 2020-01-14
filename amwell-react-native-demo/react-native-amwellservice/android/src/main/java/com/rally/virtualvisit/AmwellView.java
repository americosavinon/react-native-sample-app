package com.rally.virtualvisit;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Color;
import android.util.AttributeSet;
import android.view.View;
import android.widget.Button;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.uimanager.events.RCTEventEmitter;

@SuppressLint("AppCompatCustomView")
public class AmwellView extends Button {

    public Boolean isOn = false;
    public void setIsOn (Boolean initialBulbStatus){
        isOn = initialBulbStatus;
        updateButton();

    }

    // private void changeStatus() {
    public void onReceiveNativeEvent() {
        System.out.println("onReceiveNativeEvent called~!");
        WritableMap event = Arguments.createMap();
        event.putBoolean("isOn", isOn);

        ReactContext reactContext = (ReactContext)getContext();

        reactContext.getJSModule(RCTEventEmitter.class).receiveEvent(
                getId(),
                "statusChange",
                event);

        if (isOn) {
            setBackgroundColor(Color.YELLOW);
            setText("Switch OFF");
        } else {
            setBackgroundColor(Color.BLACK);
            setText("Switch ON");
        }
    }

    public AmwellView(Context context) {
        super(context);
        this.setTextColor(Color.BLUE); // start with blue

        this.setOnClickListener(changeStatusListener); // initialize the event listener

        updateButton();
    }

    public AmwellView(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public AmwellView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }

    private OnClickListener changeStatusListener = new OnClickListener() {
        public void onClick(View v) {
            isOn = !isOn;
            updateButton();
            System.out.println("Event Click Called!");
            onReceiveNativeEvent();
        }
    };

    private void updateButton() {
        if (isOn) {
            setBackgroundColor(Color.YELLOW);
            setText("Switch OFF");
        } else {
            setBackgroundColor(Color.BLACK);
            setText("Switch ON");
        }
    }
}