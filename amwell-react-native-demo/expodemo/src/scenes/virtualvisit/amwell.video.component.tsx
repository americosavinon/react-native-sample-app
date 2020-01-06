import React from "react";
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
  RNCounterView,
  RNAmwellView
} from "react-native-amwellservice";

import { Divider, Layout, Text } from "@ui-kitten/components";

import { Toolbar } from "../../components/toolbar.component";

import {
  SafeAreaLayout,
  SafeAreaLayoutElement,
  SaveAreaInset
} from "../../components/safe-area-layout.component";

export const AmwellVideoScreen = (props): SafeAreaLayoutElement => {
  const onButtonClick = e => {
    console.log("button clicked!!!");
    // console.log(UIManager.getConstants());

    console.log(UIManager.getViewManagerConfig("AmwellView"));
    UIManager.dispatchViewManagerCommand(
      findNodeHandle(this.mySwiftComponentInstance),
      UIManager["AmwellView"].Commands.updateValueViaManager,
      []
    );
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
          <Text>Press to start test video call!</Text>
          <TouchableOpacity onPress={onButtonClick}>
            <Image
              style={styles.button}
              source={require("../../assets/video-call.jpeg")}
            />
          </TouchableOpacity>
          <RNAmwellView
            style={styles.nativeViewStyle}
            ref={ref => (this.mySwiftComponentInstance = ref)}
          ></RNAmwellView>
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
    borderWidth: 0,
    width: "90%"
  },

  button: {
    width: 100,
    height: 100,
    borderWidth: 0,
    backgroundColor: "rgba(52, 52, 52, 0.8)"
  }
});
