import React from "react";
import { StyleSheet, Text, View } from "react-native";
import Amwellservice from "react-native-amwellservice";

export default class App extends React.Component {
  async componentDidMount() {
    Amwellservice.initialize().then(
      function(value) {
        console.log(value); // "Success"
      },
      function(value) {
        console.log("failed!");
      }
    );
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
