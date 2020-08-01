import os
import ast

from Server import config
from Server.Instruments.Instruments.instrument import Instrument
from Server.Instruments.Tools import requirements as reqTools
from Server.Instruments.Tools import generation as genTools


_min_pitch = 57
_max_pitch = 84


class Stepper(Instrument):
    def requirements(self, track):
        reqs = reqTools.Requirements(track)
        reqs.apply_checkers([
            reqTools.notes_range(_min_pitch, _max_pitch)
        ])
        return reqs
    def generate(self, track):
        reqs = self.requirements(track)
        # If there is requirements to be satisfied
        if reqs:
            # Hard fix requirements
            raise Exception('There are still requirements')
        # Generates notes and times
        return genTools.notes_and_times(track)
    def upload(self):
        pass
    def get_code(self, melody):
        if not os.path.isfile(config.Storage.melodies_folder + 'melody'):
            return 'Could not find melody ' + melody, 500
        with open(config.Storage.melodies_folder + melody, 'r') as file:
            data = ast.literal_eval(file.read())
        generated = data.get(self.name)
        return "const PROGMEM uint16_t notes{}[] = {{\n" \
               "    {}\n" \
               "}};" \
            .format(self.name, ','.join(map(lambda x: str(x), generated['notes']))) \
             + "const PROGMEM uint32_t times{}[] = {{\n" \
               "    {}\n" \
               "}};" \
            .format(self.name, ','.join(map(lambda x: str(x), generated['times'])))

