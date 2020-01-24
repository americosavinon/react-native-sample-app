package com.rally.virtualvisit;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.americanwell.sdk.AWSDK;
import com.americanwell.sdk.AWSDKFactory;
import com.americanwell.sdk.entity.Authentication;
import com.americanwell.sdk.entity.VisitModality;
import com.americanwell.sdk.entity.VisitModalityType;
import com.americanwell.sdk.entity.consumer.Consumer;
import com.americanwell.sdk.entity.practice.PracticeInfo;
import com.americanwell.sdk.entity.provider.Provider;
import com.americanwell.sdk.entity.provider.ProviderInfo;
import com.americanwell.sdk.entity.provider.ProviderVisibility;
import com.americanwell.sdk.entity.visit.Visit;
import com.americanwell.sdk.entity.visit.VisitContext;
import com.americanwell.sdk.exception.AWSDKInstantiationException;
import com.americanwell.sdk.logging.AWSDKLogger;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.uimanager.events.RCTEventEmitter;
import com.rally.virtualvisit.rx.service.AuthenticationService;
import com.rally.virtualvisit.rx.service.ConsumerService;
import com.rally.virtualvisit.rx.service.PracticeProvidersService;
import com.rally.virtualvisit.rx.service.VisitService;

import java.util.List;
import java.util.Set;


import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_AUDIO;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_DEFAULT;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_MEDIA;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_NETWORKING;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_PERMISSIONS;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_VIDEO;
import static com.americanwell.sdk.logging.AWSDKLogger.LOG_CATEGORY_VISIT;

@SuppressLint("AppCompatCustomView")
public class AmwellView extends Button {

    private Context applicationContext = null;

    private final static String LOG_TAG = AmwellView.class.getName();

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

        applicationContext = context;
        this.setTextColor(Color.BLUE); // start with blue
        this.setOnClickListener(changeStatusListener); // initialize the event listener

        updateButton();

        // initialize sdk
        initSDK();
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

    public void demoVideoCall() {
        // start to test some service code logic here
        AuthenticationService authenticationService = new AuthenticationService(awsdk);
        PracticeProvidersService practiceProvidersService = new PracticeProvidersService(awsdk);
        ConsumerService consumerService = new ConsumerService(awsdk);
        VisitService visitService = new VisitService(awsdk);

        // initialize sdk
        authenticationService.initializeSdk("https://iot58.amwellintegration.com/",
                "bf8a5665", null, null).subscribe(x -> {
            System.out.println("SDK Initialize Success!");
            authenticationService.authenticate("yunfeng.lin@rallyhealth.com", "cs123!@#")
                    .subscribe(a -> {
                        Authentication auth = a.getResult();
                        System.out.println("Auth success!");
                        System.out.println("Consumer Name:" + auth.getConsumerInfo().getFullName());

                        consumerService.getConsumer(auth)
                                .subscribe(consumer -> {
                                    Consumer consumerItem = consumer.getResult();
                                    practiceProvidersService.getPractices(consumerItem)
                                            .subscribe(practice -> {
                                                List<PracticeInfo> info = practice.getResult();
                                                System.out.println("get practice info");

                                                // get the provider
                                                practiceProvidersService.findProviders(null, info.get(0), null)
                                                        .subscribe(providers -> {
                                                            List<ProviderInfo> providerInfos = providers.getResult();
                                                            ProviderInfo target = providerInfos.get(0);

                                                            // Loop through the Providers
                                                            for(int i = 0; i < providerInfos.size(); i ++ ) {
                                                                ProviderInfo pInfo = providerInfos.get(i);
                                                                if (pInfo.getLastName() == "Four") {
                                                                    target = pInfo;
                                                                    break;
                                                                }
                                                            }

                                                            // check if the provider is offline
                                                            if (target.getVisibility() == ProviderVisibility.OFFLINE) {
                                                                System.out.println("Provider is offline!");
                                                                return;
                                                            }

                                                            // find the provider with provider Info
                                                            practiceProvidersService.getProvider(null, target)
                                                                    .subscribe(provider -> {
                                                                        Provider pInfo = provider.getResult();

                                                                        // create visit context
                                                                        visitService.getVisitContext(consumerItem, pInfo)
                                                                                .subscribe(vcontext -> {
                                                                                    VisitContext ctx = vcontext.getResult();
                                                                                    System.out.println("Create VisitContext success!");
                                                                                    // update the context
                                                                                    Set<VisitModality> availableModalities = ctx.getPractice().getVisitModalities();
                                                                                    VisitModality visitModality = null;
                                                                                    for (VisitModality vm : availableModalities) {
                                                                                        visitModality = vm;
                                                                                        // video is the default
                                                                                        if (VisitModalityType.VIDEO.equals(vm.getModalityType())) {
                                                                                            break;
                                                                                        }
                                                                                    }

                                                                                    ctx.getLegalTexts().get(0).setAccepted(true);
                                                                                    ctx.setModality(visitModality);

                                                                                    // create visit
                                                                                    visitService.buildVisit(ctx)
                                                                                            .subscribe(visit -> {
                                                                                                Visit vEntity = visit.getResult();

                                                                                                // now we need to start visit, we might get provider offline error here.
                                                                                                visitService.startVisit(vEntity, vEntity.getConsumer().getAddress(), null)
                                                                                                        .subscribe(x1 -> {

                                                                                                            if (x1.getIntent() != null) {
                                                                                                                System.out.println(x1.getIntent());
                                                                                                                // start activity
                                                                                                                Intent intentView = x1.getIntent();
                                                                                                                intentView.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                                                                                                                applicationContext.startActivity(x1.getIntent());
//                                                                                                                  finish();
                                                                                                            }
                                                                                                        }, err -> {
                                                                                                            System.out.println(err.getMessage());
                                                                                                        });

                                                                                            }, err -> {
                                                                                                System.out.println("build visit failed");
                                                                                                System.out.println(err.getMessage());
                                                                                            });

                                                                                }, err -> System.out.println("get visit context failed"));

                                                                    }, err -> System.out.println("get provider failed"));

                                                        }, err -> System.out.println("get providerInfo failed!"));

                                            }, err -> System.out.println("get practice failed!"));

                                }, err -> System.out.println("get consumer failed!"));


                    }, err -> System.out.println("auth error!"));
        }, error -> System.out.println(error.getMessage()));
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