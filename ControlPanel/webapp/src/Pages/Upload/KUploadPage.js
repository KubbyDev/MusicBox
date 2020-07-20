import React from 'react';

export default function KUploadPage(props) {

    const onChangeHandler = (e) => {
        fetch('/api/musicfile', {
            method: 'post',
            body: e.target.files[0],
        })
            .then(r => console.log(r))
            .catch(e => console.error(e));
    }

    return (
        <input type="file" name="file" onChange={onChangeHandler}/>
    );
}