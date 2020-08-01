
# Takes a list of lists of track dicts containing name, highest, lowest, length and notes properties
# And combines them in a single dict ready to be sent back to the client
def notes(results):
    total_length = 0
    tracks = []
    for thread in results:
        for track in thread:
            length = track.pop('length')
            if length > total_length: total_length = length
            tracks.append(track)
    return {'tracks': tracks, 'totalLength': total_length}