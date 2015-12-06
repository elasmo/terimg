/*                                                                                                                                                                                                                 
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

#ifndef MENU_H
#define MENU_H

extern struct menu_t;

menu_t init_menu(const char *items[]);
void deinit_submenu(menu_t *menu);
char **show_submenu(menu_t *menu);
void show_menu_bar(WINDOW *win);

#endif
