import ast
import os

from Server import config


def _check_directory_traversal(path):
    cfg_real_path = os.path.realpath(config.Storage.storage_location)
    prefix = os.path.commonprefix((os.path.realpath(path), cfg_real_path))
    if prefix != cfg_real_path:
        raise Exception('Detected hacking attempt: ' + path)

# Reads a file and parses it into a dictionnary
# Returns None if the file doesn't exist
def read(path):
    _check_directory_traversal(path)
    if os.path.isfile(path):
        with open(path, 'r') as file:
            return ast.literal_eval(file.read())
    return None

# Writes a file from a python object
def write(path, obj):
    _check_directory_traversal(path)
    with open(path, 'w+') as file:
        file.write(str(obj))