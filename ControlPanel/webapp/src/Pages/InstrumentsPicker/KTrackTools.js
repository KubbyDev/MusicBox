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

        const args = tools.filter(t => t.shouldSend()).map(t => ({
            args: t.args,
            id: t.id,
        }));
        if(args.length === 0) return;

        fetch('/api/process', {
            method: 'post',
            body: args,
        })
            .then(() => {
                history.push('/');
                history.push('/instrumentpicker');
            })
            .catch(console.error);
    };

    const test_______testing_____temporary__should_not_be_there_octavetool = () => {
        tools[0].setArgs(tools[0].args +1);
        console.log(tools[0].args);
    }

    return (
        <Grid
            container
            direction='row'
        >
            <Grid item>
                <Dropdown>
                    <Dropdown.Toggle variant='secondary'>Track Tools</Dropdown.Toggle>
                    <Dropdown.Menu>
                        <Button onClick={test_______testing_____temporary__should_not_be_there_octavetool}>Btn</Button>
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