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
  styles = StyleSheet.create({
    container: {
      flex: 1,
      backgroundColor: '#fff',
      alignItems: 'center',
      justifyContent: 'center'
    }
  });

  renderLoading = () => {
    <View style={this.styles.container}>
      <ActivityIndicator size="large" />
    </View>;
  };

  render() {
    return (
      <ImageBackground source={require('./assets/images/background2.jpg')} style={{ width: '100%', flex: 1 }}>
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
      </ImageBackground>
    );
  }
}

export default App;
