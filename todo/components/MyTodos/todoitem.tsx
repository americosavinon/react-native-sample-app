import React, { Component } from 'react'
import { Checkbox, List, WhiteSpace } from '@ant-design/react-native';

const CheckboxItem = Checkbox.CheckboxItem;

export default class todoitem extends Component {

    render() {
        return (
            <CheckboxItem>
                {this.props.title}
            </CheckboxItem>
        )
    }
}
