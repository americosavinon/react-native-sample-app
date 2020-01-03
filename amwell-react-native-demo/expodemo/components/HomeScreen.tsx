import React from "react";
import {
  StyleSheet,
  Image,
  View,
  Text,
  Button,
} from "react-native";

export default function HomeScreen({ navigation }) {
    return (
        <View style={{ flex: 1, alignItems: 'center', justifyContent: "center"}}>
            <Text>Home Page Demo!</Text>
        <Button
            onPress={() => navigation.navigate("Settings")}
            title="Go to notifications"
        />
        </View>
    );
}

HomeScreen.navigationOptions = {
    header: (
        <Text>Hello</Text>
    ),
};