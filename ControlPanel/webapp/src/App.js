import React from 'react';
import KHomePage from "./Pages/KHomePage";
import { Route, Switch } from "react-router-dom";
import {createMuiTheme} from "@material-ui/core";
import {ThemeProvider} from "@material-ui/styles";
import KUploadPage from "./Pages/Upload/KUploadPage";
import KInstrumentsPageLoader from "./Pages/InstrumentsPicker/KInstrumentsPageLoader";
import KMelodiesPageLoader from "./Pages/Melodies/KMelodiesPageLoader";

const theme = createMuiTheme({
    palette: {
        primary: {
            main: '#9d0000',
            light: '#ff2d2d',
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
            last: '#111111',
            error: '#400e0e',
        }
    },
});

export default function App() {
    return (
        <ThemeProvider theme={theme}>
            <Switch>
                <Route exact path='/' component={KHomePage}/>
                <Route exact path='/instrumentpicker' component={KInstrumentsPageLoader}/>
                <Route exact path='/upload' component={KUploadPage}/>
                <Route exact path='/melodies' component={KMelodiesPageLoader}/>
            </Switch>
        </ThemeProvider>
    );
}