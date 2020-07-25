import React from 'react';
import KInstrumentsPage from "./KInstrumentsPage";

export default function KInstrumentsPageLoader(props) {

    let [notes, setNotes] = React.useState(null);
    let [instruments, setInstruments] = React.useState(null);
    let [notesProgress, setNotesProgress] = React.useState(null);
    let [instrumentsProgress, setInstrumentsProgress] = React.useState(null);

    const getNotesProgress = () => {
        fetch('/api/notes/progress')
            .then(res => res.json())
            .then(res => {
                setNotesProgress(res);
                if (res.percent === 100) getInstrumentsProgress();
                else getNotesProgress();
            })
            .catch(console.error);
    }

    const getInstrumentsProgress = () => {
        fetch('/api/instruments/progress')
            .then(res => res.json())
            .then(res => {
                setInstrumentsProgress(res)
                if (res.percent === 100) loadInstrumentsPage()
                else getInstrumentsProgress();
            })
            .catch(console.error);
    }

    const loadInstrumentsPage = () => {
        fetch('/api/notes')
            .then(res => res.json())
            .then(res => setNotes(res))
            .catch(console.error);
        fetch('/api/instruments')
            .then(res => res.json())
            .then(res => setInstruments(res))
            .catch(console.error);
    }

    if(notesProgress === null) getNotesProgress();

    const loadingPage = (
        <>
            <p>Waiting for results...</p>
            <p>
                {
                    notesProgress === null
                        ?   '0%  Getting progression information'
                        :   notesProgress.percent + '%  ' + notesProgress.status
                }
            </p>
            <p>
                {
                    instrumentsProgress === null
                        ?   '0%  Getting progression information'
                        :   instrumentsProgress.percent + '%  ' + instrumentsProgress.status
                }
            </p>
        </>
    );

    return (
        <>
            {
                (notes === null || instruments === null)
                    ? loadingPage
                    : <KInstrumentsPage
                        tracks={notes.tracks}
                        totalLength={notes.totalLength}
                        instruments={instruments}
                    />
            }
        </>
    )
}
