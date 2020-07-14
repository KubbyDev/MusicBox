import React from "react";
import {SafeAnchor} from "react-bootstrap";
import Grid from "@material-ui/core/Grid";
import ErrorIcon from '@material-ui/icons/Error';
import WarningIcon from '@material-ui/icons/Warning';
import Tooltip from "@material-ui/core/Tooltip";

export default function KInstrument(props) {

    const generateTooltip = () => {
        return props.errors.concat(props.warnings).join(', ');
    };

    return (
        <Tooltip title={generateTooltip()}>
            <Grid
                container
                direction='row'
                alignItems='center'
                justify='flex-start'
                spacing={0}
            >
                <Grid item xs={4}>
                    {props.errors.length > 0 ? <ErrorIcon style={{color:'red'}}/>
                        : (props.warnings.length > 0 ? <WarningIcon style={{color:'yellow'}}/>
                            : <></>)}
                </Grid>
                <Grid item xs={8}>
                    <SafeAnchor {...props}/>
                </Grid>
            </Grid>
        </Tooltip>
    )
}
