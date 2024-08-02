
#ifndef SORA
# define SORA


# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "struct.h"
# include "macros.h"
#include <sys/time.h>


/* FUNCTIONS */
void	 put_indicator(t_sora *sora);
void	update_pos(t_sora *sora);
void	pixel_put(int x, int y, int color);
void	put_player(t_sora *sora);
t_sora	*get_sora(t_sora *sora);
int		update_frame(t_sora *sora);
int		key_down(int key, t_sora *sora);
int		key_up(int key, t_sora *sora);
int		mouse_move(int x, int y, t_sora *sora);
int		mouse_press(int button, int x, int y, t_sora *sora);
int		mouse_release(int button, int x, int y, t_sora *sora);
int		exit_program(t_sora *cub);
void	terror(char *__err__message);

#endif