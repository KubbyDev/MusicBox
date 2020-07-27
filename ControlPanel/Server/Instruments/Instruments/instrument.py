
class Instrument:
    def __init__(self, name=None, index=None):
        if name: self.name = name
        elif index: self.name = type(self).__name__ + str(index)
        else: self.name = type(self).__name__
    def requirements(self, notes):
        """
        Lists the modifications to make to a notes list to make it playable by the instrument

        :param notes: a list of notes
        :return: a Requirements object containing the list of warnings and errors
        """
        raise NotImplementedError()
    def generate(self, notes):
        """
        Generates an object in the right format so that the instrument can directly use it.

        :param notes: a preprocessed list of notes
        :return: an object that can be sent directly to the instrument
        """
        raise NotImplementedError()
    def transfer(self, data):
        """
        Transfers the data to the right place so the instrument can access it

        :param data: a data object returned by the generate function
        """
        raise NotImplementedError()