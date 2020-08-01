
class Instrument:
    def __init__(self, name=None, index=None):
        if name: self.name = name
        elif index: self.name = type(self).__name__ + str(index)
        else: self.name = type(self).__name__
    def requirements(self, track):
        """
        Lists the modifications to make to a notes list to make it playable by the instrument

        :param track: a list of note dicts
        :return: a Requirements object containing the list of warnings and errors
        """
        raise NotImplementedError()
    def generate(self, track):
        """
        Generates an object in the right format so that the instrument can directly use it.

        :param track: a full track dict
        :return: an object that can be sent directly to the instrument
        """
        raise NotImplementedError()
    def upload(self):
        """
        Transfers the generated notes to the right place so the instrument can access it
        """
        raise NotImplementedError()
    def get_code(self, melody):
        """
        Returns the c++ code for this instrument for the given melody. Can be put
        directly in an instrument specific arduino sketch.

        :param melody: The name of the desired melody
        """
        raise NotImplementedError()