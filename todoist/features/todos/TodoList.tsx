import React, { Component } from 'react';
import PropTypes from 'prop-types';
import Todo from './Todo';
import { List } from 'react-native-paper';
import { FlatList, StyleSheet, Text, ScrollView, View, ActivityIndicator } from 'react-native';

const TodoList = ({ todos, toggleTodo, removeTodo }) => (
  <ScrollView>
    <List.Section>
      <List.Subheader style={{ color: 'white' }}>My Todos:</List.Subheader>
      {todos.map(todo => (
        <Todo
          key={todo.id}
          {...todo}
          onClick={() => {
            toggleTodo(todo.id);
          }}
          onDel={() => {
            removeTodo(todo.id);
          }}
        />
      ))}
    </List.Section>
  </ScrollView>
);

TodoList.propTypes = {
  todos: PropTypes.arrayOf(
    PropTypes.shape({
      id: PropTypes.string.isRequired,
      completed: PropTypes.bool.isRequired,
      text: PropTypes.string.isRequired
    }).isRequired
  ).isRequired,
  toggleTodo: PropTypes.func.isRequired,
  removeTodo: PropTypes.func.isRequired
};

export default TodoList;
