#ifndef WINDOW_H
#define WINDOW_H

typedef struct s_window {
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	int		title_size;
} t_window;

#endif