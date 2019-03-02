#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

typedef struct {
    int width;
    int height;
    int step;
    char *data;
} GAME;

/**
 * @brief Initialize a game instance and create initial seed.
 *
 * @param game Pointer to the GAME structure to initialize
 * @param width Screen/Window width, identical to number of horizontal elements
 * @param height Screen/Window height, identical to number of vertical elements
 * @param step Step size
 * @param coverage A number between 0 - 100 indicating the percentage of a cell being alive
 *
 * @return void
 ***************************************************************/
void init_game(GAME *game, int width, int height, int step, int coverage);

void update_game(GAME *game);

void destroy_game(GAME *game);

//-------------------------------------------
//  Private functions
//-------------------------------------------

int get_neighbours(GAME game, int x, int y);

int get_data_index(int width, int x, int y);

int get_left_x(int x, GAME game);

int get_right_x(int x, GAME game);

int get_top_y(int y, GAME game);

int get_bottom_y(int y, GAME game);

#endif // GAME_H_INCLUDED
