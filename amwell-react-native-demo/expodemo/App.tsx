import React from "react";
import {
  StyleSheet,
  Text,
  Image,
  View,
  TouchableOpacity,
  UIManager,
  Button,
  findNodeHandle,
  Platform,
  ToastAndroid
} from "react-native";
import { Appbar } from "react-native-paper";

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
  console.log(" ======== Testing Launched! =======");
  // console.log(Amwellservice);

  onButtonClick = e => {
    console.log("button clicked!!!");
    UIManager.dispatchViewManagerCommand(
      findNodeHandle(this.mySwiftComponentInstance),
      UIManager["AmwellView"].Commands.updateValueViaManager,
      []
    );
  };

  _goBack = () => console.log("Went back");
  _handleSearch = () => console.log("Searching");
  _handleMore = () => console.log("Shown more");

  return (
    <View style={styles.container}>
      <Appbar.Header>
        <Appbar.BackAction onPress={this._goBack} />
        <Appbar.Content
          title="Virtual Visit - Amwell SDK"
          subtitle="Demo App with Native UI Module"
        />
        <Appbar.Action icon="magnify" onPress={this._handleSearch} />
        <Appbar.Action icon="dots-vertical" onPress={this._handleMore} />
      </Appbar.Header>
      <View style={styles.contentContainer}>
        <Text>Press to start test video call!</Text>
        <TouchableOpacity onPress={this.onButtonClick}>
          <Image
            style={styles.button}
            source={require("./images/video-call.jpeg")}
          />
        </TouchableOpacity>
        <RNAmwellView
          style={styles.nativeViewStyle}
          ref={ref => (this.mySwiftComponentInstance = ref)}
        ></RNAmwellView>
        <Text>Note: Make sure Provider [Test Four] is online!</Text>
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
    backgroundColor: "#fff"
  },

  contentContainer: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
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
