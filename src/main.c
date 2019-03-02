#include <stdio.h>
#include <allegro5/allegro.h>
#include "config.h"
#include "game.h"


int main(int argc, char **argv) {

    ALLEGRO_DISPLAY         *display = NULL;
    ALLEGRO_DISPLAY_MODE    disp_data;
    int                     WIDTH,
                            HEIGHT;

    if(!al_init()) {
        printf("Failed to initialize allegro!\n");
        return -1;
    }

    if(!al_init_primitives_addon()) {
        printf("Failed to initialize allegro primitives!\n");
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
    //al_set_new_display_flags(ALLEGRO_FULLSCREEN);

    //Create Display
    display = al_create_display(WIDTH, HEIGHT);

    if(!display) {
        printf("Failed to create display!\n");
        return -1;
    }

    //------------------    Begin Temp

    GAME game;

    init_game(&game, WIDTH, HEIGHT, 10, 5);

    int c = 0;

    while(c < 500) {

        update_game(&game);

        //Flip display buffer after each update
        al_flip_display();

        //Wait for 1 seconds
        al_rest(0.1);

        c++;
    }

    destroy_game(&game);

    //------------------    End Temp

    //Close display and release resources
    al_destroy_display(display);

    return 0;
}
