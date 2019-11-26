import React from 'react';
import FilterLink from './FilterLink';
import { VisibilityFilters } from './filtersSlice';
import { View, StyleSheet } from 'react-native';

const styles = StyleSheet.create({
  footerContainer: {
    flex: 1,
    justifyContent: 'space-around',
    flexDirection: 'row',
    position: 'absolute',
    width: '100%',
    bottom: 0,
    borderTopWidth: 2,
    borderColor: 'gray',
    backgroundColor: 'white',
    paddingBottom: 10,
  },
});

const Footer = () => (
  <View style={styles.footerContainer}>
    <FilterLink filter={VisibilityFilters.SHOW_ALL}>All Tasks</FilterLink>
    <FilterLink filter={VisibilityFilters.SHOW_ACTIVE}>Active</FilterLink>
    <FilterLink filter={VisibilityFilters.SHOW_COMPLETED}>Completed</FilterLink>
  </View>
);

export default Footer;
