import React, { Component } from "react";
import { StyleSheet } from "react-native";
import { WebView } from "react-native-webview";
import {
  SafeAreaLayout,
  SafeAreaLayoutElement,
  SaveAreaInset
} from "../../components/safe-area-layout.component";

import { Divider, Layout, Text } from "@ui-kitten/components";
import { Toolbar } from "../../components/toolbar.component";

export const AmwellInlineWebScreen = (props): SafeAreaLayoutElement => {
  return (
    <SafeAreaLayout style={styles.safeArea} insets={SaveAreaInset.TOP}>
      <Toolbar
        title="Amwell SDK Virtual Visit WebView Demo"
        onBackPress={props.navigation.goBack}
      />
      <Divider />
      <WebView
        source={{ uri: "https://infinite.red" }}
        style={{ marginTop: 20 }}
      />
    </SafeAreaLayout>
  );
};

const styles = StyleSheet.create({
  safeArea: {
    flex: 1
  }
});
