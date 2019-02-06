#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "config.h"

int main() {
    ALLEGRO_DISPLAY         *display = NULL;
    ALLEGRO_DISPLAY_MODE    disp_data;
    int WIDTH, HEIGHT;

    if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
    }

    printf("Display Modes: %d\n", al_get_num_display_modes());

    al_get_display_mode(0, &disp_data);

    printf("Display Resolution: %dx%d\n", disp_data.width, disp_data.height);

    WIDTH   = disp_data.width;
    HEIGHT  = disp_data.height;

    al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    display = al_create_display(WIDTH, HEIGHT);

    if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
    }

    al_clear_to_color(al_map_rgb(128,0,196));

    al_flip_display();

    al_rest(3);

    al_destroy_display(display);

    return 0;
}
