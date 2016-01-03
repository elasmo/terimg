/*                                                                              
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/      

#ifndef INIT_H
#define INIT_H

#include <curses.h>
#include <errno.h>
#include "screen_buffer.h"

#define MAX_HEIGHT      20
#define MAX_WIDTH       75
#define IMAGE_HEIGHT    20
#define IMAGE_WIDTH     75

#define BORDER_BEGIN_Y 1
#define BORDER_BEGIN_X 1

void init_curses();
void init_colors();
WINDOW *create_screen_buffer_window();
void init_screen_buffer(screen_buffer_t *screen_buffer);

#endif
