

class RcParams(dict):
    #validate = { key : converter
    #            for key, (default, converter) in defaultParams.items()}
    def __init__(self, *args, **kwargs):
        self.update(*args, **kwargs)

    def __setitem__(self, key, val):
        #try:
        #    cval = self.validate[key](val)
        #except ValueError as ve:
        #    raise ValueError(f"Key {key} : {ve}") from None
        dict.__setitem__(self, key, val)
    
    def __getitem__(self, key):
        return dict.__getitem__(self, key)
        

