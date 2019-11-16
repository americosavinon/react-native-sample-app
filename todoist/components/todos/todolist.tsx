import React, { Component } from 'react'
import { FlatList, StyleSheet, Text, ScrollView, View, ActivityIndicator } from 'react-native';
import { Button, Modal, Provider, List, WhiteSpace, Tabs, InputItem } from '@ant-design/react-native';
import { FAB, Portal, TextInput } from 'react-native-paper';
import Todoitem from './todoitem'

const Item = List.Item;

export default class Todolist extends Component {
    constructor(props, context) {
        super(props, context);
        this.state = {
            isLoading: true,
            visibleNewTodo: false,
            newTaskValue: ''
        };
    }

    componentDidMount() {
        this.fetchTodos();
    }

    // fetch the todos from remote source
    fetchTodos() {
        fetch('https://jsonplaceholder.typicode.com/todos')
            .then((resp) => resp.json())
            .then((respjson) => {
                this.setState({
                    isLoading: false,
                    newTaskDataSource: respjson.filter(task => task.completed == false).slice(0, 50),
                    finishedTaskDataSource: respjson.filter(task => task.completed == true).slice(0, 50),
                }, function () {
                });
            })
            .catch((error) => {
                console.error(error);
            });
    }


    onNewTask = () => {
        this.setState({
            visibleNewTodo: true,
        });
    };

    onClose = () => {
        console.log("close add popup called!");
        this.setState({
            visibleNewTodo: false,
        });
    };

    onSave = () => {
        console.log("save and close add popup called!");
        this.setState({
            visibleNewTodo: false,
        });

        this.state.newTaskDataSource.unshift({
            "completed": false,
            "id": 999,
            "title": this.state.newTaskValue,
            "userId": 4,
        });

        // call function to add to the state
        fetch('https://jsonplaceholder.typicode.com/todos', {
            method: 'POST',
            body: JSON.stringify({
                "completed": false,
                "id": 999,
                "title": this.state.newTaskValue,
                "userId": 4,
            }),
            headers: {
                "Content-type": "application/json; charset=UTF-8"
            }
        })
            .then(response => response.json())
            .then(json => console.log(json));
    };

    render() {
        const tabs = [
            { title: 'Tasks' },
            { title: 'Finished' }
        ];

        const style = {
            height: '100%',
            backgroundColor: 'white',
        } as any;

        if (this.state.isLoading) {
            return (
                <View style={{ flex: 1, padding: 20 }}>
                    <ActivityIndicator />
                </View>
            )
        }

        return (
            <Provider>
                <View style={{ flex: 1 }}>
                    <Tabs tabs={tabs}>
                        <View style={style}>
                            <ScrollView
                                style={{ flex: 1, backgroundColor: '#f5f5f9' }}
                                automaticallyAdjustContentInsets={false}
                                showsHorizontalScrollIndicator={false}
                                showsVerticalScrollIndicator={false}
                            >
                                <FlatList
                                    data={this.state.newTaskDataSource}
                                    renderItem={({ item }) => <Todoitem rowData={item} completed={item.completed}></Todoitem>}
                                    keyExtractor={item => item.id.toString()}
                                />
                            </ScrollView>
                        </View>
                        <View style={style}>
                            <ScrollView
                                style={{ flex: 1, backgroundColor: '#f5f5f9' }}
                                automaticallyAdjustContentInsets={false}
                                showsHorizontalScrollIndicator={false}
                                showsVerticalScrollIndicator={false}
                            >
                                <FlatList
                                    data={this.state.finishedTaskDataSource}
                                    renderItem={({ item }) => <Todoitem rowData={item} completed={item.completed}></Todoitem>}
                                    keyExtractor={item => item.id.toString()}
                                />
                            </ScrollView>
                        </View>
                    </Tabs>
                    <FAB.Group
                        open={this.state.open}
                        icon={this.state.open ? 'minus-box' : 'plus-box'}
                        actions={[
                            { icon: 'creation', label: 'Add Task', onPress: () => this.onNewTask() },
                            { icon: 'alert', label: 'Finished Task', onPress: () => console.log('Pressed email') },
                            { icon: 'alert', label: 'Remind', onPress: () => console.log('Pressed notifications') },
                        ]}
                        onStateChange={({ open }) => this.setState({ open })}
                        onPress={() => {
                            if (this.state.open) {
                                // do something if the speed dial is open
                            }
                        }}
                    />
                    <Modal
                        popup
                        visible={this.state.visibleNewTodo}
                        animationType="slide-up"
                        onClose={this.onClose}
                    >
                        <View style={{ paddingVertical: 20, paddingHorizontal: 20, height: 400 }}>

                            <TextInput
                                label='Task'
                                multiline
                                value={this.state.newTaskValue}
                                onChangeText={(value: any) => {
                                    this.setState({
                                        newTaskValue: value,
                                    });
                                }}
                            />
                        </View>
                        <Button type="primary" onPress={this.onSave}>
                            save
                    </Button>
                    </Modal>
                </View >
            </Provider>
        )
    }
}

const styles = StyleSheet.create({
    actionButtonIcon: {
        fontSize: 20,
        height: 22,
        color: 'white',
        zIndex: 1000
    }
});