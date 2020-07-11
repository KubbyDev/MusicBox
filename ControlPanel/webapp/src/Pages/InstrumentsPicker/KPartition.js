import React from 'react';
import {useTheme} from "@material-ui/styles";

// TEMPORARY
const noteHeight = 8;


export default function KPartition(props) {

    const theme = useTheme();

    const drawCanvas = (canvas) => {
        const ctx = canvas.getContext('2d');
        ctx.fillStyle = theme.palette.background.secondary;
        ctx.fillRect(0, 0, canvas.width, canvas.height);

        const mult = 500/props.totallength;
        ctx.fillStyle = theme.palette.primary.main;
        for (let note of props.track.notes) {
            const row = note.pitch - props.track.lowest;
            ctx.fillRect(note.start*mult, (row-0.5)*noteHeight, (note.end-note.start)*mult, noteHeight);
        }
    }

    return (
        <canvas
            ref={drawCanvas}
            width={500}
            height={(props.track.highest - props.track.lowest)*noteHeight}
        />
    );
};