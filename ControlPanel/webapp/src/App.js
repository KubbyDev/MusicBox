import React from 'react';
import KHomePage from "./Pages/KHomePage";
import KInstrumentsPage from "./Pages/InstrumentsPicker/KInstrumentsPage";
import { Route, Switch } from "react-router-dom";
import {createMuiTheme} from "@material-ui/core";
import {ThemeProvider} from "@material-ui/styles";
import {makeStyles} from "@material-ui/core/styles";

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
            accentuation: '#000000',
            last: '#222222'
        }
    },
});

export default function App() {

    const classes = useStyles();

    return (
        <ThemeProvider theme={theme}>
            <div className={classes.background}>
                <Switch>
                    <Route exact path='/' component={KHomePage}/>
                    <Route exact path='/instrumentpicker' component={KInstrumentsPage}/>
                </Switch>
            </div>
        </ThemeProvider>
    );
}

const useStyles = makeStyles((theme) => ({
    background: {
        backgroundColor: theme.palette.background.last,
    },
}));