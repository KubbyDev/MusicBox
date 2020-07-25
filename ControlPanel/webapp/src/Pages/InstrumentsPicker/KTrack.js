import React from 'react';
import KTrackPanel from "./Panel/KTrackPanel";
import Grid from "@material-ui/core/Grid";
import KPartition from "./KPartition";
import makeStyles from "@material-ui/core/styles/makeStyles";

export default function KTrack(props) {

    const classes = useStyles();

    // Generates an object with information on the errors to display on the partition
    const partitionModifications = () => {
        let res = [];
        for(let instrument of props.instruments.filter(i => props.selectedInstruments.includes(i.name))) {
            for (let error of instrument.errors.concat(instrument.warnings)) {
                if (! error.args) continue;
                if (error.args.min) res.min = res.min ? Math.max(res.min, error.args.min) : error.args.min;
                if (error.args.max) res.max = res.max ? Math.min(res.max, error.args.max) : error.args.max;
            }
        }
        return res;
    }

    return (
        <Grid
            container
            direction='row'
            className={classes.track}
            justify='flex-start'
            alignItems='center'
            spacing={1}
        >
            <Grid item xs={3}>
                <KTrackPanel
                    name={props.track.name}
                    instruments={props.instruments}
                    selectedInstruments={props.selectedInstruments}
                    setSelectedInstruments={props.setSelectedInstruments}
                    selected={props.selected}
                    setSelected={props.setSelected}
                />
            </Grid>
            <Grid item xs={9}>
                <KPartition
                    track={props.track}
                    totalLength={props.totalLength}
                    modifications={partitionModifications()}
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