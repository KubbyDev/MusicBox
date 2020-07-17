# This file contains general functions for the preprocessing part


def move_octaves(notes, octaves):
    """
    Moves the whole melody upwards by n octaves
    :param notes: list of notes
    :param octaves: number of octaves, can be negative
    """
    for n in notes:
        n.pitch += octaves * 12 # 12 not 8 because of the # notes