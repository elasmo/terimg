/*                                                                                                       
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

#include "edit.h"

/**
 * Delete content at the current screen buffer position
 *
 */
void delete_point(screen_buffer_t *image, int pos) {
    /*
       1. Make sure the current buffer position is within the screen buffer
          (This should never happen. Is it even a possible bug?
	   Check maybe uneeded)
       2. Set y,x, fg, bg, ch to 0 on current buffer position
       3. Set a variable to indicate that the screen buffer is modified
     */
    image->points[pos].y = 0;
    image->points[pos].x = 0;
    image->points[pos].fg = 0;
    image->points[pos].bg = 0;
    image->points[pos].ch = 0;
    image->modified = 1;
}

/**
 * Save content at the current screen buffer position
 *
 */
void edit_point(screen_buffer_t *screen_buffer, int pos) {
    /*
       1. Make sure the current buffer position is within the screen buffer
       2. Save current attributes (ch, fg, bg) at the current screen buffer
          position
          XXX: We could save some extra bytes by storing color pair number
               instead of fg and bg separate. Read more in file.c
       3. Set a variable to indicate that the screen buffer is modified
     */

    if(screen_buffer->cursor_y > 0 && screen_buffer->cursor_x > 0) {
        screen_buffer->points[pos].y = screen_buffer->cursor_y;
        screen_buffer->points[pos].x = screen_buffer->cursor_x;
        screen_buffer->points[pos].ch = screen_buffer->current_char;
        screen_buffer->modified = 1;
    }
}
