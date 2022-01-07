#!/usr/bin/env python3

class IgorRec_Event:
    """Recombination event class containing event's name, type, realizations,
    etc... Similar to IGoR's C++ RecEvent class.
    """

    def __init__(self, event_type, seq_type, seq_side, priority,
                 nickname):

        self._pd_realizations = None

    @property
    def pd_realizations(self):
        return self._pd_realizations

    @pd_realizations.setter
    def pd_realizations(self, value):
        self.update_realizations_from_dataframe(value)
        self._pd_realizations = self.get_realization_DataFrame()

    @pd_realizations.deleter
    def pd_realizations(self):
        del self._pd_realizations
