/*                                                                                                                                                                                                                 
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   
#include "main.h"
#include "init.h"

void endProgram() {                                                             
    curs_set(1);                                                                  
    endwin();                                                                     
    fprintf(stderr, "Exiting!\n");                                                
    exit(EXIT_SUCCESS);                                                           
}                        

int main(int argc, char *argv[]) {
    int y_old, x_old, term_height, term_width, cur_pos;
    const char *filename;
    bool busy;
    screen_buffer_t *screen;

    atexit((void *) exit_program);

    init_curses();
    init_colors();
    init_screen_buffer(screen);
    init_menu(); /// XXX: def


    if(argc > 1) {
        filename = argv[1];
        screen = open_file(filename);
    }

    /*
     * Main program loop
     *
    */
    busy = 1;
    while(busy) {
        // Set cursor position
        // Show image
        // Show cursor
        // Show program logo
        // show menu bar
        // redraw and update screen buffer

        /*
         * Keyboard input routines goes here:
         * .. menu handler, screen buffer editing
         */
    }

    // Deinit

    return(EXIT_SUCCESS);
}

