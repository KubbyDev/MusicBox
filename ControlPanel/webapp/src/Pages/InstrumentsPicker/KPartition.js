import React from 'react';
import {useTheme} from "@material-ui/styles";


export default function KPartition(props) {

    const theme = useTheme();
    const noteHeight = 8;

    const midiToName = (midi) => {
        if(midi > 108 || midi < 21) {
            console.error("Couldn't convert midi pitch " + midi + " to note name");
            return 'ERR';
        }
        const notes = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"];
        const octave = Math.floor(midi / 12) - 1;
        const noteIndex = (midi % 12);
        return notes[noteIndex] + octave;
    }

    const drawCanvas = (canvas) => {

        if(!canvas) return;

        // Sets the canvas up
        const ctx = canvas.getContext('2d');
        canvas.width = window.innerWidth;
        canvas.height = (props.track.highest - props.track.lowest +1)*noteHeight;

        // Defines the drawing area for the partition
        const width = canvas.width - 25;
        const height = canvas.height;
        ctx.fillStyle = theme.palette.background.secondary;
        ctx.fillRect(0, 0, width, height);

        // Highest and lowest notes
        ctx.fillStyle = theme.palette.text.main;
        ctx.textAlign = "center";
        ctx.textBaseline = "middle";
        ctx.font = "12px Arial";
        ctx.fillText(midiToName(props.track.lowest), canvas.width - 12, canvas.height - 6);
        ctx.fillText(midiToName(props.track.highest), canvas.width - 12, 6);

        // Modification: min and max notes
        ctx.fillStyle = theme.palette.background.error;
        if(props.modifications.min !== undefined) {
            let height = (props.modifications.min - props.track.lowest) * noteHeight;
            ctx.fillRect(0, height - height, width, height);
        }
        if(props.modifications.max !== undefined)
            ctx.fillRect(0, 0, width, (props.track.highest - props.modifications.max)*noteHeight);

        const mult = width/props.totalLength;
        ctx.fillStyle = theme.palette.primary.main;
        for (let note of props.track.notes)
            ctx.fillRect(
                note.start * mult,
                (props.track.highest - note.pitch) * noteHeight,
                (note.end-note.start)*mult,
                noteHeight
            );
    }

    return (
        <canvas
            ref={drawCanvas}
            style={{width: '100%'}}
        />
    );
};