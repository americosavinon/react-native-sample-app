import React from 'react';
import PropTypes from 'prop-types';
import { List, Colors, IconButton } from 'react-native-paper';
import { StyleSheet } from 'react-native';

const Todo = ({ onClick, onDel, completed, text, id }) => {
  const renderLeft = () => (
    <List.Icon style={styles.checkboxButton} icon={completed ? 'check-circle' : 'panorama-fisheye'} />
  );

  const renderRight = () => (
    <IconButton
      icon="delete"
      style={styles.deleteButton}
      color={Colors.black}
      size={20}
      onPress={() => {
        onDel(id);
      }}
    />
  );

  return (
    <List.Item
      title={text}
      rippleColor={Colors.purple100}
      style={styles.todoItemContainer}
      titleStyle={completed ? styles.completeItem : styles.noncompleteItem}
      onPress={() => {
        onClick();
      }}
      left={renderLeft}
      right={renderRight}
    />
  );
};

Todo.propTypes = {
  onClick: PropTypes.func.isRequired,
  onDel: PropTypes.func.isRequired,
  completed: PropTypes.bool.isRequired,
  text: PropTypes.string.isRequired,
  id: PropTypes.string.isRequired,
};

const styles = StyleSheet.create({
  completeItem: {
    textDecorationLine: 'line-through',
    borderWidth: 0,
    width: '100%',
    marginTop: 5,
  },
  noncompleteItem: {
    textDecorationLine: 'none',
    borderWidth: 0,
    width: '100%',
    marginTop: 5,
  },
  checkboxButton: {
    width: 30,
    height: 25,
    borderWidth: 0,
    marginTop: 15,
  },
  deleteButton: {
    borderWidth: 0,
    marginTop: 12,
    width: 32,
  },
  todoItemContainer: {
    borderRadius: 10,
    height: 45,
    justifyContent: 'space-around',
    borderWidth: 1,
    borderColor: 'white',
    backgroundColor: 'white',
    shadowColor: 'white',
    shadowOffset: {
      width: 0,
      height: 10,
    },
    shadowOpacity: 0.25,
    shadowRadius: 3.84,
    elevation: 5,
    marginBottom: 6,
    marginLeft: 5,
    marginRight: 5,
    paddingTop: 0,
  },
});

export default Todo;
