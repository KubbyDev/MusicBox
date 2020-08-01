import React from 'react';
import Grid from "@material-ui/core/Grid";
import 'bootstrap/dist/css/bootstrap.min.css';
import {Dropdown, Button, ButtonGroup} from "react-bootstrap";
import KInstrument from "./KInstrument";
import makeStyles from "@material-ui/styles/makeStyles";
import Checkbox from '@material-ui/core/Checkbox'

export default function KTrackPanel(props) {

    const classes = useStyles();

    const buttonVariant = (() => {
        // No selected instruments => grey
        if(props.selectedInstruments.length === 0) return 'secondary';
        // Gets the selected instruments objects
        const selected = props.instruments.filter(i => props.selectedInstruments.includes(i.name));
        // Errors => red
        if(selected.some(i => i.errors.length > 0)) return 'danger';
        // Warnings => yellow
        if(selected.some(i => i.warnings.length > 0)) return 'warning';
        // Nothing => green
        return 'success';
    })();

    return (
        <Grid
            container
            direction='column'
            alignItems='center'
            justify='center'
        >
            {/* Track title and checkbox --------------------------------------------------------------------------- */}
            <Grid item className={classes.name}>
                <Grid
                    container
                    direction='row'
                    alignItems='center'
                    spacing={1}
                >
                    <Grid item>
                        <strong style={{fontSize:32}}>{props.name}</strong>
                    </Grid>
                    <Grid item>
                        <Checkbox
                            className={classes.checkbox}
                            checked={props.selected}
                            onChange={e => props.setSelected(e.target.checked)}
                        />
                    </Grid>
                </Grid>
            </Grid>
            {/* Processes selection dropdown --------------------------------------------------------------------- */}
            <Grid item>
                <Dropdown as={ButtonGroup}>
                    {/* Dropdown title */}
                    <Button variant={buttonVariant}>
                        {props.selectedInstruments.join(', ') || 'Select an instrument'}
                    </Button>
                    <Dropdown.Toggle variant={buttonVariant}/>
                    {/* Dropdown buttons */}
                    <Dropdown.Menu>
                        {
                            props.instruments.map((instrument, index) =>
                                <Dropdown.Item
                                    key={index}
                                    as={KInstrument}
                                    errors={instrument.errors.map(e => e.message)}
                                    warnings={instrument.warnings.map(w => w.message)}
                                    active={props.selectedInstruments.includes(instrument.name)}
                                    onSelect={instname => {
                                        let res = props.selectedInstruments.slice();
                                        if(! res.includes(instname)) res.push(instname);
                                        else res = res.filter(x => x !== instname);
                                        props.setSelectedInstruments(res);
                                    }}
                                    eventKey={instrument.name}
                                >
                                    {instrument.name}
                                </Dropdown.Item>
                            )
                        }
                    </Dropdown.Menu>
                </Dropdown>
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
    checkbox: {
        color: theme.palette.primary.main,
    }
}));