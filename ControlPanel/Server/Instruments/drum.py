from Server.Instruments.instrument import Instrument
from Server.Processes.Tools import requirements as reqTools


class Drum(Instrument):
    def requirements(self, track):
        reqs = reqTools.Requirements(track)
        return reqs
    def generate(self, track):
        pass
    def upload(self):
        pass
