import threading
from Programs import jobmanager, tools as programtools
from Programs.Notes.Tools import tools
from Programs.Notes.Tools import preprocess


_job_functions = [
    preprocess.move_octaves, # ID 0: Move octaves
]


def _do_job(job, results, index):
    jobID = job['id']
    args = job['args']
    if jobID < 0 or jobID > len(_job_functions):
        raise Exception('Unknown job id %i' % jobID)
    for track in results[index]:
        _job_functions[jobID](track, args)


def _process(results, progress, args):
    _, jobs, selected = args
    tracks, totallength = args[0]['tracks'], args[0]['totalLength']
    # Puts the tracks in the results list to be processes
    for i in range(len(tracks)):
        results.append([])
        tracks[i]['length'] = totallength
        results[i].append(tracks[i])
    # Does one job at a time
    for job in jobs:
        threads = []
        # Starts one thread for each track
        for i in range(len(tracks)):
            # If the track is not selected to be modified, does nothing
            if i not in selected: continue
            # If the track is selected, starts a thread to apply all the modifications sequencially
            t = threading.Thread(target=_do_job, args=(job, results, i))
            threads.append(t)
            t.start()
        # Waits for the threads to terminate
        programtools.wait_for_threads(threads)


# Starts a track processing
def start_processing(jobs):
    try:
        jobmanager.launch_job(
            main=_process,
            args=(jobmanager.get_results('notes'), jobs['jobs'], jobs['selectedTracks']),
            name='notes',
            progress=None,
            postprocess=tools.post_process
        )
    except Exception as e:
        return str(e.args), 500
    return 'Started jobs'