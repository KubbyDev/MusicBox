import React from 'react';
import KMelodiesPage from "./KMelodiesPage";

export default function KMelodiesPageLoader(props) {

    // This parameter allow to skip the generation progress screen
    const directLoad = props.location.state === undefined ? true : props.location.state;

    let [melodies, setMelodies] = React.useState(null);
    let [genProgress, setGenProgress] = React.useState(null);
    let [loadingData, setLoadingData] = React.useState(false);

    const getProgress = () => {
        fetch('/api/generation/progress')
            .then(res => res.json())
            .then(res => {
                setGenProgress(res)
                if (res.done) loadMelodiesPage()
                else getProgress();
            })
            .catch(console.error);
    }

    const loadMelodiesPage = () => {
        setLoadingData(true);
        fetch('/api/melodies')
            .then(res => res.json())
            .then(res => setMelodies(res))
            .catch(console.error);
    }

    if(genProgress === null && !directLoad) getProgress();
    if(directLoad && !loadingData) loadMelodiesPage();

    const computingPage = (
        <>
            <p>Waiting for the computation to end...</p>
            <p>
                {
                    genProgress === null
                        ?   '0%  Waiting for the server'
                        :   genProgress.percent + '%  ' + genProgress.status
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
                melodies === null
                    ? (loadingData ? loadingPage : computingPage)
                    : <KMelodiesPage
                        melodies={melodies}
                    />
            }
        </>
    )
}
