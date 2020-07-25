from sortedcontainers import SortedList


def move_octaves(track, octaves):
    """
    Moves the track and all its notes upwards by n octaves
    :param track: track dict (notes in the 'notes' list)
    :param octaves: number of octaves, can be negative
    """
    offset = octaves * 12 # 12 not 8 because of the # notes
    for n in track['notes']:
        n['pitch'] += offset
    track['lowest'] += offset
    track['highest'] += offset
    return track


# Merges two list of notes (start, end, pitch). Makes sure the notes are ordered by starting time
def merge(tracks):
    sl = SortedList(key=lambda n: n[0]) # Sorts by start time
    for track in tracks:
        sl.update(track)
    return sl[:]

