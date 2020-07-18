import React from 'react';
import Button from "@material-ui/core/Button";
import Grid from "@material-ui/core/Grid";
import {makeStyles} from "@material-ui/styles";
import {useHistory} from "react-router";

export default function KHomePage() {

    const classes = useStyles();
    const history = useHistory();

    const buttons = [
        {name: 'Instruments\nPicker', destination:'/instrumentpicker', color: 'aqua'},
    ]//.concat(Array(6).fill({name:'Button',destination:'/',color:'aqua'}, 0, 6)).slice(0,6);

    const handleClick = (destination) => {
        console.log(destination);
        history.push(destination);
    };

    return (
        <Grid
            container
            direction='column'
            className={classes.maingrid}
        >
            {
                [buttons.slice(0, 3), buttons.slice(3, 6)].map(row => {
                    if (!row)
                        return (<></>);
                    return (
                        <Grid item xs={6}>
                            <Grid
                                container
                                direction='row'
                                className={classes.rowgrid}
                            >
                                {
                                    row.map(button => {
                                        if (!button)
                                            return (<></>);
                                        return (
                                            <Grid item xs={4}>
                                                <Button
                                                    title={button.name}
                                                    onClick={() => handleClick(button.destination)}
                                                    className={classes.button}
                                                    style={{backgroundColor: button.color}}
                                                />
                                            </Grid>
                                        )
                                    })
                                }
                            </Grid>
                        </Grid>
                    )
                })
            }
        </Grid>
    );
}

const useStyles = makeStyles(theme => ({
    button: {
        width: '100%',
        height: '100%',
    },
    maingrid: {
        width: '100%',
        height: '100%',
    },
    rowgrid: {
        width: '100%',
        height: '100%',
    },
}));