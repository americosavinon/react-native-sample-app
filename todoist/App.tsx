import React from 'react';
import { AppLoading } from 'expo';
import * as Font from 'expo-font';
import { StyleSheet, View } from 'react-native';
import { Provider as PaperProvider, Text, Button, ActivityIndicator } from 'react-native-paper';
import { Provider as StoreProvider } from 'react-redux';
import HeaderNav from './components/Header';
import { store, persistor } from './store'
import VisibleTodoList from './features/todos/VisibleTodoList';
import Footer from './features/filters/Footer';
import AddTodo from './features/todos/AddTodo';
import NavLink from './features/filters/NavLink';
import { PersistGate } from 'redux-persist/integration/react'

export default class App extends React.Component {

  async componentDidMount() {
    await Font.loadAsync(
      'antoutline',
      // eslint-disable-next-line
      require('@ant-design/icons-react-native/fonts/antoutline.ttf')
    );

    await Font.loadAsync(
      'antfill',
      // eslint-disable-next-line
      require('@ant-design/icons-react-native/fonts/antfill.ttf')
    );
    // eslint-disable-next-line
    this.setState({ isReady: true });
  }

  renderLoading = () => {
    <View style={styles.container}>
      <ActivityIndicator size="large" />
    </View>
  }

  render() {
    return (
      <StoreProvider store={store}>
        <PersistGate loading={this.renderLoading()} persistor={persistor}>
          <PaperProvider>
            <HeaderNav></HeaderNav>
            <AddTodo></AddTodo>
            <VisibleTodoList />
            <Footer></Footer>
            {/* <NavLink></NavLink> */}
          </PaperProvider>
        </PersistGate>
      </StoreProvider>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
