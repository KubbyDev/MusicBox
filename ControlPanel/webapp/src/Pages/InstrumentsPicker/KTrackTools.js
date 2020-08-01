import React from 'react';
import {Button} from "@material-ui/core";
import {Dropdown} from "react-bootstrap";
import Grid from "@material-ui/core/Grid";
import {makeStyles} from "@material-ui/styles";
import {useHistory} from "react-router";

export default function KTrackTools(props) {

    const classes = useStyles();
    const history = useHistory();

    const tools = (() => {
        // eslint-disable-next-line react-hooks/rules-of-hooks
        const [octaveShift, setOctaveShift] = React.useState(0);
        return [
            {
                id: 0,
                name: 'Octave Shift',
                args: octaveShift,
                setArgs: setOctaveShift,
                shouldSend: () => octaveShift !== 0,
            }
        ];
    })();

    // Apply button
    const apply = () => {

        const jobs = tools.filter(t => t.shouldSend()).map(t => ({
            args: t.args,
            id: t.id,
        }));
        if(jobs.length === 0) return;

        fetch('/api/process', {
            method: 'post',
            body: JSON.stringify({
                jobs: jobs,
                selectedTracks: props.selectedTracks
                    .filter(trackSelection => trackSelection[0])
                    .map((trackSelection, index) => index),
            }),
        })
            .then(() => {
                history.push('/');
                history.push('/instrumentpicker');
            })
            .catch(console.error);
    };

    return (
        <Grid
            container
            direction='row'
        >
            <Grid item>
                <Dropdown>
                    <Dropdown.Toggle variant='secondary'>Track Tools</Dropdown.Toggle>
                    <Dropdown.Menu>
                        <Grid
                            container
                            direction='column'
                        >
                            <Grid item>
                                {/* Octave shift ------------------------------------------------------------------- */}
                                <Grid container
                                    direction='row'
                                    alignItems='center'
                                    justify='space-around'
                                    style={{width:400}}
                                >
                                    <Grid item>
                                        <p>Octave shift</p>
                                    </Grid>
                                    <Grid item xs={6}>
                                        <Grid container
                                              direction='row'
                                              alignItems='center'
                                              justify='space-between'
                                              style={{width:'100%'}}
                                        >
                                            <Grid item>
                                                <Button onClick={() => {tools[0].setArgs(tools[0].args -1)}}>DOWN</Button>
                                            </Grid>
                                            <Grid item>
                                                {tools[0].args}
                                            </Grid>
                                            <Grid item>
                                                <Button onClick={() => {tools[0].setArgs(tools[0].args +1)}}>UP</Button>
                                            </Grid>
                                        </Grid>
                                    </Grid>
                                </Grid>
                            </Grid>
                            <Grid item>
                                <Dropdown.Divider/>
                            </Grid>
                            <Grid item>
                                <p>Second tool</p>
                            </Grid>
                        </Grid>
                    </Dropdown.Menu>
                </Dropdown>
            </Grid>
            <Grid item>
                <Button
                    className={classes.apply}
                    onClick={apply}
                >
                    Apply
                </Button>
            </Grid>
        </Grid>
    );
}

const useStyles = makeStyles(theme => ({
    apply: {
        backgroundColor: theme.palette.secondary.main,
        color: theme.palette.text.dark,
        borderColor: theme.palette.background.borders,
    }
}))