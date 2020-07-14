import React from 'react';
import Grid from "@material-ui/core/Grid";
import 'bootstrap/dist/css/bootstrap.min.css';
import {Dropdown, Button, ButtonGroup} from "react-bootstrap";
import KInstrument from "./KInstrument";
import makeStyles from "@material-ui/styles/makeStyles";
import Checkbox from '@material-ui/core/Checkbox'

export default function KTrackPanel(props) {

    const classes = useStyles();

    return (
        <Grid
            container
            direction='column'
            alignItems='center'
            justify='center'
        >
            {/* Track title and checkbox */}
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
            {/* Instruments selection dropdown */}
            <Grid item>
                <Dropdown as={ButtonGroup}>
                    {/* Dropdown title */}
                    <Button variant={props.selectedInstruments.length > 0 ? 'success' : 'secondary'}>
                        {props.selectedInstruments.join(', ') || 'Select an instrument'}
                    </Button>
                    <Dropdown.Toggle variant={props.selectedInstruments.length > 0 ? 'success' : 'secondary'}/>
                    {/* Dropdown buttons */}
                    <Dropdown.Menu>
                        {
                            props.instruments.map(instrument =>
                                <Dropdown.Item
                                    as={KInstrument}
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
        '&$checked': {
            color: theme.palette.primary.main,
        },
    }
}));