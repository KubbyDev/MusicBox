import React from 'react';
import KInstrumentsPage from "./KInstrumentsPage";

export default function KInstrumentsPageLoader(props) {

    // This parameter allow to skip the computing progress screen
    const directLoad = props.location.state === undefined ? true : props.location.state;

    let [notes, setNotes] = React.useState(null);
    let [instruments, setInstruments] = React.useState(null);
    let [notesProgress, setNotesProgress] = React.useState(null);
    let [instrumentsProgress, setInstrumentsProgress] = React.useState(null);
    let [loadingData, setLoadingData] = React.useState(false);

    const getNotesProgress = () => {
        fetch('/api/notes/progress')
            .then(res => res.json())
            .then(res => {
                setNotesProgress(res);
                if (res.done) getInstrumentsProgress();
                else getNotesProgress();
            })
            .catch(console.error);
    }

    const getInstrumentsProgress = () => {
        fetch('/api/instruments/progress')
            .then(res => res.json())
            .then(res => {
                setInstrumentsProgress(res)
                if (res.done) loadInstrumentsPage()
                else getInstrumentsProgress();
            })
            .catch(console.error);
    }

    const loadInstrumentsPage = () => {
        setLoadingData(true);
        fetch('/api/notes')
            .then(res => res.json())
            .then(res => setNotes(res))
            .catch(console.error);
        fetch('/api/instruments')
            .then(res => res.json())
            .then(res => setInstruments(res))
            .catch(console.error);
    }

    if(notesProgress === null && !directLoad) getNotesProgress();
    if(directLoad && !loadingData) loadInstrumentsPage();

    const computingPage = (
        <>
            <p>Waiting for the computation to end...</p>
            <p>
                {
                    notesProgress === null
                        ?   '0%  Waiting for the server'
                        :   notesProgress.percent + '%  ' + notesProgress.status
                }
            </p>
            <p>
                {
                    instrumentsProgress === null
                        ?   '0%  Waiting for the server'
                        :   instrumentsProgress.percent + '%  ' + instrumentsProgress.status
                }
            </p>
        </>
    );

    const loadingPage = (
      <>
          <p>Loading data...</p>
      </>
    );

    return (
        <>
            {
                (notes === null || instruments === null)
                    ? (loadingData ? loadingPage : computingPage)
                    : <KInstrumentsPage
                        tracks={notes.tracks}
                        totalLength={notes.totalLength}
                        instruments={instruments}
                    />
            }
        </>
    )
}
