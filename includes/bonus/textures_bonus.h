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
	void *monster_blue; //! M
	void *monster_red; //! M
	void *monster_green; //! M
	void *monster_yellow; //! M
	int width;
	int height;

} t_textures;

#endif