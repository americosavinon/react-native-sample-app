import React, { Component } from 'react'
import PropTypes from 'prop-types'
import Todo from './Todo'
import { List } from 'react-native-paper';

const TodoList = ({ todos, toggleTodo, removeTodo }) => (
    <List.Section>
        <List.Subheader>My Todos:</List.Subheader>
        {todos.map(todo => (
            <Todo key={todo.id} {...todo} onClick={() => {
                toggleTodo(todo.id)
            }
            } onDel={() => {
                removeTodo(todo.id)
            }
            } />
        ))}
    </List.Section>
)

TodoList.propTypes = {
    todos: PropTypes.arrayOf(
        PropTypes.shape({
            id: PropTypes.number.isRequired,
            completed: PropTypes.bool.isRequired,
            text: PropTypes.string.isRequired
        }).isRequired
    ).isRequired,
    toggleTodo: PropTypes.func.isRequired,
    removeTodo: PropTypes.func.isRequired
}

export default TodoList