import React from 'react';
import KHomePage from "./Pages/KHomePage";
import KInstrumentsPage from "./Pages/InstrumentsPicker/KInstrumentsPage";
import { Route, Switch } from "react-router-dom";
import {createMuiTheme} from "@material-ui/core";
import {ThemeProvider} from "@material-ui/styles";

const theme = createMuiTheme({
    palette: {
        primary: {
            main: '#069d00',
        },
        secondary: {
            main: '#ffffff',
        },
        text: {
            main: '#ffffff',
            secondary: '#cccccc',
        },
        background: {
            main: '#404040',
            secondary: '#2b2b2b',
            accentuation: '#000000',
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