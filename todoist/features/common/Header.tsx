import * as React from 'react';
import PropTypes from 'prop-types';
import { Appbar } from 'react-native-paper';
import { connect } from 'react-redux';
import { ToggleFilter, setToggleFilter } from '../toggles/toggleSlice';

class HeaderNav extends React.Component {
  _toggleProfile = () => {
    this.props.toggleFunc();
  };

  _handleMore = () => {
    if (this.props.toggleState === ToggleFilter.SHOW) {
      this.props.setToggleFilter(ToggleFilter.HIDE);
    } else {
      this.props.setToggleFilter(ToggleFilter.SHOW);
    }
  };

  render() {
    return (
      <Appbar.Header>
        <Appbar.Action icon="home" onPress={this._toggleProfile} />
        <Appbar.Content title="My Todos" subtitle="Simple Demo" />
        <Appbar.Action
          icon={this.props.toggleState === ToggleFilter.SHOW ? 'minus' : 'plus'}
          onPress={this._handleMore}
        />
      </Appbar.Header>
    );
  }
}

HeaderNav.protoTypes = {
  toggleFunc: PropTypes.func,
};

const mapStateToProps = function(state) {
  return {
    toggleState: state.toggleFilter,
  };
};

const mapDispatchToProps = { setToggleFilter };

export default connect(mapStateToProps, mapDispatchToProps)(HeaderNav);
