import React from "react";
import PropTypes from "prop-types";
import { NativeModules, requireNativeComponent } from "react-native";

const { Amwellservice } = NativeModules;

const RCTAmwellView = requireNativeComponent(
  "AmwellView",
  AmwellVirtualVisitView
);

// We are exporting services for non UI features and a custom View for UI Native component
export { Amwellservice };

export class AmwellVirtualVisitView extends React.Component {
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

    this.props.onChangeMessage(event.nativeEvent);
  }

  render() {
    return (
      <RCTAmwellView
        {...this.props}
        isOn={this.state.isOn}
        onStatusChange={this._onChange}
      />
    );
  }
}

AmwellVirtualVisitView.propTypes = {
  /**
   *  Callback that is called when the current player item ends.
   */
  onChangeMessage: PropTypes.func
};
