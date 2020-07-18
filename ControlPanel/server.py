from flask import Flask, send_from_directory

app = Flask(__name__, static_folder='webapp/build', static_url_path='/')

# Pages
pages=['', 'instrumentpicker']
for page in pages:
    app.add_url_rule(
        '/' + page,
        endpoint=page,
        view_func=lambda: app.send_static_file('index.html')
    )

# Static auxiliary files
@app.route('/<path:path>')
def send_file(path):
    return send_from_directory('.', path)

if __name__ == "__main__":
    app.run(port=80)