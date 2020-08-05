import React from 'react';
import KMelody from "./KMelody";
import Grid from "@material-ui/core/Grid";

export default function KMelodiesPage(props) {

    return (
        <>
            <Grid
                container
                justify='space-between'
                alignItems='center'
                direction='column'
            >
                {
                    props.melodies.map((melody, index) => {
                        return (
                            <Grid item key={index}>
                                <KMelody name={melody}/>
                            </Grid>
                        );
                    })
                }
            </Grid>
        </>
    );
}