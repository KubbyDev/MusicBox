class Instrument:
    def preprocess(self, notes):
        """
        Modifies a notes list to make it playable by the instrument

        :param notes: a list of notes
        :return: A new notes list that the instrument can play
        """
        pass
    def generate(self, notes):
        """
        Generates an object in the right format so that the instrument can directly use it
        The notes must be playable (they must have gone through the preprocess function)

        :param notes: a preprocessed list of notes
        :return: an object that can be sent directly to the instrument
        """
        pass
    def transfer(self, data):
        """
        Transfers the data to the right place so the instrument can access it

        :param data: a data object returned by the generate function
        """
        pass