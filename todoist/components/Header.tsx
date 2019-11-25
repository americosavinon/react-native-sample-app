import * as React from 'react';
import { Appbar } from 'react-native-paper';
import { connect } from 'react-redux'
import { ToggleFilter, setToggleFilter } from '../features/toggles/toggleSlice'
import { BackHandler } from 'react-native';

class HeaderNav extends React.Component {
    _goBack = () => {
        console.log('exit!')
        BackHandler.exitApp()
    }

    _handleSearch = () => console.log('Searching')
    _handleMore = () => {
        console.log(this.props.toggleState)

        if (this.props.toggleState == ToggleFilter.SHOW)
            this.props.setToggleFilter(ToggleFilter.HIDE)
        else
            this.props.setToggleFilter(ToggleFilter.SHOW)
    }

    render() {
        return (
            <Appbar.Header>
                <Appbar.BackAction
                    onPress={this._goBack}
                />
                <Appbar.Content
                    title="My Todos"
                    subtitle="Simple Demo"
                />
                <Appbar.Action icon={this.props.toggleState == ToggleFilter.SHOW ? 'minus' : 'plus'} onPress={this._handleMore} />
            </Appbar.Header>
        );
    }
}

const mapStateToProps = function (state) {
    return {
        toggleState: state.toggleFilter,
    }
}

const mapDispatchToProps = { setToggleFilter }

export default connect(
    mapStateToProps,
    mapDispatchToProps
)(HeaderNav)