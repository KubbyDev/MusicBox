import React from 'react';
import KTrackPanel from "./KTrackPanel";
import Grid from "@material-ui/core/Grid";
import KPartition from "./KPartition";
import makeStyles from "@material-ui/core/styles/makeStyles";

export default function KTrack(props) {

    const classes = useStyles();

    return (
        <Grid
            container
            direction='row'
            className={classes.track}
            justify='flex-start'
            alignItems='center'
        >
            <Grid item>
                <KTrackPanel name={props.track.name} />
            </Grid>
            <Grid item>
                <KPartition track={props.track} totallength={props.totallength}/>
            </Grid>
        </Grid>
    );
};

const useStyles = makeStyles(theme => ({
    track: {
        backgroundColor: theme.palette.background.main,
        padding: theme.spacing(1),
    },
}));