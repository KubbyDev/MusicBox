from Server.Instruments.instrument import Instrument
from Server.Processes.Tools import requirements as reqTools
from Server.Processes.Tools import generation as genTools


_min_pitch = 57
_max_pitch = 84

_delays = { # TODO: May be possible to replace by time periods
    0: 0,
    57: 4489,
    58: 4239,
    59: 4001,
    60: 3778,
    61: 3567,
    62: 3363,
    63: 3175,
    64: 2995,
    65: 2825,
    66: 2674,
    67: 2515,
    68: 2375,
    69: 2243,
    70: 2112,
    71: 1996,
    72: 1886,
    73: 1776,
    74: 1678,
    75: 1584,
    76: 1495,
    77: 1409,
    78: 1328,
    79: 1252,
    80: 1182,
    81: 1116,
    82: 1053,
    83: 993,
    84: 936,
}


class Stepper(Instrument):

    def requirements(self, track):
        reqs = reqTools.Requirements(track)
        reqs.apply_checkers([
            reqTools.notes_range(_min_pitch, _max_pitch)
        ])
        return reqs

    def generate(self, track):
        reqs = self.requirements(track)
        # Finds quick fixes if there are requirements to be satisfied
        if not reqs.empty(): reqs.fix()
        # Generates notes and times
        res = genTools.notes_and_times(track)
        for i in range(len(res['notes'])):
            res['notes'][i] = _delays[res['notes'][i]]
        return res

    def upload(self):
        pass

