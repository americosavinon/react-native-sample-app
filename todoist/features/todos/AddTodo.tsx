import React, { useState } from 'react'
import { connect } from 'react-redux'
import { addTodo } from './todosSlice'
import { View } from 'react-native'
import { FAB, Portal, TextInput, Button } from 'react-native-paper'

const mapDispatch = { addTodo }

const AddTodo = ({ addTodo }) => {
    const [todoText, setTodoText] = useState('')

    const onChange = e => {
        // console.log(e)
        setTodoText(e)
    }

    return (
        <View style={{
            top: 8,
            paddingLeft: 2,
            paddingRight: 2,
            flexDirection: "row",
            justifyContent: "space-around",
            flexWrap: "wrap",
            height: 'auto'
        }}>
            <TextInput
                label='What you want to do?'
                value={todoText}
                onChangeText={onChange}
                style={{ width: '100%' }}
            />
            <Button mode="contained" icon="plus-box" uppercase={false} style={{ width: 180, marginTop: 10, marginLeft: 'auto', marginRight: 10 }} onPress={() => {
                if (!todoText.trim()) {
                    return
                }
                addTodo(todoText)
                setTodoText('')
            }}>Add Todo</Button>
        </View>
    )
}

export default connect(
    null,
    mapDispatch
)(AddTodo)