import React from 'react';
import { StyleSheet, Text, View, KeyboardAvoidingView } from 'react-native';
import BottomSheet from 'reanimated-bottom-sheet';
import { TextInput } from 'react-native-paper';

export default class MyProfile extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      snapIndex: 1,
    };
  }

  renderInner = () => (
    <KeyboardAvoidingView style={styles.container} behavior="padding" enabled>
      <View style={styles.panel}>
        <Text style={styles.panelTitle}>Your Profile</Text>
        <Text style={styles.panelSubtitle}>Task List</Text>
        <View>
          <Text> Stats Data Show here! (v1.0.3) </Text>
          <Text />
          <TextInput label="Sample Form!" style={styles.taskInput} />
          <Text />
          <Text>github: https://github.com/peterlin99512/react-native-sample-app</Text>
        </View>
      </View>
    </KeyboardAvoidingView>
  );

  renderHeader = () => (
    <View style={styles.header}>
      <View style={styles.panelHeader}>
        <View style={styles.panelHandle} />
      </View>
    </View>
  );

  toggleSnapPoints = () => {
    if (this.state.snapIndex === 0) {
      this.setState({ snapIndex: 1 });
    } else {
      this.setState({ snapIndex: 0 });
    }

    this.bs.current.snapTo(this.state.snapIndex);
  };

  // Create ref to control the bottomsheet object
  bs = React.createRef();

  render() {
    return (
      <BottomSheet
        ref={this.bs}
        snapPoints={['88%', 0]}
        renderContent={this.renderInner}
        renderHeader={this.renderHeader}
        initialSnap={this.state.snapIndex}
      />
    );
  }
}

const IMAGE_SIZE = 200;

const styles = StyleSheet.create({
  container: {
    backgroundColor: '#F5FCFF',
    borderWidth: 0,
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
    height: 1000,
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
