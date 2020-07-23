import React from 'react';
import {useTheme} from "@material-ui/styles";


export default function KPartition(props) {

    const theme = useTheme();
    const noteHeight = 8;

    const drawCanvas = (canvas) => {

        console.log("Update");
        if(!canvas) console.log("No canvas");

        if(!canvas) return;

        const ctx = canvas.getContext('2d');
        canvas.width = window.innerWidth;
        canvas.height = (props.track.highest - props.track.lowest)*noteHeight;

        ctx.fillStyle = theme.palette.background.secondary;
        ctx.fillRect(0, 0, canvas.width, canvas.height);

        // Modification: min and max notes
        ctx.fillStyle = theme.palette.background.error;
        if(props.modifications.min !== undefined) {
            let height = (props.modifications.min - props.track.lowest) * noteHeight;
            ctx.fillRect(0, canvas.height - height, canvas.width, height);
        }
        if(props.modifications.max !== undefined)
            ctx.fillRect(0, 0, canvas.width, (props.track.highest - props.modifications.max)*noteHeight);

        const mult = canvas.width/props.totalLength;
        ctx.fillStyle = theme.palette.primary.main;
        for (let note of props.track.notes) {
            const row = props.track.highest - note.pitch;
            ctx.fillRect(
                note.start*mult,
                (row-0.5)*noteHeight,
                (note.end-note.start)*mult,
                noteHeight
            );
        }
    }

    return (
        <canvas
            ref={drawCanvas}
            style={{width: '100%'}}
        />
    );
};