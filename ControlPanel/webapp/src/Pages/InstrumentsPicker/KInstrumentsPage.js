import React from 'react';
import KTrack from "./KTrack";
import Grid from "@material-ui/core/Grid";
import makeStyles from "@material-ui/core/styles/makeStyles";

export default function KInstrumentsPage() {

    const classes = useStyles();

    let tracks = [
        {name: 'Track1', lowest: 34, highest: 89, notes: [{start: 0, end: 900, pitch: 57},{start: 900, end: 1500, pitch: 67}]},
        {name: 'Track2', lowest: 39, highest: 46, notes: [{start: 400, end: 600, pitch: 40},{start: 900, end: 1500, pitch: 42}]},
        {name: 'Track3', lowest: 20, highest: 69, notes: [{start: 40, end: 300, pitch: 51},{start: 900, end: 1500, pitch: 67}]},
        {name: 'Track4', lowest: 67, highest: 78, notes: [{start: 0, end: 500, pitch: 77},{start: 900, end: 1500, pitch: 68}]},
    ]
    let totallength = 1500;

    return (
        <Grid
            container
            spacing={1}
            alignItems='stretch'
            direction='column'
            className={classes.trackslist}
        >
            {tracks.map(track =>
                <Grid item xs={12}>
                    <KTrack track={track} totallength={totallength}/>
                </Grid>
            )}
        </Grid>
    );
}

const useStyles = makeStyles(theme => ({
    trackslist: {
        backgroundColor: theme.palette.background.accentuation,
        padding: theme.spacing(1),
    }
}));