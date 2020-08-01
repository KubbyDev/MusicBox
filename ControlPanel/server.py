import os
from flask import Flask, send_from_directory, jsonify, request
from werkzeug import serving

from Server.Processes import generation, processing, from_midi
from Server.Processes.JobManager import jobmanager
from Server.Instruments.instrument import instruments_list
from Server import config

# Initialisation --------------------------------------------------------------

app = Flask(__name__, static_folder=config.WebApp.static_folder, static_url_path='/')

# Silent end points
silentendpoints = config.API.silent_endpoints
parent_log_request = serving.WSGIRequestHandler.log_request
def log_request(self, *args, **kwargs):
    if self.path in silentendpoints: return
    parent_log_request(self, *args, **kwargs)
serving.WSGIRequestHandler.log_request = log_request

# Adds an endpoint for each page because otherwise getting to these
# pages without going through the home page would generate a 404
for page in config.WebApp.pages:
    app.add_url_rule(
        '/' + page,
        endpoint=page,
        view_func=lambda: app.send_static_file('index.html')
    )

# Server storage folder structure
for folder in [config.Storage.cache_folder, config.Storage.melodies_folder]:
    try: os.makedirs(folder)
    except: pass

# Static auxiliary files ------------------------------------------------------

@app.route('/<path:path>')
def send_file(path):
    return send_from_directory('.', path)

# API -------------------------------------------------------------------------

# Notes generation

@app.route('/api/musicfile', methods=['POST'])
def musicfile():
    # Writes the music file to a temporary location in the server storage
    try:
        file = open(config.Storage.cache_folder + 'musicfile', 'wb+')
        file.write(request.data)
        file.close()
    except:
        return 'Error while updating the musicfile', 500
    # Launches the midi to notes conversion
    return from_midi.start_musicfile_conversion()

@app.route('/api/process', methods=['POST'])
def process():
    return processing.start_processing(request.get_json(force=True))

# Getters

@app.route('/api/notes')
def notes():
    return jsonify(jobmanager.get_results('notes'))

@app.route('/api/notes/progress')
def notes_progress():
    return jsonify(jobmanager.get_progress('notes'))

@app.route('/api/instruments')
def instruments():
    return jsonify(jobmanager.get_results('instruments'))

@app.route('/api/instruments/progress')
def instruments_progress():
    return jsonify(jobmanager.get_progress('instruments'))

# Generation and playing

@app.route('/api/generate', methods=['POST'])
def generate():
    return generation.start(request.get_json(force=True))

@app.route('/api/code/<melody>/<instrument>') # TODO: Security
def get_code(melody, instrument):
    for inst in instruments_list:
        if inst.name == instrument:
            res = inst.get_code(melody)
            if not isinstance(res, tuple): return jsonify(res)
            else: return jsonify(res[0]), res[1]
    return jsonify("Instrument " + instrument + " not found"), 500

# -----------------------------------------------------------------------------

if __name__ == "__main__":
    app.run(port=config.Server.port)
