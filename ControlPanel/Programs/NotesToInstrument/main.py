import threading
from Programs.NotesToInstrument.Instruments.drum import Drum
from Programs.NotesToInstrument.Instruments.harp import Harp
from Programs.NotesToInstrument.Instruments.stepper import Stepper
from Programs.NotesToInstrument.Instruments.tesla import Tesla
from Programs.NotesToInstrument.Instruments.whistle import Whistle
from Programs import tools
from Programs.MidiToNotes import main as miditonotes


# List of available instruments
_instruments = [Stepper(index=1), Stepper(index=2), Stepper(index=3)]
# True until the instruments computation is done
_working = False
# Stores the last instruments computation results
instruments_results = []


# Computes the requirements for all the tracks for this instrument
def _compute_instrument(results, index, instrument, tracks):
    res = None
    for track in tracks:
        res = instrument.requirements(track).build_for_instruments(res)
    res['name'] = instrument.name
    results[index] = res


# Computes a list that contains the instruments
# and the list of errors and warnings for each instrument
def _instruments_computation():
    global instruments_results
    global _working
    results = []
    threads = []
    # Starts one thread for each instrument
    for i in range(len(_instruments)):
        results.append([])
        thread = threading.Thread(target=_compute_instrument, args=(
            results,
            i,
            _instruments[i],
            miditonotes.conversion_results['tracks']
        ))
        thread.start()
        threads.append(thread)
    # Waits for all the threads to terminate
    tools.wait_for_threads(threads)
    # Finishes the calculation
    instruments_results = results
    _working = False

# Starts the computation of a list that contains the instruments
# and the list of errors and warnings for each instrument
def start_instruments_computation():
    global _working
    if _working:
        return 'A computation is already running', 500
    _working = True
    threading.Thread(target=_instruments_computation).start()
    return 'Started instruments computation'


# Gives a rough progression percentage and a status message
def get_progression():
    if _working: return {'percent': 50, 'status':'Computing...'}
    else: return {'percent': 100, 'status':'Done'}