import React from 'react';
import KTrackPanel from "./Panel/KTrackPanel";
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
            spacing={1}
        >
            <Grid item xs={2}>
                <KTrackPanel
                    name={props.track.name}
                    instruments={props.instruments}
                    selectedInstruments={props.selectedInstruments}
                    setSelectedInstruments={props.setSelectedInstruments}
                    selected={props.selected}
                    setSelected={props.setSelected}
                />
            </Grid>
            <Grid item xs={10}>
                <KPartition
                    track={props.track}
                    totalLength={props.totalLength}
                />
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