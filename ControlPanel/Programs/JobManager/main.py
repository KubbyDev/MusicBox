import threading
import Programs.tools as tools
import os


# Static values
_default_progress_function = lambda pro: {'percent':50,'status':'In progress'}
_progress_done = {'percent':100,'status':'Done'}

# Is a job currently running ?
_working = False

# Current job information
_progress_function = _default_progress_function
_results = None
_progress = None
_job_name = None


def launch_job(main,
               args=None,
               name='Job',
               progress=None,
               postprocess=None,
               done=None):
    """
    Starts an async job

    :param main: function that will be ran by the job. Takes a results list and a progress list in parameters.
    The results list is the one that will be returned by the get_results function. The progress list is optionnal and
    can be used for the progress_function (parameter below)
    :param args: arguments for the main function
    :param name: name of the job. Can be used to refer to that job in the get_progress and get_results functions
    :param progress: a function that takes the progress list from the job_main and returns progress info.
    :param postprocess: a function that will be ran when the job has finished. Takes the results as a parameter
    and returns the postprocessed version of the results.
    :param done: a function that will be called when the job is done
    :return: Nothing. Can raise errors
    """
    global _working
    global _job_name
    # Throws if there is a job running
    if _working: raise Exception('A job is already running')
    # Officially starts the job
    _working = True
    _job_name = name
    # Job control function, started in a thread below
    def control_function():
        global _working
        global _results
        global _progress
        global _progress_function
        _results = []
        _progress = []
        _progress_function = progress if progress else _default_progress_function
        # Starts the job
        workingthread = threading.Thread(target=main, args=(_results, _progress, args))
        workingthread.start()
        # Waits for the job to finish
        tools.wait_for_threads([workingthread], 10)
        # Saves the results and the last progress
        with open('ServerStorage/' + name + '/Results', 'w+') as file:
            file.write(str(_results))
        with open('ServerStorage/' + name + '/Progress', 'w+') as file:
            file.write(str(_progress_function(_progress) if progress else _progress_done))
        # Runs the post process function
        if postprocess is not None:
            _results = postprocess(_results)
        # Stops the job and calls the done function
        _working = False
        if done is not None: done()
    threading.Thread(target=control_function()).start()


# Returns the return value of the progress function or its last return value
# The return value of this function is always the string representation of the data
def get_progress(job_name='Job'):
    # If the queried job is currently running, calls the function directly
    if _working and _job_name == job_name: return str(_progress_function(_progress))
    # If it is another job, returns the last progress of the queried job if available
    if os.path.isfile('ServerStorage/'+job_name+'/Progress'):
        with open('ServerStorage/'+job_name+'/Progress', 'r') as file:
            return file.read()
    # If it is not available, throws an error
    else: raise Exception('Unknown job')


# Returns the current value of the results array
# The return value of this function is always the string representation of the data
def get_results(job_name='Job'):
    # If the queried job is currently running, returns the results directly
    if _working and _job_name == job_name: return str(_results)
    # If it is another job, returns the results of the queried job if available
    if os.path.isfile('ServerStorage/'+job_name+'/Results'):
        with open('ServerStorage/'+job_name+'/Results', 'r') as file:
            return file.read()
    # If it is not available, throws an error
    else: raise Exception('Unknown job')