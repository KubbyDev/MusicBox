const noteparser = require('note-parser');

let stopped = false;
let notes = [];
const audioContext = new AudioContext();

const stopNote = (note, rm) => {
    if(rm === undefined) rm = true;
    if(rm) notes = remove(notes, note);
    if(note.playing) {
        note.gain.gain.exponentialRampToValueAtTime(0.00001, audioContext.currentTime + 0.04);
        setTimeout(() => note.oscillator.stop(), 500);
    }
    clearInterval(note.interval);
    note.playing = false;
}

const remove = (array, e) => array.filter(x => x !== e);

const playMelody = (melody) => {

    if (notes.length > 0) {
        console.error('A melody is already playing');
        return;
    }

    stopped = false;
    return new Promise((resolve, reject) => {

        const start = Date.now();
        const elapsed = () => Date.now() - start;

        const playNote = (start, end, pitch) => {

            let o = audioContext.createOscillator();
            let g = audioContext.createGain();
            o.connect(g);
            g.connect(audioContext.destination);
            o.frequency.value = noteparser.freq(pitch);
            let current = {
                interval: undefined,
                oscillator: o,
                gain: g,
                playing: false,
            };
            notes.push(current);

            current.interval = setInterval(() => {
                // Starts the note
                if (!current.playing && elapsed() > start) {
                    o.start(0);
                    current.playing = true;
                    console.log(o.frequency.value);
                }
                // Stops the note
                if (current.playing && elapsed() > end) {
                    stopNote(current, true);
                }
            }, 5);

            return current;
        }

        // Schedules all the note events
        for(let note of melody)
            playNote(note.start, note.end, note.pitch);

        // Waits for the melody to finish
        const i = setInterval(() => {

            if(notes.length > 0)
                return;

            clearInterval(i);
            resolve(stopped);
        });
    });
}

const stopMelody = () => {
    stopped = true;
    for(let note of notes)
        stopNote(note, false);
    notes = [];
}

export { playMelody, stopMelody }