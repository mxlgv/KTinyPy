#include "tp.h"
#include "syscalls.c"



#define EXPORT(MOD_NAME, F_NAME, F_POINT) tp_set(tp, MOD_NAME , tp_string(F_NAME), tp_fnc(tp, F_POINT))

extern tp_obj tp_dict(TP);
extern tp_obj tp_fnc(TP,tp_obj v(TP));


void kolibri_init(TP)
{
    tp_obj kolibri_mod = tp_dict(tp);

    EXPORT(kolibri_mod, "debug_print"  , _debug_print);
    EXPORT(kolibri_mod, "start_draw"   , _start_draw);
    EXPORT(kolibri_mod, "end_draw"     , _end_draw);
    EXPORT(kolibri_mod, "create_window", _create_window);
    EXPORT(kolibri_mod, "create_button", _create_button);
    EXPORT(kolibri_mod, "draw_text"    , _draw_text);
    EXPORT(kolibri_mod, "get_event"    , _get_event);
    EXPORT(kolibri_mod, "get_button"    ,_get_button);

    tp_set(tp, kolibri_mod, tp_string("__doc__"), tp_string("KolibriOS system specific functions."));
    tp_set(tp, kolibri_mod, tp_string("__name__"), tp_string("kolibri"));
    tp_set(tp, kolibri_mod, tp_string("__file__"), tp_string(__FILE__));

    tp_set(tp, tp->modules, tp_string("kolibri"), kolibri_mod);
}
