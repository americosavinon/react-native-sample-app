# react-native-sample-app
Todo List app demo
 - We use this app for demo purpose, simple business logic but touch all the key concepts for jump starter

# How we setup todoist with expo

```
expo init todoist # (choose managed with blank typescript support)
yarn add react-native-paper
yarn add react-native-vector-icons
react-native link react-native-vector-icons
```

How to start the project in local mac.

```
cd todo/ios
pod install

cd todo
yarn ios
```

## react native ant-design part setup notes

```
yarn add @ant-design/react-native
react-native link @ant-design/icons-react-native
```