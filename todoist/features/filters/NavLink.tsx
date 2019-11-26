import React, { Component } from 'react';
import { connect } from 'react-redux';
import { FAB } from 'react-native-paper';
import { VisibilityFilters, setVisibilityFilter } from './filtersSlice';

class NavLink extends Component {
  constructor(props, context) {
    super(props, context);
    this.state = {
      open: false
    };
  }

  render() {
    return (
      <FAB.Group
        open={this.state.open}
        icon={this.state.open ? 'minus-box' : 'plus-box'}
        fabStyle={{ backgroundColor: 'black', marginBottom: 25 }}
        actions={[
          {
            icon: 'creation',
            label: 'Show All',
            onPress: () => this.props.setVisibilityFilter(VisibilityFilters.SHOW_ALL)
          },
          {
            icon: 'creation',
            label: 'Active',
            onPress: () => this.props.setVisibilityFilter(VisibilityFilters.SHOW_ACTIVE)
          },
          {
            icon: 'creation',
            label: 'Completed',
            onPress: () => this.props.setVisibilityFilter(VisibilityFilters.SHOW_COMPLETED)
          }
        ]}
        onStateChange={({ open }) => this.setState({ open })}
        onPress={() => {
          if (this.state.open) {
            // do something if the speed dial is open
          }
        }}
      />
    );
  }
}

const mapDispatchToProps = { setVisibilityFilter };

export default connect(null, mapDispatchToProps)(NavLink);
