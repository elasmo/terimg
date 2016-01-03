/*                                                                            
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

#include "init.h"
#include "window.h"

/**
  * Initialize curses
  *
  */
void init_curses() {
    initscr();
    curs_set(0);
    noecho();

    /*
    int term_height = MAX_HEIGHT; // FIXME lyulz
    int term_width = MAX_WIDTH; // FIXME lyulz

    (void) getmaxyx(stdscr, term_height, term_width);
    if(term_height < MAX_HEIGHT || term_width < MAX_WIDTH) {
        fprintf(stderr, "At least %dx%d required.\n", MAX_WIDTH, MAX_HEIGHT);
        exit(EXIT_FAILURE);
    }
    */
}

/** 
  * Initialize colors
  *
  */
void init_colors() {
    if(!has_colors()) {
        fprintf(stderr, "Your terminal does not support color.\n");
        exit(EXIT_FAILURE);
    }

    start_color();

    //short color_pair, fg, bg, i, n;

    //n_pair = 0;                                                                 
                                                                                
    /* XXX: untested code
       8 different colors, looping through to get all possible combinations
     */
    /*
    for(n = 8; n >= 0; n--) {                                                   
        for(i = 0; i <= 8; i++) {                                               
            init_pair(color_pair, fg, bg);
            n_pair++;                                                           
        }                                                                       
    }                              
    */
}

/**
  * Create screen buffer decorations
  *
  */
//void create_screen_buffer_deco(WINDOW *screen_buffer_window) {
//    screen_buffer_window = create_window(MAX_HEIGHT+2, MAX_WIDTH+2,
//                                         BORDER_BEFIN_Y, BORDER_BEGIN_X, TRUE);
//}

/**
  * Initialize a new screen buffer
  *
  */
void init_screen_buffer(screen_buffer_t *screen_buffer, WINDOW *screen_buffer_window) {
    /*
       1. Set header data
       2. Create new_screen buffer
     */

    // Initial default values
    screen_buffer->file_version = 1;
    screen_buffer->width = IMAGE_WIDTH;
    screen_buffer->height = IMAGE_HEIGHT;
    screen_buffer->area = screen_buffer->width * screen_buffer->height;
    screen_buffer->current_char = ACS_CKBOARD;
    screen_buffer->fg = COLOR_YELLOW;
    screen_buffer->bg = COLOR_BLACK;
    screen_buffer->cursor_x = 1;
    screen_buffer->cursor_y = 2;
    screen_buffer->buffer_modified = 0;
    screen_buffer->points =  new_screen_buffer();
}

/// XXX void init_menu() {
// Create a holder for the menu bar
// Initialize menu and set attributes
// Set initial settings (default colors etc.)
//}
//

