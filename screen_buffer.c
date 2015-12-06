/*                                                                                                                                                                                                                 
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/      

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Point (x,y) definition
typedef struct {
    short x;
    short y;
    short fg;
    short bg; // XXX: See notes on fileformat in file.c
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
} point_t;

/**
  * Create new empty screen buffer
  *
  */
point_t *new_screen_buffer(int num_points) {
    size_t bytes;
    point_t *points;

    bytes = num_points(sizeof(point_t));
    points = malloc(bytes);

    if(points == NULL) {
        fprintf(stderr, "Unable to create new screen buffer: Memory error.\n");
        exit(EXIT_FAILURE);
    }

    memset(points, 0, bytes);

    return points;
}

/**
  * Display screen buffer 
  *
  */
void show_screen_buffer(WINDOW *win, screen_buffer_t *screen) {
    // Loop through points and display on window
}
