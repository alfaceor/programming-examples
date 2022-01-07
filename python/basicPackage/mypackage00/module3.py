try:
    import importlib.resources as pkg_resources
except ImportError:
    # Try backported to PY<37 `importlib_resources`.
    import importlib_resources as pkg_resources

from . import templates  # relative-import the *package* containing the templates

template = pkg_resources.read_text(templates, 'temp_file')
# or for a file-like stream:
template = pkg_resources.open_text(templates, 'temp_file')


