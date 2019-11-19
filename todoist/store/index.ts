import { configureStore, getDefaultMiddleware } from '@reduxjs/toolkit'

// We'll use redux-logger just as an example of adding another middleware
import logger from 'redux-logger'

// And use redux-batch as an example of adding enhancers
import { reduxBatch } from '@manaflair/redux-batch'

import rootReducer from '../reducers'

const middleware = [...getDefaultMiddleware(), logger]

const preloadedState = {
    todos: [
        {
            id: 1,
            text: 'Eat food',
            completed: true
        },
        {
            id: 2,
            text: 'Exercise',
            completed: false
        },
        {
            id: 3,
            text: 'Exercise All',
            completed: false
        }
    ],
    visibilityFilter: 'SHOW_ALL'
}

const store = configureStore({
    reducer: rootReducer,
    middleware,
    devTools: process.env.NODE_ENV !== 'production',
    preloadedState,
    enhancers: [reduxBatch]
})

// The store has been created with these options:
// - The slice reducers were automatically passed to combineReducers()
// - redux-thunk and redux-logger were added as middleware
// - The Redux DevTools Extension is disabled for production
// - The middleware, batch, and devtools enhancers were automatically composed together

export default store