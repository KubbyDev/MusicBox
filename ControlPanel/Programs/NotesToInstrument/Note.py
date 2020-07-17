
class Note:
    def __init__(self, startMs, endMs, pitch):
        """
        Creates a note object
        :param startMs: moment when the note start from the beginning of the song (milliseconds)
        :param endMs: moment when the note start from the beginning of the song (milliseconds)
        :param pitch: pitch of the note, as in MIDI files
        """
        self.start = startMs
        self.end = endMs
        self.pitch = pitch