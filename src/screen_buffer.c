/*                                                                                                                                                                                                                 
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/      

#include "screen_buffer.h"
#include "init.h"

#define num_points(x) (IMAGE_WIDTH * IMAGE_HEIGHT * x)

/**
  * Create new empty screen buffer
  *
  */
point_t *new_screen_buffer() {
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
void show_screen_buffer(screen_buffer_t *image, WINDOW *win) {
    // Loop through points and display on window
    int i;
    for(i = 0; i < image->area; i++) {
        if(image->points[i].y > 0 && image->points[i].x > 0) {
            mvwaddch(win, image->points[i].y, image->points[i].x,
                     image->points[i].ch);
        }
    }
}
