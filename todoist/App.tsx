import React from 'react';
import { StyleSheet, View, ImageBackground } from 'react-native';
import { Provider as PaperProvider, ActivityIndicator } from 'react-native-paper';
import { Provider as StoreProvider } from 'react-redux';
import HeaderNav from './features/common/Header';
import { store, persistor } from './store';
import VisibleTodoList from './features/todos/VisibleTodoList';
import Footer from './features/filters/Footer';
import AddTodo from './features/todos/AddTodo';
import { PersistGate } from 'redux-persist/integration/react';

class App extends React.Component {
  renderLoading = () => {
    <View style={styles.container}>
      <ActivityIndicator size="large" />
    </View>;
  };

  render() {
    return (
      <ImageBackground source={require('./assets/images/background4.jpg')} style={styles.imageContainer}>
        <StoreProvider store={store}>
          <PersistGate loading={this.renderLoading()} persistor={persistor}>
            <PaperProvider>
              <HeaderNav />
              <AddTodo />
              <VisibleTodoList />
              <Footer />
              {/* <NavLink></NavLink> */}
            </PaperProvider>
          </PersistGate>
        </StoreProvider>
      </ImageBackground>
    );
  }
}

const styles = StyleSheet.create({
  imageContainer: {
    width: '100%',
    flex: 1,
  },
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});

export default App;
