from os.path import join

class Server:
    port = 80

class WebApp:
    pages = ['', 'instrumentpicker', 'upload']
    static_folder = 'webapp/build'

class API:
    silent_endpoints = ['/api/notes/progress', '/api/instruments/progress']

class Storage:
    _storage_folder = 'ServerStorage'
    _cache_folder = 'cache'

    storage_location = _storage_folder + '/'
    cache_folder = join(_storage_folder, _cache_folder) + '/'