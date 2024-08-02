# include "../includes/sora.h"

int	mouse_move(int x, int y, t_sora *sora) {

	if (sora->mouse_pressed) {
		puts("moved");
		if (x < 100)
			sora->me.tar_x = 100;
		else if (x > WIDTH  - 100)
			sora->me.tar_x = WIDTH - 100;
		else
			sora->me.tar_x = x;
	
		if (y < 100)
			sora->me.tar_y = 100;
		else if (y > HEIGHT - 100)
			sora->me.tar_y = HEIGHT - 100;
		else
			sora->me.tar_y = y;
	}
	return 0;
}
