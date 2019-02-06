#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "config.h"

int main() {

    ALLEGRO_DISPLAY         *display = NULL;
    ALLEGRO_DISPLAY_MODE    disp_data;
    int                     WIDTH,
                            HEIGHT;

    if(!al_init()) {
      printf("Failed to initialize allegro!\n");
      return -1;
    }

    if(al_get_num_display_modes() < 1) {
        printf("No display mode available");
        return -1;
    }

    //Start with first display mode
    al_get_display_mode(0, &disp_data);

    //Display the resolution
    printf("Display Resolution: %dx%d\n", disp_data.width, disp_data.height);

    //Set width and height
    WIDTH   = disp_data.width;
    HEIGHT  = disp_data.height;

    //Set display flag
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    //Create Display
    display = al_create_display(WIDTH, HEIGHT);

    if(!display) {
        printf("Failed to create display!\n");
        return -1;
    }

    //------------------    Begin Temp

    //Clear display with specified colour
    al_clear_to_color(al_map_rgb(128, 0, 196));

    //Set pixel colour in the middle of the screen
    al_draw_pixel(WIDTH/2, HEIGHT/2, al_map_rgb(0, 0, 0));

    //Flip display buffer after each update
    al_flip_display();

    //Wait for 3 seconds
    al_rest(3);

    //------------------    End Temp

    //Close display and release resources
    al_destroy_display(display);

    return 0;
}
