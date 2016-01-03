/*                                                                            
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   
#include "main.h"
#include "edit.h"
#include "init.h"

void exit_program() {                                                             
    curs_set(1);                                                                  
    endwin();                                                                     
    fprintf(stderr, "Exiting!\n");                                                
    exit(EXIT_SUCCESS);                                                           
}

void show_banner() {
    attron(A_BOLD);
    mvprintw(0, MAX_WIDTH-6, "[terimg]");
    attroff(A_BOLD);
    refresh();
}


int main(int argc, char *argv[]) {
    int y_old, x_old, term_height, term_width, cur_pos, busy;
    char *filename = NULL;
    WINDOW *screen_buffer_window = NULL;
    screen_buffer_t screen_buffer;

    atexit((void *) exit_program);

    init_curses();
    init_colors();
    init_screen_buffer(&screen_buffer, screen_buffer_window);
    screen_buffer_window = create_window(MAX_HEIGHT+2, MAX_WIDTH+2,
                                         BORDER_BEGIN_Y, BORDER_BEGIN_X, TRUE);
    show_banner();
    //init_menu(); /// XXX: def


    if(argc > 1) {
        filename = argv[1];
        //screen_buffer = open_file(filename);
        //or open_file(screen_buffer, filename);
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
        show_cursor(&screen_buffer, screen_buffer_window);

//    mvwaddch(screen_buffer_window, screen_buffer.cursor_y, 
//             screen_buffer.cursor_x, screen_buffer.current_char);
        // show menu bar
        // redraw and update screen buffer
        show_screen_buffer(&screen_buffer, screen_buffer_window);
        wrefresh(screen_buffer_window);

        /*
         * Keyboard input routines goes here:
         * .. menu handler, screen buffer editing
         */
    }
    // Deinit

    refresh();

    return(EXIT_SUCCESS);
}

