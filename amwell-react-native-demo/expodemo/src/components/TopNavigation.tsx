/**
 * IMPORTANT: To use Icon component make sure to follow this guide:
 * https://akveo.github.io/react-native-ui-kitten/docs/guides/icon-packages
 */

import React from "react";
import {
  Icon,
  TopNavigation,
  TopNavigationAction
} from "@ui-kitten/components";
import PropTypes from "prop-types";
import { useNavigation } from '@react-navigation/native';
import { DrawerActions } from '@react-navigation/routers';

const BackIcon = style => <Icon {...style} name="menu-outline" />;
const EditIcon = style => <Icon {...style} name="search-outline" />;
const MenuIcon = style => <Icon {...style} name="log-out-outline" />;

const BackAction = props => <TopNavigationAction {...props} icon={BackIcon} />;
const EditAction = props => <TopNavigationAction {...props} icon={EditIcon} />;
const MenuAction = props => <TopNavigationAction {...props} icon={MenuIcon} />;

export class TopNavigationHeader extends React.Component {
  onBackPress = () => {
    // const navigation = useNavigation();
    // this.props.toggleDrawerFunc();
    // navigation.dispatch(DrawerActions.toggleDrawer());
  };

  renderLeftControl = () => <BackAction onPress={this.onBackPress} />;
  renderRightControls = () => [<EditAction />, <MenuAction />];

  render() {
    return (
      <TopNavigation
        title="AmwellSDK DemoApp"
        leftControl={this.renderLeftControl()}
        rightControls={this.renderRightControls()}
      />
    );
  }
}

TopNavigationHeader.protoTypes = {
  toggleDrawerFunc: PropTypes.func
};
