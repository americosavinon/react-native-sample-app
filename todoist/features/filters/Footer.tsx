import React from 'react'
import FilterLink from './FilterLink'
import { VisibilityFilters } from './filtersSlice'
import { View, Text } from 'react-native';

const Footer = () => (
    <View style={{ flex: 1, justifyContent: "space-around", flexDirection: "row", position: 'absolute', width: '85%', bottom: 0, borderTopWidth: 1 }}>
        <FilterLink filter={VisibilityFilters.SHOW_ALL}>All</FilterLink>
        <FilterLink filter={VisibilityFilters.SHOW_ACTIVE}>Active</FilterLink>
        <FilterLink filter={VisibilityFilters.SHOW_COMPLETED}>Completed</FilterLink>
    </View>
)

export default Footer