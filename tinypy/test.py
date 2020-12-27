import kolibri

my_button=2
exit_button=1

def redraw():
    kolibri.start_draw()
    kolibri.create_window(10, 40, 400, 200, "My window", 0xffffff, 0x14)
    kolibri.draw_text("Python example", 15, 34, 14, 0x90000000)
    kolibri.create_button(10, 50, 20, 50, my_button, 0x177245)
    kolibri.end_draw()

if __name__=="__main__":
  kolibri.debug_print("Debug test line\n")
  while True:
    gui_event = kolibri.get_event()
    if gui_event == 1:
        redraw()
    if get_event == 3:
        button_id = kolibri.get_button()
        if button_id == exit_button:
            break;
        if get_event == my_button:
            kolibri.debug_print("Clicked 'MyButton'\n")
            redraw()

    
  
