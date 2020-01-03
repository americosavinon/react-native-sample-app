import React from "react";
import {
  View,
  Text,
  Button,
} from "react-native";

import { createStackNavigator, TransitionPresets } from '@react-navigation/stack';
import { TopNavigationHeader } from "./TopNavigation";
import AmwellVideoCall from "./AmwellVideoCall";

function VideoScreen({ navigation }) {
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
        onPress={() => navigation.navigate("Video")}
        title="Go to Video"
      />
    </View>
  );
}

export default function Settings() {
  const Stack = createStackNavigator();
  return (
    <Stack.Navigator
      initialRouteName="Video"
      mode="modal"
      headerMode="float"
      screenOptions={{
        gestureEnabled: true,
        cardOverlayEnabled: true,
        headerStyle: {
          backgroundColor: '#f4511e',
        },
        headerTintColor: '#fff',
        headerTitleStyle: {
          fontWeight: 'bold',
        },
        ...TransitionPresets.ModalPresentationIOS,
      }}
      
    >
      <Stack.Screen name="Video" component={AmwellVideoCall}  
      options={{
        title: 'My home',
        headerStyle: {
          backgroundColor: '#f4511e',
        },
        headerTintColor: '#fff',
        headerTitleStyle: {
          fontWeight: 'bold',
        },
        header: props => <TopNavigationHeader {...props} /> 
      }}/>
      <Stack.Screen name="Profile" component={ProfileScreen} />
    </Stack.Navigator>)
}

