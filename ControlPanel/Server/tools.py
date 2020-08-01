import time
from music21.pitch import Pitch


# Waits until all the threads are terminated
# Checks every intervalMs milliseconds
def wait_for_threads(threads, intervalMs=100):
    while True:
        done = True
        for t in threads:
            if t.is_alive():
                done = False
        if done:
            break
        time.sleep(intervalMs/1000)


def midi_to_name(midi):
    return Pitch(midi).nameWithOctave