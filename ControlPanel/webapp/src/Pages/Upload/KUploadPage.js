import React from 'react';
import Button from "@material-ui/core/Button";

export default function KUploadPage(props) {

    let file = null;

    const upload = () => {
        fetch('/api/musicfile', {
            method: 'post',
            body: file,
        }).catch(console.error);
    }

    return (
        <>
            <input type="file" name="file" onChange={(e) => file = e.target.files[0]}/>
            <Button onClick={upload}>Upload</Button>
        </>
    );
}