/*                                                                                              
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>

WINDOW *create_window(short height, short width, short begin_y, short begin_x, 
                      const bool BORDER);
void delete_window(WINDOW *win);
#endif
