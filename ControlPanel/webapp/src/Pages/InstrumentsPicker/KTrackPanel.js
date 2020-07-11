import React from 'react';
import Grid from "@material-ui/core/Grid";
import {makeStyles} from "@material-ui/core/styles";

export default function KTrackPanel(props) {

    const classes = useStyles();

    return (
        <Grid
            container
            direction='row'
            alignItems='center'
            justify='center'
        >
            <Grid item className={classes.name}>
                <p>{props.name}</p>
            </Grid>
        </Grid>
    );
};

const useStyles = makeStyles((theme) => ({
    name: {
        padding: theme.spacing(2),
        textAlign: 'center',
        color: theme.palette.text.main,
    },
}));