import React from "react";
import { StyleSheet, Text, View } from "react-native";
import { NativeModules } from "react-native";

export default class App extends React.Component {
  async componentDidMount() {
    // NativeModules.AmwellService.initialize(null, () => console.warn("oh noes"));
    let demo = NativeModules.AmwellService.test();
    demo.then(
      function(value) {
        console.log(value); // "Success"
      },
      function(value) {
        console.log("failed!");
      }
    );
    /*
    let myModule = NativeModules.ExamplePromise;
    console.log("hello!");
    let data = myModule.getMyPromise();

    data.then(
      function(value) {
        console.log(value); // "Success"
      },
      function(value) {
        console.log("failed!");
      }
    );*/
    // console.log(data); // Here is our promise
  }

  render() {
    return (
      <View style={styles.container}>
        <Text>Open up App.tsx to start working on your app!</Text>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center"
  }
});
