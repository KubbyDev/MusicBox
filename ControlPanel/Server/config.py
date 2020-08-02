from os.path import join
import os

class Server:
    port = 80

class WebApp:
    pages = ['', 'instrumentpicker', 'upload', 'melodies']
    static_folder = 'webapp/build'

class API:
    silent_endpoints = ['/api/notes/progress', '/api/instruments/progress']

class Storage:
    _storage_folder = 'Server\\Storage'
    _cache_folder = 'cache'
    _melodies_folder = 'melodies'

    storage_location = _storage_folder + os.sep
    cache_folder = join(_storage_folder, _cache_folder) + os.sep
    melodies_folder = join(_storage_folder, _melodies_folder) + os.sep
