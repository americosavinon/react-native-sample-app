import React, { useState } from 'react'
import { connect } from 'react-redux'
import { addTodo } from './todosSlice'
import { VisibilityFilters, setVisibilityFilter } from '../filters/filtersSlice'
import { View } from 'react-native'
import { TextInput, Button } from 'react-native-paper'

const AddTodo = (props) => {
    const [todoText, setTodoText] = useState('')

    const onChange = e => {
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
            <Button mode="contained" icon="plus-box" uppercase={false}
                style={{ width: 180, marginTop: 10, marginLeft: 'auto', marginRight: 10 }} onPress={() => {
                    if (!todoText.trim()) {
                        return
                    }
                    props.addTodo(todoText)
                    setTodoText('')
                    // switch to all tasks
                    props.setVisibilityFilter(VisibilityFilters.SHOW_ALL)
                }}>Add Todo</Button>
        </View>
    )
}

const mapDispatchToProps = { addTodo, setVisibilityFilter }

export default connect(
    null,
    mapDispatchToProps
)(AddTodo)