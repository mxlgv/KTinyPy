#include "tinypy.c"

extern void init_std_modules(TP);

int main(int argc, char *argv[]) {
    tp_vm *tp = tp_init(argc,argv);
    init_std_modules(tp);
    tp_ez_call(tp,"py2bc","tinypy",tp_None);
    tp_deinit(tp);
    return(0);
}

