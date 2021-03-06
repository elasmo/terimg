/*                                                                                              
* ----------------------------------------------------------------------------  
* "THE BEER-WARE LICENSE" (Revision 42):                                        
* <Johan> wrote this file. As long as you retain this notice you
* can do whatever you want with this stuff. If we meet some day, and you think  
* this stuff is worth it, you can buy me a beer in return. Johan                
* ----------------------------------------------------------------------------  
*/                   

/*
Fileformat:
   Header
    %d%d%d%d
    [file format version][width][height][area]

   Image
    %d%d%d%d%c
    [y][x][fg][bg][char]

    XXX: Idea to save some extra bytes for fun
         [y][x][color_pair][char]
*/

#include "file.h"

/**
 * Save screen buffer to file
 *
 */
void save_file(const char *filename, screen_buffer_t *screen_buffer) {
    /*
       1. Check if current filename exists and ask user to rename or overwrite
       2. Open file
       3. Write header 
       4. Loop through and write all points
       5. Change screen buffer to unmodified (saved)
       6. Close file
     */

    FILE *fp;
    int i;

    if((fp = fopen(filename, "wb")) == NULL) {
        fclose(fp);
        // Write error, notify user
    }

    /* Header */
    fwrite(&screen_buffer->width, 2, 1, fp);
    fwrite(&screen_buffer->height, 2, 1, fp);

    /* Image */
    for(i = 0; i < screen_buffer->width * screen_buffer->height; ++i) {
        fwrite(&screen_buffer->points[i].x, 2, 1, fp);
        fwrite(&screen_buffer->points[i].y, 2, 1, fp);
        fwrite(&screen_buffer->points[i].ch, 1, 1, fp);
    }

    fclose(fp);
}

/**
 * Open file
 *
 */
screen_buffer_t *open_file(const char *filename) {
    /*
       1. Check if current file exists
       2. Open file and check for read errors
       3. Read header and verify that it's not corrupt/faulty
       4. Create a new screen buffer to read it into
       5. Loop through points and save to buffer
       4. Verify 
       6. Close file and return screen buffer
     */
    if(file_exists(filename)) {
       

    }
    else {
        // Notify user
        // don't do stuff, warn etc.
        return NULL;
    }
}

/**
 * Check if file exists
 * XXX: stat(), access(), open() etc. can be used to get a better way of
 * checking if the file sxists.
 *
 */
int file_exists(const char *filename) {
    FILE *fp = NULL;

    if((fp = fopen(filename, "rb")) == NULL) {
        fclose(fp);
        return 0;
    }
    else {
        fclose(fp);
        return 1;
    }
}
