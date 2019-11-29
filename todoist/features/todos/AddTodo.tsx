import React from 'react';
import { StyleSheet, Text, View, KeyboardAvoidingView } from 'react-native';
import BottomSheet from 'reanimated-bottom-sheet';
import { TextInput, Button } from 'react-native-paper';
import { connect } from 'react-redux';
import { addTodo } from './todosSlice';
import { ToggleFilter, setToggleFilter } from '../toggles/toggleSlice';
import { VisibilityFilters, setVisibilityFilter } from '../filters/filtersSlice';

class AddTodoModal extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      todoText: '',
    };

    // initialize the toggle Filter as hide
    props.setToggleFilter(ToggleFilter.HIDE);
  }

  componentDidUpdate(prevProps, prevState, snapshot) {
    if (prevProps.toggleState !== this.props.toggleState) {
      if (this.props.toggleState === ToggleFilter.HIDE) {
        this.bs.current.snapTo(0);
      } else {
        this.bs.current.snapTo(1);
      }
    }
  }

  onChange = e => {
    this.setState({ todoText: e });
  };

  renderInner = () => {
    return (
      <View style={styles.panel}>
        <Text style={styles.panelTitle}>New Todo:</Text>
        <Text style={styles.panelSubtitle}>e.g. Make a plan for tomorrow!</Text>
        <View>
          <TextInput
            label="What you want to do?"
            value={this.state.todoText}
            onChangeText={this.onChange}
            style={styles.taskInput}
          />
          <Button
            mode="contained"
            icon="plus-box"
            uppercase={false}
            style={styles.saveButton}
            onPress={() => {
              console.log('test');
              if (!this.state.todoText.trim()) {
                return;
              }

              this.bs.current.snapTo(0);

              this.props.addTodo(this.state.todoText);
              this.state.todoText = '';

              this.props.setToggleFilter(ToggleFilter.HIDE);
              // switch to all tasks
              this.props.setVisibilityFilter(VisibilityFilters.SHOW_ALL);
            }}
          >
            Save Todo
          </Button>
        </View>
      </View>
    );
  };

  renderHeader = () => (
    <View style={styles.header}>
      <View style={styles.panelHeader}>
        <View style={styles.panelHandle} />
      </View>
    </View>
  );

  // Create ref to control the bottomsheet object
  bs = React.createRef();

  render() {
    return (
      <KeyboardAvoidingView style={styles.bottomsheetContainer} behavior="position">
        <BottomSheet
          ref={this.bs}
          snapPoints={[0, 300]}
          renderContent={this.renderInner}
          renderHeader={this.renderHeader}
          initialSnap={0}
          enabledBottomClamp={true}
          onCloseEnd={() => {
            this.props.setToggleFilter(ToggleFilter.HIDE);
          }}
        />
        <Text></Text>
      </KeyboardAvoidingView>
    );
  }
}

const IMAGE_SIZE = 200;

const styles = StyleSheet.create({
  bottomsheetContainer: {
    height: 1,
    lineHeight: 1,
  },
  container: {
    backgroundColor: '#F5FCFF',
    borderWidth: 0,
  },
  saveButton: {
    width: 180,
    marginTop: 10,
    marginLeft: 'auto',
    marginRight: 10,
  },
  taskInput: {
    width: '100 %',
  },
  box: {
    width: IMAGE_SIZE,
    height: IMAGE_SIZE,
  },
  panelContainer: {
    position: 'absolute',
    top: 0,
    bottom: 0,
    left: 0,
    right: 0,
  },
  panel: {
    height: 400,
    padding: 20,
    backgroundColor: '#f7f5eee8',
  },
  header: {
    backgroundColor: '#f7f5eee8',
    shadowColor: '#000000',
    paddingTop: 20,
    borderTopLeftRadius: 20,
    borderTopRightRadius: 20,
  },
  panelHeader: {
    alignItems: 'center',
  },
  panelHandle: {
    width: 40,
    height: 8,
    borderRadius: 4,
    backgroundColor: '#00000040',
    marginBottom: 10,
  },
  panelTitle: {
    fontSize: 27,
    height: 35,
  },
  panelSubtitle: {
    fontSize: 14,
    color: 'gray',
    height: 30,
    marginBottom: 10,
  },
  panelButton: {
    padding: 20,
    borderRadius: 10,
    backgroundColor: '#318bfb',
    alignItems: 'center',
    marginVertical: 10,
  },
  panelButtonTitle: {
    fontSize: 17,
    fontWeight: 'bold',
    color: 'white',
  },
  photo: {
    width: '100%',
    height: 225,
    marginTop: 30,
  },
  map: {
    height: '100%',
    width: '100%',
  },
});

const mapStateToProps = function(state) {
  return {
    toggleState: state.toggleFilter,
  };
};

const mapDispatchToProps = { addTodo, setVisibilityFilter, setToggleFilter };

export default connect(mapStateToProps, mapDispatchToProps)(AddTodoModal);
