import * as React from 'react';
import PropTypes from 'prop-types';
import { Appbar } from 'react-native-paper';
import { connect } from 'react-redux';
import { setToggleFilter } from '../toggles/toggleSlice';

class HeaderNav extends React.Component {
  _toggleProfile = () => {
    this.props.toggleProfileFunc();
  };

  _handleMore = () => {
    // if (this.props.toggleState === ToggleFilter.SHOW) {
    //   this.props.setToggleFilter(ToggleFilter.HIDE);
    // } else {
    //   this.props.setToggleFilter(ToggleFilter.SHOW);
    // }
  };

  render() {
    return (
      <Appbar.Header>
        <Appbar.Action icon="home" onPress={this._toggleProfile} />
        <Appbar.Content title="My Todos" subtitle="Simple Demo" />
        <Appbar.Action icon="menu" onPress={this._handleMore} />
      </Appbar.Header>
    );
  }
}

HeaderNav.protoTypes = {
  toggleProfileFunc: PropTypes.func,
};

const mapStateToProps = function(state) {
  return {
    toggleState: state.toggleFilter,
  };
};

const mapDispatchToProps = { setToggleFilter };

export default connect(mapStateToProps, mapDispatchToProps)(HeaderNav);
