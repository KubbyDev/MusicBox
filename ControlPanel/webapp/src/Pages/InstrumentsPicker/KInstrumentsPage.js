import React from 'react';
import KTrack from "./KTrack";
import {Grid, Button} from "@material-ui/core";
import makeStyles from "@material-ui/core/styles/makeStyles";
import { playMelody, stopMelody } from "../../MelodyPlayer";
import KTrackTools from "./KTrackTools";
import {useHistory} from "react-router";

export default function KInstrumentsPage(props) {

    const classes = useStyles();
    const history = useHistory();
    const [playingMelodyB, setPlayingMelodyB] = React.useState(false);
    const [playingMelodyM, setPlayingMelodyM] = React.useState(false);

    // Filters the errors and warnings for a particular track
    const instrumentsForTrack = (track) => {
        return props.instruments.map(inst => ({
            name: inst.name,
            warnings: inst.warnings.filter(w => w.track === track),
            errors: inst.errors.filter(e => e.track === track),
        }));
    };

    let selectedInstruments = [];
    for(let i=0; i < props.tracks.length; i++)
        // eslint-disable-next-line react-hooks/rules-of-hooks
        selectedInstruments.push(React.useState([]));
    /* When filled: [
           [[inst0, inst1], setInstrumentsTrack0],
           [[inst5], setInstrumentsTrack1],
           [[inst3], setInstrumentsTrack2]
       ]
    */

    let selectedTracks = [];
    for(let i = 0; i < props.tracks.length; i++)
        // eslint-disable-next-line react-hooks/rules-of-hooks
        selectedTracks.push(React.useState(false));
    /* When filled: [
           [selectedTrack0, setSelectedTrack0],
           [selectedTrack1, setSelectedTrack1],
           [selectedTrack2, setSelectedTrack2]
       ]
    */

    const handlePlayBrowser = () => {
        if(! playingMelodyB) {
            let notes = [];
            for(let i = 0; i < props.tracks.length; i++) {
                if(selectedTracks[i][0])
                    notes = notes.concat(props.tracks[i].notes);
            }
            setPlayingMelodyB(true);
            playMelody(notes)
                .then((forced) => {
                    if(!forced) setPlayingMelodyB(false)
                });
        }
        else {
            stopMelody();
            setPlayingMelodyB(false);
        }
    }

    const handlePlayMusicbox = () => {

        setPlayingMelodyM( ! playingMelodyM);
    };

    const handleGenerate = () => {

        let body = {};
        // For each instrument
        for(let instrument of props.instruments) {
            let trackId = -1;
            // Goes through all the tracks
            for(let i = 0; i < props.tracks.length; i++) {
                // If this track is not selected
                if( ! selectedTracks[i][0]) continue;
                // If this track has this instrument selected
                if(selectedInstruments[i][0].includes(instrument.name)) {
                    trackId = i;
                    break;
                }
            }
            if(trackId !== -1) // If a selected track selected this instrument
                body[instrument.name] = trackId;
        }

        fetch('/api/generate/Melody', {method: 'post', body: JSON.stringify(body)})
            .then(history.push({pathname: '/melodies', state: false}))
            .catch(console.error);
    };

    return (
        <>
            {/* Top toolbar ---------------------------------------------------------------------------------------- */}
            <Grid
                container
                direction='row'
                justify='space-between'
                alignItems='center'
                className={classes.topToolbar}
            >
                <Grid item xs={3}>
                    <Grid
                        container
                        alignItems='center'
                        justify='space-evenly'
                    >
                        <Grid item>
                            <Button
                                className={classes.topToolbarButton}
                                onClick={()=>{ for(let t of selectedTracks) t[1](true) }}
                            >
                                Select all
                            </Button>
                        </Grid>
                        <Grid item>
                            <Button
                                className={classes.topToolbarButton}
                                onClick={()=>{ for(let t of selectedTracks) t[1](false) }}
                            >
                                Deselect all
                            </Button>
                        </Grid>
                    </Grid>
                </Grid>
                <Grid item xs={3}>
                    <KTrackTools
                        tracks={props.tracks}
                        selectedTracks={selectedTracks}
                    />
                </Grid>
                <Grid item xs={3}>
                    <Grid
                        container
                        alignItems='center'
                        justify='space-evenly'
                    >
                        <Grid item>
                            <Button className={classes.topToolbarButton} onClick={handlePlayBrowser}>
                                {playingMelodyB ? 'Stop playing' : 'Play on browser'}
                            </Button>
                        </Grid>
                        <Grid item>
                            <Button className={classes.topToolbarButton} onClick={handlePlayMusicbox}>
                                {playingMelodyM ? 'Stop playing' : 'Play on music box'}
                            </Button>
                        </Grid>
                    </Grid>
                </Grid>
                <Grid item>
                    <Button className={classes.topToolbarButton} onClick={handleGenerate}>
                        Generate
                    </Button>
                </Grid>
            </Grid>
            {/* Tracks --------------------------------------------------------------------------------------------- */}
            <Grid
                container
                alignItems='stretch'
                direction='column'
                className={classes.trackslist}
            >
                {props.tracks.map((track, index) =>
                    <Grid item xs={12} className={classes.track} key={index}>
                        <KTrack
                            track={track}
                            totalLength={props.totalLength}
                            instruments={instrumentsForTrack(track.name)}
                            selectedInstruments={selectedInstruments[index][0]}
                            setSelectedInstruments={selectedInstruments[index][1]}
                            selected={selectedTracks[index][0]}
                            setSelected={selectedTracks[index][1]}
                        />
                    </Grid>
                )}
            </Grid>
        </>
    );
}

const useStyles = makeStyles(theme => ({
    trackslist: {
        backgroundColor: theme.palette.background.borders,
        padding: theme.spacing(1),
    },
    track: {
        marginBottom: theme.spacing(2),
    },
    topToolbar: {
        backgroundColor: theme.palette.primary.light,
    },
    topToolbarButton: {
        backgroundColor: theme.palette.secondary.main,
        color: theme.palette.text.dark,
        borderColor: theme.palette.background.borders,
    }
}));