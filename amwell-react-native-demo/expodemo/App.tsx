import React from "react";
import {
  StyleSheet,
  Image,
  View,
  TouchableOpacity,
  UIManager,
  findNodeHandle,
  SafeAreaView,
  Button,
  Platform,
  ToastAndroid
} from "react-native";

import {
  ApplicationProvider,
  IconRegistry,
  Divider,
  Layout,
  TopNavigation,
  Text,
  Icon
} from "@ui-kitten/components";
import { EvaIconsPack } from "@ui-kitten/eva-icons";
import { mapping, light as lightTheme } from "@eva-design/eva";

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

import { TopNavigationActionsShowcase } from "./components/TopNavigation";
import AmwellVideoCall from "./components/AmwellVideoCall";

import { createDrawerNavigator } from "@react-navigation/drawer";
import { NavigationNativeContainer } from "@react-navigation/native";

function HomeScreen({ navigation }) {
  return (
    <View style={{ flex: 1, flexDirection: "column-reverse" }}>
      <Button
        onPress={() => navigation.navigate("Notifications")}
        title="Go to notifications"
      />
    </View>
  );
}

function NotificationsScreen({ navigation }) {
  return (
    <View style={{ flex: 1, flexDirection: "column-reverse" }}>
      <Button onPress={() => navigation.goBack()} title="Go back home" />
    </View>
  );
}

const Drawer = createDrawerNavigator();

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

  return (
    <React.Fragment>
      <IconRegistry icons={EvaIconsPack} />
      <ApplicationProvider mapping={mapping} theme={lightTheme}>
        <SafeAreaView style={{ flex: 1 }}>
          <TopNavigationActionsShowcase
            navigation={Drawer}
          ></TopNavigationActionsShowcase>

          <Divider />
          <NavigationNativeContainer>
            <Drawer.Navigator initialRouteName="VideoCall">
              <Drawer.Screen name="Home" component={HomeScreen} />
              <Drawer.Screen
                name="Notifications"
                component={NotificationsScreen}
              />
              <Drawer.Screen name="VideoCall" component={AmwellVideoCall} />
            </Drawer.Navigator>
          </NavigationNativeContainer>
        </SafeAreaView>
      </ApplicationProvider>
    </React.Fragment>
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
