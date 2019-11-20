import React from 'react'
import PropTypes from 'prop-types'
import { List, Colors, Button, IconButton } from 'react-native-paper';
import { View } from 'react-native'

const Todo = ({ onClick, onDel, completed, text, id }) => (
    <View style={{ flexDirection: 'row', justifyContent: "space-around", }}>
        <List.Icon color={Colors.blue500} icon={completed ? 'check' : 'bookmark'} style={{ borderWidth: 0, width: 20, height: 20 }} />
        <List.Item title={text}
            style={{ padding: 1, borderWidth: 0, width: '70%' }}
            titleStyle={{ textDecorationLine: completed ? 'line-through' : 'none', borderWidth: 0 }}
            onPress={onClick}
        >
        </List.Item>
        <IconButton
            icon="delete"
            color={Colors.black}
            size={20}
            onPress={() => {
                onDel(id)
            }
            }
        />
    </View>
)

Todo.propTypes = {
    onClick: PropTypes.func.isRequired,
    onDel: PropTypes.func.isRequired,
    completed: PropTypes.bool.isRequired,
    text: PropTypes.string.isRequired,
    id: PropTypes.number.isRequired,
}

export default Todo