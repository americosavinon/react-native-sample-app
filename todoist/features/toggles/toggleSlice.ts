import { createSlice } from '@reduxjs/toolkit'

export const ToggleFilter = {
    SHOW: 'SHOW',
    HIDE: 'HIDE'
}

const toggleSlice = createSlice({
    name: 'toggleFilter',
    initialState: ToggleFilter.HIDE,
    reducers: {
        setToggleFilter(state, action) {
            // console.log(state);
            return action.payload
        }
    }
})

export const { setToggleFilter } = toggleSlice.actions

export default toggleSlice.reducer