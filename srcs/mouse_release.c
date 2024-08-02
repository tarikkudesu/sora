# include "../includes/sora.h"

int	mouse_release(int button, int x, int y, t_sora *sora) {
		puts("released");
	if (button == 1) {
		sora->mouse_pressed = false;
	}
	(void)x;
	(void)y;
	return 0;
}
