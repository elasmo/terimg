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
    mvprintw(0, MAX_WIDTH-6, "terimg_");
    attroff(A_BOLD);
    refresh();
}


int main(int argc, char *argv[]) {
    int y_old, x_old, term_height, term_width, cur_pos, busy, c;
    char *filename = NULL;
    WINDOW *screen_buffer_window = NULL;
    screen_buffer_t screen_buffer;

    atexit((void *) exit_program);

    init_curses();
    init_colors();
    init_screen_buffer(&screen_buffer, screen_buffer_window);
    screen_buffer_window = create_window(MAX_HEIGHT+2, MAX_WIDTH+2,
                                         BORDER_BEGIN_Y, BORDER_BEGIN_X, TRUE);
    keypad(screen_buffer_window, TRUE);
    show_banner();
    mvprintw(0,2, "image size: %d:%d", IMAGE_WIDTH, IMAGE_HEIGHT);
    refresh();

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
        // Set cursor position in buffer
        cur_pos = get_bufpos(screen_buffer.cursor_x, 
                             screen_buffer.cursor_y,
                             screen_buffer.width);

        // Clear current position
        mvwaddch(screen_buffer_window, y_old, x_old, SPACE);

        // Show cursor
        show_cursor(&screen_buffer, screen_buffer_window);
        y_old = screen_buffer.cursor_y;
        x_old = screen_buffer.cursor_x;

        // Show image
        show_screen_buffer(&screen_buffer, screen_buffer_window);

        // redraw and update screen buffer
        wrefresh(screen_buffer_window);

        /*
         * Keyboard input routines goes here:
         * .. menu handler, screen buffer editing
         */
        switch(c = wgetch(screen_buffer_window)) {
        case SPACE:
            edit_point(&screen_buffer, cur_pos);
            break;
        case KEY_UP:
            if(screen_buffer.cursor_y > 1)
                --screen_buffer.cursor_y;
            break;
        case KEY_DOWN:
            if(screen_buffer.cursor_y < IMAGE_HEIGHT)
                ++screen_buffer.cursor_y;
            break;
        case KEY_LEFT:
            if(screen_buffer.cursor_x > 1)
                --screen_buffer.cursor_x;
            break;
        case KEY_RIGHT:
            if(screen_buffer.cursor_x < IMAGE_WIDTH)
                ++screen_buffer.cursor_x;
            break;
        }
    }
    // Deinit
    free(screen_buffer.points);
    delwin(screen_buffer_window);

    refresh();

    return(EXIT_SUCCESS);
}
