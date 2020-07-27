import math


# Useful class to build a requirements dictionnary
class Requirements:
    def __init__(self, track):
        self.warnings, self.errors = [], []
        self.track = track
    # Builds the requirements list in the right format for the instruments request
    # (Adds these requirements to an already existing dictionnary if provided)
    def build_for_instruments(self, current=None):
        res = current if current else {'warnings':[], 'errors':[]}
        for reqType in ['warnings', 'errors']:
            for req in self.__getattribute__(reqType):
                res[reqType].append(req)
        return res
    # Applies requirement checkers to check them
    def apply_checkers(self, checkers):
        for checker in checkers:
            checkID, warnings, errors = checker(self.track)
            for error in (warnings + errors):
                error['track'] = self.track['name']
                error['id'] = checkID
            for w in warnings: self.warnings.append(w)
            for e in errors: self.errors.append(e)


# Checkers --------------------------------------------------------------------
# Checkers are functions that take a track (full dictionnary) and return
# a list of errors and a list of warnings in a tuple (both can be empty)


NOTES_RANGE_CHECK = 1
def notes_range(minNote, maxNote):
    # Checks if the notes are in the range of the instrument. If not, tries to move the notes
    # by some amount of octaves and returns a warning. If it is not possible, returns an error
    # The return value is a tuple (CheckID, Warnings, Errors)
    # Arguments for this check are the min and max notes of the instrument
    def check_notes_range(track):
        trMin = track['lowest']
        trMax = track['highest']
        args = {'min':minNote,'max':maxNote}
        err = {'message':"Can't fit in instrument range", 'args':args}
        warn = {'message':"Not in instrument range (can fit)", 'args':args}
        if trMin < minNote:
            movement = math.ceil((minNote - trMin)/12)
            if trMax + 12*movement > maxNote:
                return NOTES_RANGE_CHECK, [], [err]
            return NOTES_RANGE_CHECK, [warn], []
        elif trMax > maxNote:
            movement = math.ceil((trMax - maxNote)/12)
            if trMin - 12*movement < minNote:
                return NOTES_RANGE_CHECK, [], [err]
            return NOTES_RANGE_CHECK, [warn], []
        else:
            return NOTES_RANGE_CHECK, [], []
    return check_notes_range
