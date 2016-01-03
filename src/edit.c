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
void delete_point(screen_buffer_t *screen_buffer, int pos) {
    /*
       1. Make sure the current buffer position is within the screen buffer
          (This should never happen. Is it even a possible bug?
	   Check maybe uneeded)
       2. Set y,x, fg, bg, ch to 0 on current buffer position
       3. Set a variable to indicate that the screen buffer is modified
     */

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
}

/**
 * Show cursor
 *
 */
void show_cursor(screen_buffer_t *screen_buffer,WINDOW *screen_buffer_window) {
    mvwaddch(screen_buffer_window, screen_buffer->cursor_y, 
             screen_buffer->cursor_x, screen_buffer->current_char);
}
