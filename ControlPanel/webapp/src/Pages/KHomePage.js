import React from 'react';
import Button from "@material-ui/core/Button";
import Grid from "@material-ui/core/Grid";
import {makeStyles} from "@material-ui/styles";
import {useHistory} from "react-router";

export default function KHomePage() {

    const classes = useStyles();
    const history = useHistory();

    const buttons = [
        {name: 'Processes\nPicker', destination:'/instrumentpicker', color: 'aqua'},
        {name: 'Upload\nFile', destination:'/upload', color: 'magenta'},
        {name: 'Melodies', destination:'/melodies', color: 'green'},
    ]

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
                [buttons.slice(0, 3), buttons.slice(3, 6)].map((row, index) => {
                    if (!row)
                        return (<></>);
                    return (
                        <Grid item xs={12} key={index}>
                            <Grid
                                container
                                direction='row'
                                className={classes.rowgrid}
                            >
                                {
                                    row.map((button, index2) => {
                                        if (!button)
                                            return (<></>);
                                        return (
                                            <Grid item xs={4} key={index2}>
                                                <Button
                                                    title={button.name}
                                                    onClick={() => handleClick(button.destination)}
                                                    className={classes.button}
                                                    style={{backgroundColor: button.color}}
                                                >
                                                    {button.name}
                                                </Button>
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
        width: '80%',
        height: '80%',
        color: theme.palette.text.main,
        paddingTop: '40%',
        paddingBottom: '40%',
        fontSize: '60',
    },
    maingrid: {
        width: '100%',
        height: '100',
    },
    rowgrid: {
        width: '100%',
        height: '100%',
    },
}));