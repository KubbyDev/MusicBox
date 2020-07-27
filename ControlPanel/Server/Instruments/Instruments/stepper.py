from Server.Instruments.Instruments.instrument import Instrument
from Server.Instruments.Tools import requirements as reqTools

_min_pitch = 57
_max_pitch = 84


class Stepper(Instrument):
    def requirements(self, track):
        reqs = reqTools.Requirements(track)
        reqs.apply_checkers([
            reqTools.notes_range(_min_pitch, _max_pitch)
        ])
        return reqs
    def generate(self, notes):
        pass
    def transfer(self, data):
        pass

