import React, { Component } from 'react'
import { Checkbox, List, WhiteSpace } from '@ant-design/react-native'
import { Button } from 'react-native-paper'
import { View } from 'react-native'
const CheckboxItem = Checkbox.CheckboxItem

export default class todoitem extends Component {

    onChange = (todoitem) => {
        console.log(todoitem);

        // update the todoitem status
        let newTodoItem = Object.assign({}, todoitem);
        newTodoItem.completed = !newTodoItem.completed;

        // make a post here for api change
        fetch('https://jsonplaceholder.typicode.com/todos/' + todoitem.id, {
            method: 'PUT',
            body: JSON.stringify(newTodoItem),
            headers: {
                "Content-type": "application/json; charset=UTF-8"
            }
        })
            .then(response => response.json())
            .then(json => console.log(json))
    }

    render() {
        return (
            <View style={{ flex: 1, flexDirection: 'row' }}>
                <View style={{ flex: 10 }}>
                    <CheckboxItem onChange={() => this.onChange(this.props.rowData)}>
                        {this.props.rowData.title}
                    </CheckboxItem>
                </View>
                <View style={{ flex: 1, width: 25, paddingTop: 5 }}>
                    <Button icon="delete"></Button>
                </View>
            </View>
        )
    }
}
