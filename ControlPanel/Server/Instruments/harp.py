from music21.note import Note

from Server.Instruments.instrument import Instrument
from Server.Processes.Tools import requirements as reqTools
from Server.Processes.Tools import generation as genTools


_min_pitch = 24
_max_pitch = 108


class Harp(Instrument):

    def requirements(self, track):
        reqs = reqTools.Requirements(track)
        reqs.apply_checkers([
            reqTools.notes_range(_min_pitch, _max_pitch),
            # TODO: Notes too close
        ])
        return reqs

    def generate(self, track):
        reqs = self.requirements(track)
        # Finds quick fixes if there are requirements to be satisfied
        if not reqs.empty(): reqs.fix()
        # Generates notes and times
        return genTools.notes_and_times(track)

    def upload(self):
        pass