import React from 'react'
import PropTypes from 'prop-types'
import { View } from 'react-native';
import { Button } from 'react-native-paper';

const Link = ({ active, children, setVisibilityFilter, filter }) => (
    <View style={{ height: 40, borderWidth: 0, marginRight: 10, marginLeft: 10 }}>
        <Button onPress={() => setVisibilityFilter(filter)}
            disabled={active}
            mode="text"

            labelStyle={{ textDecorationLine: active ? 'none' : 'underline', color: active ? 'purple' : 'gray' }}
        >
            {children}
        </Button>
    </View>
)

Link.propTypes = {
    active: PropTypes.bool.isRequired,
    children: PropTypes.node.isRequired,
    setVisibilityFilter: PropTypes.func.isRequired,
    filter: PropTypes.string.isRequired
}

export default Link