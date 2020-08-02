import React from 'react';
import Button from "@material-ui/core/Button";
import {useHistory} from "react-router";

export default function KUploadPage(props) {

    const history = useHistory();
    let file = null;

    const upload = () => {
        fetch('/api/musicfile', {
            method: 'post',
            body: file,
        })
            .then(() => history.push('/instrumentpicker'))
            .catch(console.error);
    }

    return (
        <>
            <input type="file" name="file" onChange={(e) => file = e.target.files[0]}/>
            <Button onClick={upload}>Upload</Button>
        </>
    );
}