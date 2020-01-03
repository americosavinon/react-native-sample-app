import * as React from 'react';
import { Text, View } from 'react-native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';

import SettingsNavigator from "./SettingsNavigator";

function HomeScreen() {
  return (
    <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
      <Text>Home!</Text>
    </View>
  );
}

function SettingsScreen() {
  return (
    <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
      <Text>Settings!</Text>
    </View>
  );
}

const Tab = createBottomTabNavigator();

export default function TabNavigation() {
  return (
      <Tab.Navigator>
        <Tab.Screen name="Home" component={SettingsNavigator} />
        <Tab.Screen name="Settings" component={SettingsScreen} />
        <Tab.Screen name="Logs" component={SettingsScreen} />
      </Tab.Navigator>
  );
}