import * as React from 'react';
import { BottomNavigation, Text } from 'react-native-paper';
import Todolist from './todos/todolist';

const MusicRoute = () => <Todolist></Todolist>;

const AlbumsRoute = () => <Text>Albums</Text>;

const RecentsRoute = () => <Text>Recents</Text>;

export default class NavBar extends React.Component {
    state = {
        index: 0,
        routes: [
            { key: 'music', title: 'New Tasks', icon: 'wordpress' },
            { key: 'albums', title: 'Completed', icon: 'xbox' },
            { key: 'recents', title: 'MyProfile', icon: 'webcam' },
        ],
    };

    _handleIndexChange = index => this.setState({ index });

    _renderScene = BottomNavigation.SceneMap({
        music: MusicRoute,
        albums: AlbumsRoute,
        recents: RecentsRoute,
    });

    render() {
        return (
            <BottomNavigation
                navigationState={this.state}
                onIndexChange={this._handleIndexChange}
                renderScene={this._renderScene}
            />
        );
    }
}