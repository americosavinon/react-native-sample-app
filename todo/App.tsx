import React from 'react';
import { AppLoading } from 'expo';
import * as Font from 'expo-font';
import { Header } from 'react-native-elements';
import { StyleSheet, Text, View } from 'react-native';
import { Icon, SearchBar, TabBar } from '@ant-design/react-native';
import Todolist from './components/MyTodos/todolist'
import * as Constants from './constants'

export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      selectedTab: 'redTab',
      theme: null,
      currentTheme: null,
      isReady: false
    };
  }

  changeTheme = (theme, currentTheme) => {
    this.setState({ theme, currentTheme });
  };

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

  renderContent(tabName) {

    switch (tabName) {
      case Constants.TAB_DASHBOARD:
        return (<View style={{ flex: 1, backgroundColor: 'white' }}>
          <Header
            leftComponent={{ icon: 'menu', color: '#fff' }}
            centerComponent={{ text: 'MY Todos', style: { color: '#fff' } }}
            rightComponent={{ icon: 'home', color: '#fff' }}
          />
          <Text>Dashboard ...</Text>
        </View>);
      case Constants.TAB_TODOS:
        return (<View style={{ flex: 1, backgroundColor: 'white' }}>
          <Header
            leftComponent={{ icon: 'menu', color: '#fff' }}
            centerComponent={{ text: 'MY Todos', style: { color: '#fff' } }}
            rightComponent={{ icon: 'home', color: '#fff' }}
          />
          <Todolist></Todolist>
        </View>);
      default:
        return (<View style={{ flex: 1, backgroundColor: 'white' }}>
          <Header
            leftComponent={{ icon: 'menu', color: '#fff' }}
            centerComponent={{ text: 'MY Profile', style: { color: '#fff' } }}
            rightComponent={{ icon: 'home', color: '#fff' }}
          />
        </View>);
    }
  }

  onChangeTab(tabName) {
    this.setState({
      selectedTab: tabName,
    });
  }

  render() {
    const { theme, currentTheme, isReady } = this.state;
    if (!isReady) {
      return <AppLoading />;
    }

    return (
      <TabBar
        unselectedTintColor="#949494"
        tintColor="#33A3F4"
        barTintColor="#f5f5f5"
      >
        <TabBar.Item
          title="Dashboard"
          icon={<Icon name="home" />}
          selected={this.state.selectedTab === 'Dashboard'}
          onPress={() => this.onChangeTab('Dashboard')}
        >
          {this.renderContent('Dashboard')}
        </TabBar.Item>
        <TabBar.Item
          icon={<Icon name="ordered-list" />}
          title="Todos"
          badge={2}
          selected={this.state.selectedTab === 'Todos'}
          onPress={() => this.onChangeTab('Todos')}
        >
          {this.renderContent('Todos')}
        </TabBar.Item>
        <TabBar.Item
          icon={<Icon name="like" />}
          title="Friend"
          selected={this.state.selectedTab === 'Friends'}
          onPress={() => this.onChangeTab('Friends')}
        >
          {this.renderContent('Friends')}
        </TabBar.Item>
        <TabBar.Item
          icon={<Icon name="user" />}
          title="My"
          selected={this.state.selectedTab === 'MyProfile'}
          onPress={() => this.onChangeTab('MyProfile')}
        >
          {this.renderContent('MyProfile')}
        </TabBar.Item>
      </TabBar>
    );
  }
}
