import React from 'react';
import KHomePage from "./Pages/KHomePage";
import KInstrumentsPage from "./Pages/InstrumentsPicker/KInstrumentsPage";
import { Route, Switch } from "react-router-dom";
import {createMuiTheme} from "@material-ui/core";
import {ThemeProvider} from "@material-ui/styles";

const theme = createMuiTheme({
    palette: {
        primary: {
            main: '#9d0000',
            light: '#ff5555',
        },
        secondary: {
            main: '#ffffff',
            disabled: '#909090',
        },
        text: {
            main: '#ffffff',
            secondary: '#bbbbbb',
            dark: '#000000',
        },
        background: {
            main: '#404040',
            secondary: '#2b2b2b',
            borders: '#000000',
            last: '#111111'
        }
    },
});

export default function App() {
    return (
        <ThemeProvider theme={theme}>
            <Switch>
                <Route exact path='/' component={KHomePage}/>
                <Route exact path='/instrumentpicker' component={KInstrumentsPage}/>
            </Switch>
        </ThemeProvider>
    );
}