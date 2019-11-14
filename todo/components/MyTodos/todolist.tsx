import React, { Component } from 'react'
import { FlatList, StyleSheet, Text, ScrollView, View, ActivityIndicator } from 'react-native';
import { Checkbox, List, WhiteSpace, Tabs } from '@ant-design/react-native';
import Todoitem from './todoitem'

const Item = List.Item;
const Brief = Item.Brief;

export default class todolist extends Component {
    constructor(props, context) {
        super(props, context);
        this.state = {
            isLoading: true,
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

    render() {
        const tabs = [
            { title: 'Tasks' },
            { title: 'Finished' }
        ];

        const style = {
            justifyContent: 'left',
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
                            renderItem={({ item }) => <Todoitem title={item.title}></Todoitem>}
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
                            renderItem={({ item }) => <Todoitem title={item.title}></Todoitem>}
                            keyExtractor={item => item.id.toString()}
                        />
                    </ScrollView>
                </View>
            </Tabs>
        )
    }
}
