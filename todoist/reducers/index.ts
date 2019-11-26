import { combineReducers } from 'redux';
import todosReducer from '../features/todos/todosSlice';
import visibilityFilterReducer from '../features/filters/filtersSlice';
import toggleFilterReducer from '../features/toggles/toggleSlice';

export default combineReducers({
  todos: todosReducer,
  visibilityFilter: visibilityFilterReducer,
  toggleFilter: toggleFilterReducer
});
