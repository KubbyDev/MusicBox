import threading
from Server.Processes.Tools import processes, postprocess, tools, progress as progress_functions
from Server.Processes import instruments_list
from Server.Processes.JobManager import jobmanager


_job_functions = [
    processes.move_octaves, # ID 0: Move octaves
]

def _do_job(job, results, rindex, progress, pindex):
    jobID = job['id']
    args = job['args']
    if jobID < 0 or jobID > len(_job_functions):
        raise Exception('Unknown job id %i' % jobID)
    for track in results[rindex]:
        _job_functions[jobID](track, args)
    progress[pindex] += 1

def _process(results, progress, args):
    _, jobs, selected = args
    tracks, totallength = args[0]['tracks'], args[0]['totalLength']
    # Puts the tracks in the results list to be processes
    for i in range(len(tracks)):
        results.append([])
        progress.append(0)
        tracks[i]['length'] = totallength
        results[i].append(tracks[i])
    # Calculates the number of selected tracks and adds the total progress
    nb_selected = 0
    for i in range(len(tracks)):
        if i in selected: nb_selected += 1
    progress.append(nb_selected*len(jobs))
    # Does one job at a time
    for job in jobs:
        progress_index = 0
        threads = []
        # Starts one thread for each track
        for i in range(len(tracks)):
            # If the track is not selected to be modified, does nothing
            if i not in selected: continue
            # If the track is selected, starts a thread to apply the current modification
            t = threading.Thread(target=_do_job, args=(
                job,
                results, i,
                progress, progress_index,
            ))
            threads.append(t)
            progress_index += 1
            t.start()
        # Waits for the threads to terminate
        tools.wait_for_threads(threads)

# Starts a track processing
def start_processing(jobs):
    try:
        jobmanager.launch_job(
            main=_process,
            args=(jobmanager.get_results('notes'), jobs['jobs'], jobs['selectedTracks']),
            name='notes',
            progress=progress_functions.from_numbers_fixed_status('Applying modifications'),
            postprocess=postprocess.notes,
            done=instruments_list.start_instruments_computation
        )
    except Exception as e:
        return str(e.args), 500
    return 'Started jobs'