#ifndef KEYMAP_BONUS_H
#define KEYMAP_BONUS_H

typedef struct s_game t_game;

typedef struct s_keymap {
    int keycode; // code de la touche
    int (*action)(t_game *game); // fonction a executer
} t_keymap;

#endif