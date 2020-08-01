import ast
import os

# Reads a file and parses it into a dictionnary
# Returns None if the file doesn't exist
def read(path):
    if os.path.isfile(path):
        with open(path, 'r') as file:
            return ast.literal_eval(file.read())
    return None

# Writes a file from a python object
def write(path, obj):
    with open(path, 'w+') as file:
        file.write(str(obj))