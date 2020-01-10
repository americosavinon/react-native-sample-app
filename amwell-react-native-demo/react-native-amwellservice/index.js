import React from "react";
import PropTypes from "prop-types";
import { NativeModules, requireNativeComponent } from "react-native";

const { Amwellservice } = NativeModules;
const RNAmwellView = requireNativeComponent("AmwellView");

// We are exporting services for non UI features and a custom View for UI Native component
export { Amwellservice, RNAmwellView };

export class AmwellVirtualVisitView extends React.PureComponent {
  _onUpdate = event => {
    if (!this.props.onUpdate) {
      return;
    }

    // process raw event...
    this.props.onUpdate(event.nativeEvent);
  };

  render() {
    return <RNAmwellView {...this.props} onUpdate={this._onUpdate} />;
  }
}

AmwellVirtualVisitView.propTypes = {
  /**
   *  Callback that is called when the current player item ends.
   */
  onUpdate: PropTypes.func
};
