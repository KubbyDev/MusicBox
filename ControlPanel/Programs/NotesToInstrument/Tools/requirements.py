import math


# Useful class to build a requirements dictionnary
class Requirements:
    def __init__(self, track):
        self.errors, self.warnings = [], []
        self.track = track
    # Builds the requirements list in the right format for the instruments request
    # (Adds these requirements to an already existing dictionnary if provided)
    def build_for_instruments(self, current=None):
        res = current if current else {'errors':[], 'warnings':[]}
        for reqType in ['errors', 'warnings']:
            for req in self.__getattribute__(reqType):
                res[reqType].append({'track':self.track['name'],'message':req})
        return res
    # Applies requirement checkers to check them
    def apply_checkers(self, checkers):
        for checker in checkers:
            err, warn = checker(self.track)
            for e in err: self.errors.append(e)
            for w in warn: self.warnings.append(w)

# Checkers --------------------------------------------------------------------
# Checkers are functions that take a track (full dictionnary) and return
# a list of errors and a list of warnings in a tuple (both can be empty)

# Checks if the notes are in the range of the instrument. If not, tries to move the notes
# by some amount of octaves and raises a warning. If it is not possible, raises an error
def notes_range(minNote, maxNote):
    def check_notes_range(track):
        trMin = track['lowest']
        trMax = track['highest']
        if trMin < minNote:
            movement = math.ceil((minNote - trMin)/12)
            if trMax + 12*movement > maxNote:
                return ['Range too wide'],[]
            return [],['Moves up by %i octaves' % movement]
        elif trMax > maxNote:
            movement = math.ceil((trMax - maxNote)/12)
            if trMin - 12*movement < minNote:
                return ['Range too wide'],[]
            return [], ['Moves down by %i octaves' % movement]
        else:
            return [],[]
    return check_notes_range
