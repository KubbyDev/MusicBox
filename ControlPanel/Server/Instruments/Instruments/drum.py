from Server.Instruments.Instruments.instrument import Instrument
from Server.Instruments.Tools import requirements as reqTools


class Drum(Instrument):
    def requirements(self, track):
        reqs = reqTools.Requirements(track)
        return reqs
    def generate(self, track):
        pass
    def upload(self):
        pass
    def get_code(self, melody):
        pass