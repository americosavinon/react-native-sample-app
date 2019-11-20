import { createSlice } from '@reduxjs/toolkit'

// we have 3 item as initialized
let nextTodoId = 4

const todosSlice = createSlice({
    name: 'todos',
    initialState: [],
    reducers: {
        addTodo: {
            reducer(state, action) {
                const { id, text } = action.payload
                state.push({ id, text, completed: false })
            },
            prepare(text) {
                return { payload: { text, id: nextTodoId++ } }
            }
        },
        toggleTodo(state, action) {
            const todo = state.find(todo => todo.id === action.payload)
            if (todo) {
                todo.completed = !todo.completed
            }
        },
        removeTodo(state, action) {
            return state.filter(todo => todo.id !== action.payload)
        }
    }
})

export const { addTodo, toggleTodo, removeTodo } = todosSlice.actions

export default todosSlice.reducer