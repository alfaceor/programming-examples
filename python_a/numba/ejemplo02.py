#!/usr/bin/env python3

from numba import njit
import random

@njit
def observable_003(ps_scenario):
    v_choice = mdl.parms.get_Event_realization('v_choice', ps_scenario['v_choice'])
    v_3_del = mdl.parms.get_Event_realization('v_3_del', ps_scenario['v_3_del'])
    v_anchor = mdl.V_anchors.loc[v_choice.id]
    j_choice = mdl.parms['j_choice'].loc[ps_scenario['j_choice']]

    return len(v_choice.value) - v_anchor - v_3_del.value
