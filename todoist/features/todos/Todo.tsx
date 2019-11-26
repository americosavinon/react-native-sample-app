import React from 'react'
import PropTypes from 'prop-types'
import { List, Colors, Button, IconButton } from 'react-native-paper';
import { View, StyleSheet } from 'react-native'

const Todo = ({ onClick, onDel, completed, text, id }) => (
    <View style={styles.todoItemContainer}>
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
    id: PropTypes.string.isRequired,
}

const styles = StyleSheet.create({
    todoItemContainer: {
        flexDirection: 'row',
        borderRadius: 10,
        justifyContent: "space-around",
        borderWidth: 1,
        borderColor: 'white',
        backgroundColor: '#fff',
        shadowColor: "gray",
        shadowOffset: {
            width: 0,
            height: 2,
        },
        shadowOpacity: 0.25,
        shadowRadius: 3.84,
        elevation: 5,
        marginBottom: 6,
        marginLeft: 3,
        marginRight: 3,
        paddingTop: 5,
    },
});


export default Todo