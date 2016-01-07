/*                                                                              
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/      

#ifndef FILE_H
#define FILE_H

#include "screen_buffer.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

void save_file(const char *filename, screen_buffer_t *screen_buffer);
screen_buffer_t *open_file(const char *filename);
int file_exists(const char *filename);
#endif
