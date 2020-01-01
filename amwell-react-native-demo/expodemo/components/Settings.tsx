import React from "react";
import {
  StyleSheet,
  Image,
  View,
  Text,
  TouchableOpacity,
  UIManager,
  findNodeHandle,
  SafeAreaView,
  Button,
  Platform,
  ToastAndroid
} from "react-native";

import { createDrawerNavigator } from "@react-navigation/drawer";
import { createStackNavigator, TransitionPresets } from '@react-navigation/stack';
import { NavigationNativeContainer } from "@react-navigation/native";


function HomeScreen({ navigation }) {
    return (
      <View style={{ flex: 1 }}>
          <Text></Text>
        <Button onPress={() => navigation.navigate("Profile")} title="Go to Profile" />
      </View>
    );
  }
  
  function ProfileScreen({ navigation }) {
    return (
      <View style={{ flex: 1, flexDirection: "column-reverse" }}>
        <Button
            onPress={() => navigation.goback()}
            title="Go back home"
          />
      </View>
    );
  }

export default function Settings() {
    const Stack = createStackNavigator();
    return (
            <Stack.Navigator
                initialRouteName="Home"
                mode="modal"
                headerMode="float"
                screenOptions={{
                gestureEnabled: true,
                cardOverlayEnabled: true,
                ...TransitionPresets.ModalPresentationIOS,
                }}
            >
                <Stack.Screen name="Home" component={HomeScreen} />
                <Stack.Screen name="Profile" component={ProfileScreen} />
            </Stack.Navigator>)
}