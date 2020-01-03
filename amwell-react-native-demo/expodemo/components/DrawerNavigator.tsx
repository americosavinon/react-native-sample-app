import * as React from 'react';
import { Text, View } from 'react-native';
import { createBottomTabNavigator } from '@react-navigation/bottom-tabs';
import { createDrawerNavigator } from "@react-navigation/drawer";

function HomeScreen() {
    return (
        <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
            <Text>Home! in drawer</Text>
        </View>
    );
}

function SettingsScreen() {
    return (
        <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
            <Text>Settings! in drawer</Text>
        </View>
    );
}

export default function DrawerNavigation() {
    const Drawer = createDrawerNavigator();
    return (
        <Drawer.Navigator initialRouteName="Home1">
            <Drawer.Screen name="Home1" component={SettingsScreen} />
            <Drawer.Screen name="VideoCall" component={HomeScreen} />
        </Drawer.Navigator>
    );
}