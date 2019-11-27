import React from 'react';
import { StyleSheet } from 'react-native';
import { connect } from 'react-redux';
import { FAB } from 'react-native-paper';
import { ToggleFilter, setToggleFilter } from '../toggles/toggleSlice';

const AddTodoFab = props => (
  <FAB style={styles.fab} small icon="plus" onPress={() => props.setToggleFilter(ToggleFilter.SHOW)} />
);

const styles = StyleSheet.create({
  fab: {
    position: 'absolute',
    margin: 16,
    right: 0,
    bottom: 60,
    backgroundColor: 'black',
  },
});

const mapStateToProps = function(state) {
  return {
    toggleState: state.toggleFilter,
  };
};

const mapDispatchToProps = { setToggleFilter };

export default connect(mapStateToProps, mapDispatchToProps)(AddTodoFab);
