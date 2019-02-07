#include <allegro.h>
#include "game.h"

void init_game(GAME *game, int width, int height, int coverage) {

    //Set random seed
    srand(time(NULL));

    game->width     = width;
    game->height    = height;
    game->data      = malloc(width * height * sizeof(char));

    //Create game seed
    int x, y, r;

    for(x = 0; x < width; x++)
        for(y = 0; y < height; y++) {
            r = rand() % 100;                           //Pick a random number between 0 and 100
            game->data[(width * y) + x] = r < coverage; //Set 1 if randomly picked number is < coverage
        }
}

void update_game(GAME *game) {

    int x, y;

    for(x = 0; x < game->width; x++)
        for(y = 0; y < game->height; y++) {

        }
}

void paint_game(GAME game) {

    //Set background colour to black
    //ToDo: Allow user setting for background colour
    al_clear_to_color(al_map_rgb(0, 0, 0));

    //Set foreground colour to yellow
    //ToDo: Allow user setting for foreground colour
    ALLEGRO_COLOR fore_colour = al_map_rgb(255, 255, 0);

    int x, y;

    for(x = 0; x < game.width; x++)
        for(y = 0; y < game.height; y++)
            if(game.data[get_data_index(game.width, x, y)])
                al_draw_pixel(x, y, fore_colour);
}

void destroy_game(GAME *game) {
    if(game->data) free(game->data);
    game->data = NULL;
}

//-------------------------------------------
//  Private functions
//-------------------------------------------

int get_neighbours(GAME game, int x, int y) {

    return 0;
}

int get_data_index(int width, int x, int y) {
    return (width * y) + x;
}
