# include "../includes/sora.h"

int	key_down(int key, t_sora *sora) {
	if (key == ESC)
		exit_program(sora);
	if (key == SPACE)
		sora->mode = false;
	return 0;
}
