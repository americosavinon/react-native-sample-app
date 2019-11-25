import { configureStore, getDefaultMiddleware } from '@reduxjs/toolkit'
import { createStore, applyMiddleware } from 'redux'

// We'll use redux-logger just as an example of adding another middleware
import { createLogger } from 'redux-logger'

// And use redux-batch as an example of adding enhancers
import { reduxBatch } from '@manaflair/redux-batch'
import { persistStore, persistReducer } from 'redux-persist'

import rootReducer from '../reducers'
import { AsyncStorage } from 'react-native'
import { composeWithDevTools } from 'redux-devtools-extension'

const middleware = []

if (__DEV__) {
    middleware.push(createLogger())
}

const preloadedState = {
    todos: [
    ],
    visibilityFilter: 'SHOW_ALL'
}

const persistConfig = {
    key: 'root',
    storage: AsyncStorage
};

const persistedReducer = persistReducer(persistConfig, rootReducer)

export const store = createStore(persistedReducer,
    undefined,
    composeWithDevTools(applyMiddleware(...middleware))
)

export const persistor = persistStore(store)

/*
const store = configureStore({
    reducer: rootReducer,
    middleware,
    devTools: process.env.NODE_ENV !== 'production',
    preloadedState,
    enhancers: [reduxBatch]
})*/

// The store has been created with these options:
// - The slice reducers were automatically passed to combineReducers()
// - redux-thunk and redux-logger were added as middleware
// - The Redux DevTools Extension is disabled for production
// - The middleware, batch, and devtools enhancers were automatically composed together
// export default store