import React from "react";
import PropTypes from "prop-types";
import {
  NativeModules,
  requireNativeComponent,
  UIManager,
  findNodeHandle
} from "react-native";

const { Amwellservice } = NativeModules;

// We wrap the View component with native functions, so the main project dont' need to deal with platform specific logic
// All service logic should be wrapped as cross platform here
class AmwellVirtualVisitView extends React.Component {
  constructor(props) {
    super(props);
    this._onChange = this._onChange.bind(this);
    this.state = {
      isOn: false
    };
  }

  _onChange(event: Event) {
    if (!this.props.onChangeMessage) {
      return;
    }

    this.setState({
      isOn: event.nativeEvent.isOn
    });

    // This is to pass the overwrite event function from React Native project.
    this.props.onChangeMessage(event.nativeEvent);
  }

  // This is the demo function to launch a video call
  testVideoCall() {
    UIManager.dispatchViewManagerCommand(
      findNodeHandle(this),
      UIManager["AmwellView"].Commands.testVideoCall,
      []
    );
  }

  render() {
    return (
      <RCTAmwellView
        {...this.props}
        isOn={this.state.isOn}
        onUpdate={this._onChange}
      />
    );
  }
}

AmwellVirtualVisitView.propTypes = {
  /**
   *  Callback that is called when the current player item ends.
   */
  onChangeMessage: PropTypes.func,
  testVideoCall: PropTypes.func
};

var RCTAmwellView = requireNativeComponent(
  "AmwellView",
  AmwellVirtualVisitView
);
module.exports = {
  AmwellVirtualVisitView,
  Amwellservice
};
