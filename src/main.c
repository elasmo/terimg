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
    attron(COLOR_PAIR(1));
    mvprintw(0, DEFAULT_WIDTH-6, "terimg");
    attroff(COLOR_PAIR(1));
    attroff(A_BOLD);
    refresh();
}


int main(int argc, char *argv[]) {
    int y_old, x_old, term_height, term_width, cur_pos, busy, c;
    char *filename = NULL;
    WINDOW *screen_buffer_window = NULL;
    screen_buffer_t screen_buffer;

    y_old = x_old = 1;

    atexit((void *) exit_program);

    /* Open image from file or create a new clean buffer */
    if(argc > 1) {
        filename = argv[1];
        fprintf(stderr, "Not implemented: open file %s\n", filename);
        exit(EXIT_SUCCESS);
                
        //screen_buffer = open_file(filename);
        //or open_file(screen_buffer, filename);
    }

    /* Init */
    init_curses();
    init_colors();
    screen_buffer_window = create_screen_buffer_window();
    init_screen_buffer(&screen_buffer);

    /* Decorations and info */
    show_banner();
    //init_menu(); /// XXX: def


    /*
     * Main program loop
     *
    */
    busy = 1;
    while(busy) {
        wrefresh(screen_buffer_window);

        /* Set cursor position in buffer */
        cur_pos = get_bufpos(screen_buffer.cursor_x, 
                             screen_buffer.cursor_y,
                             screen_buffer.width);

        /* Clear old cursor position */
        mvwaddch(screen_buffer_window, y_old, x_old, SPACE);
        y_old = screen_buffer.cursor_y; // XXX: getyx() ??
        x_old = screen_buffer.cursor_x;

        /* Show image */
        show_screen_buffer(&screen_buffer, screen_buffer_window);

        /* Show cursor */
        mvwaddch(screen_buffer_window, 
                 screen_buffer.cursor_y,
                 screen_buffer.cursor_x,
                 screen_buffer.current_char);

        /* Info, temporary */
        /*
        mvprintw(DEFAULT_HEIGHT+3, 2, 
                 "                                                                                      ");*/
        mvaddstr(0, 2, "F(1) SAVE\tF(2) OPEN\tF(3) EXIT");

        mvprintw(DEFAULT_HEIGHT+4, 2, 
                 "size: %2dx%2d, cursor: %2d:%2d, mod: %d, bufpos: %4d",
                 screen_buffer.width, 
                 screen_buffer.height,
                 screen_buffer.cursor_x,
                 screen_buffer.cursor_y,
                 screen_buffer.modified,
                 cur_pos);


        refresh();


        /*
         * Keyboard input routines goes here:
         * .. menu handler, screen buffer editing
         */
        switch(c = wgetch(screen_buffer_window)) {
        /* Editing */
        case SPACE:
            edit_point(&screen_buffer, cur_pos);
            if(screen_buffer.cursor_x < screen_buffer.width)
                screen_buffer.cursor_x++;
            break;
        case KEY_DC:
            delete_point(&screen_buffer, cur_pos);
            if(screen_buffer.cursor_x < screen_buffer.width)
                screen_buffer.cursor_x++;
            break;
        /* Navigation */
        case KEY_HOME:
            screen_buffer.cursor_x = 1;
            break;
        case KEY_END:
            screen_buffer.cursor_x = screen_buffer.width;
            break;
        case KEY_UP:
            if(screen_buffer.cursor_y > 1)
                screen_buffer.cursor_y--;
            break;
        case KEY_DOWN:
            if(screen_buffer.cursor_y < screen_buffer.height)
                screen_buffer.cursor_y++;
            break;
        case KEY_LEFT:
            if(screen_buffer.cursor_x > 1)
                screen_buffer.cursor_x--;
            break;
        case KEY_RIGHT:
            if(screen_buffer.cursor_x < screen_buffer.width)
                screen_buffer.cursor_x++;
            break;
        case KEY_NPAGE:
            if((screen_buffer.cursor_y + 4) < screen_buffer.height)
                screen_buffer.cursor_y += 4;
            else
                screen_buffer.cursor_y = screen_buffer.height;
            break;
        case KEY_PPAGE:
            if(screen_buffer.cursor_y > 4)
                screen_buffer.cursor_y -= 4;
            else
                screen_buffer.cursor_y = 1;
            break;
        /* Menu */
        case KEY_F(1):
            save_file("test.dat", &screen_buffer);
            break;
        case KEY_F(2):
        case KEY_F(3):
            busy = 0;
            break;
        }


    }

    // Deinit
    free(screen_buffer.points);
    delwin(screen_buffer_window);

    return(EXIT_SUCCESS);
}
