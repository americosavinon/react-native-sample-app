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

const BackIcon = style => <Icon {...style} name="list-outline" />;

const EditIcon = style => <Icon {...style} name="cast-outline" />;

const MenuIcon = style => <Icon {...style} name="log-out-outline" />;

const BackAction = props => <TopNavigationAction {...props} icon={BackIcon} />;

const EditAction = props => <TopNavigationAction {...props} icon={EditIcon} />;

const MenuAction = props => <TopNavigationAction {...props} icon={MenuIcon} />;

export const TopNavigationActionsShowcase = () => {
  const onBackPress = () => {
    console.log(this);
  };

  const renderLeftControl = () => <BackAction onPress={onBackPress} />;

  const renderRightControls = () => [<EditAction />, <MenuAction />];

  return (
    <TopNavigation
      title="AmwellSDK DemoApp"
      leftControl={renderLeftControl()}
      rightControls={renderRightControls()}
    />
  );
};
