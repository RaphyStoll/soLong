#ifndef TEXTURES_BONUS_H
#define TEXTURES_BONUS_H

#include "game_bonus.h"

typedef struct s_textures {
	void *player_up; //! P
	void *player_down; //! P
	void *player_left; //! P
	void *player_right; //! P
	void *wall; //! 1
	void *floor; //! 0
	void *collectible; //! C
	void *exit_open; //! E
	void *exit_closed; //! E
	int width;
	int height;

} t_textures;

#endif