import threading
from Server.Instruments.Instruments.stepper import Stepper
from Server import tools, jobmanager

# List of available instruments
_instruments = [Stepper(index=1), Stepper(index=2), Stepper(index=3)]


# Computes the requirements for all the tracks for this instrument
def _compute_instrument(results, index, instrument, tracks):
    res = None
    for track in tracks:
        res = instrument.requirements(track).build_for_instruments(res)
    res['name'] = instrument.name
    results[index] = res


# Computes a list that contains the instruments
# and the list of errors and warnings for each instrument
def _instruments_computation(results, progress, args):
    tracks = jobmanager.get_results('notes')['tracks']
    threads = []
    # Starts one thread for each instrument
    for i in range(len(_instruments)):
        results.append([])
        thread = threading.Thread(target=_compute_instrument, args=(
            results,
            i,
            _instruments[i],
            tracks
        ))
        threads.append(thread)
    # Starts the threads when the results list is fully formed to avoid race condition
    for t in threads: t.start()
    # Waits for all the threads to terminate
    tools.wait_for_threads(threads)


# Starts the computation of a list that contains the instruments
# and the list of errors and warnings for each instrument
def start_instruments_computation():
    try:
        jobmanager.launch_job(
            main=_instruments_computation,
            name='instruments',
            progress=None,
        )
    except Exception as e:
        return str(e.args), 500
    return 'Started instruments computation'