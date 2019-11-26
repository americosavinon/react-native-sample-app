import { createStore, applyMiddleware } from 'redux';

// We'll use redux-logger just as an example of adding another middleware
import { createLogger } from 'redux-logger';

// And use redux-batch as an example of adding enhancers
import { persistStore, persistReducer } from 'redux-persist';

import rootReducer from '../reducers';
import { AsyncStorage } from 'react-native';
import { composeWithDevTools } from 'redux-devtools-extension';

const middleware = [];

if (process.env.NODE_ENV !== 'production') {
  middleware.push(createLogger());
}

// const preloadedState = {
//   todos: [],
//   visibilityFilter: 'SHOW_ALL'
// };

const persistConfig = {
  version: 1,
  key: 'root',
  storage: AsyncStorage,
};

const persistedReducer = persistReducer(persistConfig, rootReducer);

export const store = createStore(persistedReducer, undefined, composeWithDevTools(applyMiddleware(...middleware)));

export const persistor = persistStore(store);

/*
const store = configureStore({
    reducer: rootReducer,
    middleware,
    devTools: process.env.NODE_ENV !== 'production',
    preloadedState,
    enhancers: [reduxBatch]
})*/
