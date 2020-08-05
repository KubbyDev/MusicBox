import threading

from Server import config, storage
from Server.Processes.JobManager import jobmanager
from Server.Processes.Tools import tools, progress as progress_functions
from Server.Instruments.available import instruments_list


def _generate_for_instrument(results, rindex, progress, pindex, instrument, track):
    results[rindex] = instrument.generate(track)
    progress[pindex] = True


def _generate(results, progress, settings):
    tracks = jobmanager.get_results('notes')['tracks']
    threads = []
    index = 0
    # Starts one thread for each selected instrument
    for i in range(len(instruments_list)):
        results.append([])
        instrument = instruments_list[i]
        # If the instrument hasn't been selected, does nothing
        if instrument.name in settings.keys():
            progress.append(False)
            index += 1
            thread = threading.Thread(target=_generate_for_instrument, args=(
                results, i,
                progress, index,
                instrument,
                tracks[settings[instrument.name]],
            ))
            threads.append(thread)
    # Starts the threads when the results list is fully formed to avoid race condition
    for t in threads: t.start()
    # Waits for all the threads to terminate
    tools.wait_for_threads(threads)


def _post_process_function(melodyName):
    def _post_process(results):
        res = {}
        for i in range(len(instruments_list)):
            if results[i]:
                res.update({instruments_list[i].name: results[i]})
        storage.write(config.Storage.melodies_folder + melodyName, res)
    return _post_process


# Starts the computation of the data that will be fed directly to the instruments
# Settings is a dict: {instrumentName: trackIndex, instrumentName: trackIndex}
def start(melodyName, settings):
    try:
        jobmanager.launch_job(
            main=_generate,
            args=settings,
            name='generation',
            progress=progress_functions.from_boolean_fixed_status('Generating instrument code'),
            postprocess=_post_process_function(melodyName)
        )
    except Exception as e:
        return str(e.args), 500
    return 'Started generation'
