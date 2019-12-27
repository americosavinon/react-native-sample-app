import React from "react";
import {
  StyleSheet,
  Text,
  Image,
  View,
  TouchableOpacity,
  UIManager,
  Button,
  findNodeHandle
} from "react-native";

import {
  Amwellservice,
  RNCounterView,
  RNAmwellView
} from "react-native-amwellservice";

import {
  Header,
  LearnMoreLinks,
  Colors,
  DebugInstructions,
  ReloadInstructions
} from "react-native/Libraries/NewAppScreen";

export default function App() {
  console.log(" ======== Testing =======");
  // console.log(Amwellservice);

  onButtonClick = e => {
    console.log("button clicked!!!");
    UIManager.dispatchViewManagerCommand(
      findNodeHandle(this.mySwiftComponentInstance),
      UIManager["AmwellView"].Commands.updateValueViaManager,
      []
    );
  };

  return (
    <View style={styles.container}>
      <View
        style={{ borderColor: Colors.black, borderWidth: 1, width: "100%" }}
      >
        <TouchableOpacity style={[styles.wrapper]} onPress={this.onButtonClick}>
          <Image
            style={styles.button}
            source={require("./images/video-call.jpeg")}
          />
        </TouchableOpacity>
        <RNAmwellView
          style={styles.border}
          ref={ref => (this.mySwiftComponentInstance = ref)}
        ></RNAmwellView>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
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
    justifyContent: "center"
  },

  border: {
    height: 150
  },

  button: {
    width: 100,
    height: 100,
    backgroundColor: "rgba(52, 52, 52, 0.8)"
  }
});
