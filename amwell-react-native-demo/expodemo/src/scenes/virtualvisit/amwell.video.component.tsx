import React, { useState, useRef, useEffect } from "react";
import {
  StyleSheet,
  Image,
  View,
  TouchableOpacity,
  UIManager,
  findNodeHandle
} from "react-native";

import { Colors } from "react-native/Libraries/NewAppScreen";

import {
  Amwellservice,
  AmwellVirtualVisitView
} from "react-native-amwellservice";

// The toast is for simple debug/demo usage
import Toast from "react-native-simple-toast";
import { Divider, Layout, Text } from "@ui-kitten/components";
import { Toolbar } from "../../components/toolbar.component";

import {
  SafeAreaLayout,
  SafeAreaLayoutElement,
  SaveAreaInset
} from "../../components/safe-area-layout.component";

export const AmwellVideoScreen = (props): SafeAreaLayoutElement => {
  const [message, setMessage] = useState("");
  const [status, setStatus] = useState(false);

  const amwellviewInstance = useRef(null);
  // useEffect(() => mySwiftComponentInstance.current);

  const onButtonClick = () => {
    console.log("virtual visit demo clicked!");
    console.log(Amwellservice);
    // Amwellservice.sampleMethod("sss", 1, () => {
    //   console.log("callback!");
    // });
    // setMessage("");

    // // console.log(amwellviewInstance);
    // amwellviewInstance.current.testVideoCall();
  };

  const onUpdate = (event: Object) => {
    console.log("Received params: " + JSON.stringify(event));

    if (event["vv-debug"] == "Wait for provider to connect!") {
      setMessage(event["vv-debug"]);
    }

    if (event["vv-error"] != null) {
      setMessage(event["vv-error"]);
    } else {
      Toast.show(event["vv-debug"]);
    }
  };

  const onClick = (event: Object) => {
    console.log("Received params: " + JSON.stringify(event));
  };

  return (
    <SafeAreaLayout style={styles.safeArea} insets={SaveAreaInset.TOP}>
      <Toolbar
        title="Amwell SDK Virtual Visit Demo"
        onBackPress={props.navigation.goBack}
      />
      <Divider />
      <Layout style={styles.container}>
        <View style={styles.container}>
          <Text style={{ fontWeight: "bold", paddingBottom: 20 }}>
            {message}
          </Text>

          <Text>Press to start test video call!</Text>
          <TouchableOpacity onPress={onButtonClick}>
            <Image
              style={styles.button}
              source={require("../../assets/video-call.jpeg")}
            />
          </TouchableOpacity>
          {/* <AmwellVirtualVisitView
            onChangeMessage={onClick}
            style={styles.nativeViewStyle}
            ref={amwellviewInstance}
          ></AmwellVirtualVisitView> */}
          <Text>Note: Make sure Provider [Test Four] is online!</Text>
        </View>
      </Layout>
    </SafeAreaLayout>
  );
};

const styles = StyleSheet.create({
  safeArea: {
    flex: 1
  },
  scrollView: {
    backgroundColor: Colors.lighter
  },
  engine: {
    position: "absolute",
    right: 0
  },
  body: {
    backgroundColor: Colors.lighter
  },
  sectionContainer: {
    marginTop: 32,
    paddingHorizontal: 24
  },
  sectionTitle: {
    fontSize: 24,
    fontWeight: "600",
    color: Colors.black
  },
  sectionDescription: {
    marginTop: 8,
    fontSize: 18,
    fontWeight: "400",
    color: Colors.dark
  },

  highlight: {
    fontWeight: "700"
  },

  footer: {
    color: Colors.dark,
    fontSize: 12,
    fontWeight: "600",
    padding: 4,
    paddingRight: 12,
    textAlign: "right"
  },

  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
    width: "100%",
    elevation: 4,
    shadowOffset: { width: 5, height: 5 },
    shadowColor: "grey",
    shadowOpacity: 0.5,
    shadowRadius: 10
  },

  nativeViewStyle: {
    height: 100,
    color: Colors.black,
    borderWidth: 1,
    width: "90%"
  },

  button: {
    width: 100,
    height: 100,
    borderWidth: 0,
    backgroundColor: "rgba(52, 52, 52, 0.8)"
  }
});
