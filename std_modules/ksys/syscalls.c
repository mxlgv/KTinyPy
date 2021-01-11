#include "tinypy.h"
#include <kos32sys.h>

#define GET_NUM_ARG() TP_TYPE(TP_NUMBER).number.val
#define GET_STR_ARG() TP_TYPE(TP_STRING).string.val

void debug_write_byte(const char ch){
    __asm__ __volatile__(
    "int $0x40"
    ::"a"(63), "b"(1), "c"(ch)
    );
}

static tp_obj _debug_print(TP){
    tp_obj str = TP_TYPE(TP_STRING);
    for(int i=0; i < str.string.len; i++)
    {
       debug_write_byte(str.string.val[i]); 
    }
    return tp_None;
} 

static tp_obj _start_draw(TP){
    begin_draw();
    return tp_None;
}


static tp_obj _end_draw(TP){
    end_draw();
    return tp_None;
}

static tp_obj _create_window(TP){
    int x = GET_NUM_ARG();
    int y = GET_NUM_ARG();
    int w = GET_NUM_ARG(); 
    int h = GET_NUM_ARG();
    const char *title= GET_STR_ARG();
    unsigned int color = GET_NUM_ARG();
    unsigned int style = GET_NUM_ARG();
    sys_create_window(x,y,w,h, title, color,style);
    return tp_None;
} 

static tp_obj _create_button(TP){
    unsigned int x = GET_NUM_ARG();
    unsigned int y = GET_NUM_ARG();
    unsigned int h = GET_NUM_ARG();
    unsigned int w = GET_NUM_ARG();
    unsigned int id = GET_NUM_ARG();
    unsigned int color = GET_NUM_ARG();
    define_button((x << 16) + w, (y << 16) + h, id, color);
    return tp_None;
}

static tp_obj _draw_text(TP){
    const char *str= GET_STR_ARG();
    int x = GET_NUM_ARG();
    int y = GET_NUM_ARG();
    int len = GET_NUM_ARG(); 
    unsigned int color = GET_NUM_ARG();
    draw_text_sys(str, x, y, len, color);
    return tp_None;
}

static tp_obj _get_event(TP){
    return tp_number(get_os_event());
}

static tp_obj _get_button(TP){
    return tp_number(get_os_button());
}
