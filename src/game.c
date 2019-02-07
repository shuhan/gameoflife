#include <allegro5/allegro.h>
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

    int x, y, i, n;

    //Set background colour to black
    //ToDo: Allow user setting for background colour
    al_clear_to_color(al_map_rgb(0, 0, 0));

    //Set foreground colour to white
    //ToDo: Allow user setting for foreground colour
    ALLEGRO_COLOR fore_colour = al_map_rgb(255, 255, 255);

    for(x = 0; x < game->width; x++)
        for(y = 0; y < game->height; y++) {
            i = get_data_index(game->width, x, y);
            n = get_neighbours(*game, x, y);

            if(game->data[i]) {
                if(n < 2 || n > 3) game->data[i] = 0;   //Die of loneliness or overcrowding
            } else {
                if(n == 3) game->data[i] = 1;           //Reproduction
            }

             if(game->data[i]) al_draw_pixel(x, y, fore_colour);
        }
}

void destroy_game(GAME *game) {
    if(game->data) free(game->data);
    game->data = NULL;
}

//-------------------------------------------
//  Private functions
//-------------------------------------------

int get_neighbours(GAME game, int x, int y) {
    int retval = 0;

    //Start from top and move clockwise
    retval += game.data[get_data_index(game.width, x, get_top_y(y, game.height))];

    retval += game.data[get_data_index(game.width, get_right_x(x, game.width), get_top_y(y, game.height))];

    retval += game.data[get_data_index(game.width, get_right_x(x, game.width), y)];

    retval += game.data[get_data_index(game.width, get_right_x(x, game.width), get_bottom_y(y, game.height))];

    retval += game.data[get_data_index(game.width, x, get_bottom_y(y, game.height))];

    retval += game.data[get_data_index(game.width, get_left_x(x, game.width), get_bottom_y(y, game.height))];

    retval += game.data[get_data_index(game.width, get_left_x(x, game.width), y)];

    retval += game.data[get_data_index(game.width, get_left_x(x, game.width), get_top_y(y, game.height))];

    return retval;
}

int get_data_index(int width, int x, int y) {
    return (width * y) + x;
}

int get_left_x(int x, int width) {
    x--;

    if(x < 0) x = width - 1;

    return x;
}

int get_right_x(int x, int width) {
    x++;

    if(x >= width) x = 0;

    return x;
}

int get_top_y(int y, int height) {
    y--;

    if(y < 0) y = height - 1;

    return y;
}

int get_bottom_y(int y, int height) {
    y++;

    if(y >= height) y = 0;

    return y;
}
