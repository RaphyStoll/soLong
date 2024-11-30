#ifndef TEXTURES_H
#define TEXTURES_H

typedef struct s_textures {
	void *player; //! P
	void *wall; //! 1
	void *floor; //! 0§
	void *collectible; //! C
	void *exit_open; //! E
	void *exit_closed; //! E

} t_textures;

#endif