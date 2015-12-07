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
    short file_version;
    short width;
    short height;
    int area;
    chtype current_char;
    short current_color_pair;
    short cursor_x;
    short cursor y;
    bool buffer_modified;
    short color_pairs;
} screen_buffer_t;

point_t *new_screen_buffer(int num_points);
void show_screen_buffer(WINDOW *win, screen_buffer_t *screen);

#endif
