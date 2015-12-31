/*                                                                                                                                                                                                                 
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

#include "menu.h"

/**
  * Initialize a submenu
  *
  */
menu_t init_menu(const char *items[]) {
    // Allocate memory for items
    // Attach items to menu
    // Create new menu
    // Create menu windows
    // Set window attributes
    // Set menu attributes
    // Return menu
}

/**
  * Deinitialize a submenu
  *
  */
void deinit_submenu(menu_t *menu) {
    // Unpost menu
    // Delete associated window
    // Free memory
}


/**
  * Show sub menu
  *
  */
char **show_submenu(menu_t *menu) {
    bool busy = 1;

    // post menu

    while(busy) {
        // Look for keyboard input
    }
}

/**
  * Show menu bar
  *
  */
void show_menu_bar(WINDOW *win) {
    // Static print of main menu items
}
