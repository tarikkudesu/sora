# include "../includes/sora.h"

int	mouse_press(int button, int x, int y, t_sora *sora) {
		puts("pressed");
	if (button == 1 && x > 0 && x < WIDTH && y > 0 && y < HEIGHT) {
		sora->mouse_pressed = true;
		sora->me.tar_x = x;
		sora->me.tar_y = y;
	}
	return 0;
}
