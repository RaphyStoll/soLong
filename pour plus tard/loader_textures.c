#include "header/game.h"

t_game *init_game(int map_width, int map_height) {
    t_game *game = malloc(sizeof(t_game));
    if (!game)
        return NULL;

//    game->enemies = malloc(sizeof(t_enemy_stats) * NUM_ENEMIES); // Exemple : NUM_ENEMIES = 5
    game->items = malloc(sizeof(t_item) * NUM_ITEMS); // Exemple : NUM_ITEMS = 10
    game->player = malloc(sizeof(t_player));
    game->textures = malloc(sizeof(t_textures));
    game->map_width = map_width;
    game->map_height = map_height;
    game->map = malloc(sizeof(char *) * map_height);
    for (int i = 0; i < map_height; i++)
        game->map[i] = malloc(sizeof(char) * map_width);

    // Initialisez les sous-structures ici, si nécessaire
    return game;
}

void free_game(t_game *game) {
    if (game) {
//        free(game->enemies);
        free(game->items);
        free(game->player);
        free(game->textures);
        for (int i = 0; i < game->map_height; i++)
            free(game->map[i]);
        free(game->map);
        free(game);
    }
}