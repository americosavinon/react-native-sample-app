import React, { Component } from 'react'
import { Checkbox, List, WhiteSpace } from '@ant-design/react-native';

const CheckboxItem = Checkbox.CheckboxItem;

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
            // 
            <CheckboxItem onChange={() => this.onChange(this.props.rowData)}>
                {this.props.rowData.title}
            </CheckboxItem>
        )
    }
}
