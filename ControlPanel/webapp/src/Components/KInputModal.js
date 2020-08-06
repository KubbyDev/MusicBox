import React from 'react';
import { Modal } from "react-bootstrap";
import TextField from "@material-ui/core/TextField";
import Button from "@material-ui/core/Button";

/*
    Opens a popup dialog.
    Parameters:
    - show: whether or not to show the dialog
    - setShow: REQUIRED: A function to set the show variable
    - title: The title
    - text: A text under the title
    - placeholder: A placeholder for the input
    - rules: a predicate that must be true in order for the save button to be enabled
    - alphanumeric: Adds a rule that forces the input to contain only [A-Za-z0-9]
    - canBeEmpty: Removes the rule that forces the input to be at least one character
    - doneTitle: The text on the done button
    - onDone: Callback function called when the user clicks on save. Takes the input as parameter
 */
export default function KInputModal(props) {

    const [value, setValue] = React.useState('');

    const show = props.show === undefined ? true : props.show;
    const setShow = props.setShow;
    const title = props.title;
    const text = props.text;
    const placeholder = props.placeholder === undefined ? '' : props.placeholder;
    const rules = props.rules === undefined ? () => true : props.rules;
    const alphanumeric = props.alphanumeric === undefined ? false : props.alphanumeric;
    const canBeEmpty = props.canBeEmpty === undefined ? () => false : props.canBeEmpty;
    const doneTitle = props.doneTitle === undefined ? 'Done' : props.doneTitle;
    const onDone = props.onDone === undefined ? () => {} : props.onDone;

    const alphanumericCheck = (input) => input.match(/^[0-9a-zA-Z]*$/);
    const emptyCheck = (input) => input.length > 0;

    const checkRules = () => {
        return (
            (canBeEmpty ? emptyCheck(value) : true) &&
            (alphanumeric ? alphanumericCheck(value) : true) &&
            rules(value)
        )
    }

    return (
        <Modal show={show} onHide={() => setShow(false)}>
            <Modal.Header closeButton>
                { title === undefined ? <></> : <Modal.Title>{title}</Modal.Title> }
            </Modal.Header>
            <Modal.Body>
                { text === undefined ? <></> : <p>{text}</p> }
                <TextField
                    onChange={(event) => setValue(event.target.value)}
                    placeholder={placeholder}
                    multiline
                    autoFocus
                />
            </Modal.Body>
            <Modal.Footer>
                <Button
                    onClick={() => {
                        setShow(false);
                        onDone(value)
                    }}
                    disabled={! checkRules()}
                >
                    {doneTitle}
                </Button>
            </Modal.Footer>
        </Modal>
    )
}