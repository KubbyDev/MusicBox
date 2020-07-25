from flask import Flask, send_from_directory, jsonify, request
from Programs.Notes import from_midi
from Programs.Notes import processing
from Programs import jobmanager
from werkzeug import serving

# Initialisation --------------------------------------------------------------

port = 80
static_folder = 'webapp/build'

app = Flask(__name__, static_folder=static_folder, static_url_path='/')

pages=['', 'instrumentpicker', 'upload']
silentendpoints = ['/api/notes/progress', '/api/instruments/progress']

parent_log_request = serving.WSGIRequestHandler.log_request
def log_request(self, *args, **kwargs):
    if self.path in silentendpoints: return
    parent_log_request(self, *args, **kwargs)
serving.WSGIRequestHandler.log_request = log_request

# Pages -----------------------------------------------------------------------

for page in pages:
    app.add_url_rule(
        '/' + page,
        endpoint=page,
        view_func=lambda: app.send_static_file('index.html')
    )

# Static auxiliary files ------------------------------------------------------

@app.route('/<path:path>')
def send_file(path):
    return send_from_directory('.', path)

# API -------------------------------------------------------------------------

@app.route('/api/musicfile', methods=['POST'])
def musicfile():
    # Writes the music file to a temporary location in the server storage
    try:
        file = open('ServerStorage/MusicFile', 'wb+')
        file.write(request.data)
        file.close()
    except:
        return 'Error while updating the musicfile', 500
    # Launches the midi to notes conversion
    return from_midi.start_musicfile_conversion()

@app.route('/api/process', methods=['POST'])
def process():
    return processing.start_processing(request.get_json(force=True))

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

# -----------------------------------------------------------------------------

if __name__ == "__main__":
    app.run(port=port)
