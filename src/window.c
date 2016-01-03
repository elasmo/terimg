/*                                                                                              
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

#include <curses.h>

/**
  * Create a window
  *
  */
WINDOW *create_window(short height, short width, short begin_y, short begin_x, 
                      const bool BORDER) {
    WINDOW *win = newwin(height, width, begin_y, begin_x);

    if(BORDER)
        box(win, ACS_VLINE, ACS_HLINE);

    return win;
}

/**
  * Delete a window
  *
  */
void delete_window(WINDOW *win) {
    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    werase(win);
    wrefresh(win);
    delwin(win);
}
