/*                                                                            
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

#include <curses.h>
#include <errno.h>

/**
  * Initialize curses
  *
  */
void init_curses() {
    initscr();
    curs_set(0);
    noecho();

    (void) getmaxyx(stdscr, term_height, term_width);
    if(term_height < MAX_HEIGHT || term_width < MAX_WIDTH) {
        fprintf(stderr, "At least %dx%d required.\n", MAX_WIDTH, MAX_HEIGHT);
        exit(EXIT_FAILURE);
    }
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

    short color_pair, fg, bg, i, n;
    n_pair = 0;                                                                 
                                                                                
    /* XXX: untested code
       8 different colors, looping through to get all possible combinations
     */
    for(n = 8; n >= 0; n--) {                                                   
        for(i = 0; i <= 8; i++) {                                               
            init_pair(color_pair, fg, bg);
            n_pair++;                                                           
        }                                                                       
    }                              
}

/**
  * Initialize a new screen buffer
  *
  */
void init_screen_buffer(screen_buffer_t *screen_buffer, WINDOW *screen_buffer_window) {
    /*
       1. Set header data
       2. Create new_screen buffer
     */
    screen_buffer_window = create_window(MAX_HEIGHT+2, MAX_WIDTH+2,
                                         BORDER_BEGIN_Y, BORDER_BEGIN_X, TRUE);

}

/// XXX void init_menu() {
//}
//

// Create a holder for the menu bar
// Initialize menu and set attributes
// Set initial settings (default colors etc.)
