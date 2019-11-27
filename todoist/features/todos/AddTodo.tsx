import React, { useState } from 'react';
import { connect } from 'react-redux';
import { addTodo } from './todosSlice';
import { VisibilityFilters, setVisibilityFilter } from '../filters/filtersSlice';
import { ToggleFilter } from '../toggles/toggleSlice';
import { View, StyleSheet } from 'react-native';
import { TextInput, Button } from 'react-native-paper';

const AddTodo = props => {
  const [todoText, setTodoText] = useState('');

  const onChange = e => {
    setTodoText(e);
  };

  if (props.toggleState === ToggleFilter.HIDE) {
    return null;
  }

  return (
    <View style={styles.container}>
      <TextInput label="What you want to do?" value={todoText} onChangeText={onChange} style={styles.taskInput} />
      <Button
        mode="contained"
        icon="plus-box"
        uppercase={false}
        style={styles.saveButton}
        onPress={() => {
          if (!todoText.trim()) {
            return;
          }
          props.addTodo(todoText);
          setTodoText('');
          // switch to all tasks
          props.setVisibilityFilter(VisibilityFilters.SHOW_ALL);
        }}
      >
        Add Todo
      </Button>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    top: 8,
    paddingLeft: 5,
    paddingRight: 5,
    flexDirection: 'row',
    justifyContent: 'space-around',
    flexWrap: 'wrap',
    height: 'auto',
    borderRadius: 10,
  },
  taskInput: {
    width: '100 %',
  },
  saveButton: {
    width: 180,
    marginTop: 10,
    marginLeft: 'auto',
    marginRight: 10,
  },
});

const mapStateToProps = function(state) {
  return {
    toggleState: state.toggleFilter,
  };
};

const mapDispatchToProps = { addTodo, setVisibilityFilter };

export default connect(mapStateToProps, mapDispatchToProps)(AddTodo);
