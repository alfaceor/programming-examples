#!/usr/bin/python3


class IgorJob(batch, species=None, chain=None):
    """
    This class should encapsulate all
    the input parameters and output files when IGoR run.
    """
    def __init__(self):
        if batch is None:
            self._batch = "IGoRDefaultBatch"
        self._batch = batchname

        if species is None:
            self._species = "NoSpecies"
        self._species = species

        if chain is None:
            # assing a random batchname
            self._chain = "IGoRDefaultBatch"
        self._chain = chain

        self._exec_path = ""
        self.igor_datadir = ""
        self.igor_modelspath = ""

        self.igor_modeldirpath = ""

        self.igor_wd = ""

        self.igor_model_parms_file = ""
        self.igor_model_marginals_file = ""
        self.igor_read_seqs = ""
        self.igor_threads = ""

    @property
    def igor_batchname(self):




