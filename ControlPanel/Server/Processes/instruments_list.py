import threading
from Server.Processes.Tools import tools, progress as progress_functions
from Server.Processes.JobManager import jobmanager
from Server.Instruments.available import instruments_list


# Computes the requirements for all the tracks for this instrument
def _compute_instrument(results, progress, index, instrument, tracks):
    res = None
    for track in tracks:
        res = instrument.requirements(track).build_for_instruments(res)
    res['name'] = instrument.name
    results[index] = res
    progress[index] = True


# Computes a list that contains the instruments
# and the list of errors and warnings for each instrument
def _instruments_computation(results, progress, args):
    tracks = jobmanager.get_results('notes')['tracks']
    threads = []
    # Starts one thread for each instrument
    for i in range(len(instruments_list)):
        results.append([])
        progress.append(False)
        thread = threading.Thread(target=_compute_instrument, args=(
            results, progress, i,
            instruments_list[i],
            tracks,
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
            progress=progress_functions.from_boolean_fixed_status('Collecting instruments requirements'),
        )
    except Exception as e:
        return str(e.args), 500
    return 'Started instruments computation'