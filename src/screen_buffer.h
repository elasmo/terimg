/*                                                                                                                                      
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/      

#ifndef SCREEN_BUFFER_H
#define SCREEN_BUFFER_H

#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Point (x, y) definition
typedef struct {
    short x;
    short y;
    short fg;
    short bg;
    chtype ch;
} point_t;

// Screen buffer definition
typedef struct {
    point_t *points;
    unsigned int file_version;
    unsigned int width;
    unsigned int height;
    unsigned int area;
    chtype current_char;
    unsigned int fg;
    unsigned int bg;
    unsigned int cursor_x;
    unsigned int cursor_y;
    unsigned int buffer_modified;
    //short color_pairs; woot?
} screen_buffer_t;

point_t *new_screen_buffer();
void show_screen_buffer(screen_buffer_t *image, WINDOW *win);

#endif
