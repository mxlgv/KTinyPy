#include "tp.c"

extern void kolibri_init(tp_vm*);

const char header[]="TinyPy for kolibriOS";

void main(int argc, char *argv[]) {
    tp_vm *tp = tp_init(argc, argv);
    kolibri_init(tp);
    CONSOLE_INIT(header);
    /* INIT */
    tp_call(tp,"py2bc","tinypy",tp_None);
    con_printf("Done");
    tp_deinit(tp);
    kol_exit();
    return;
}

