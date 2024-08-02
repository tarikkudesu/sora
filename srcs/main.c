
#include "../includes/sora.h"

// #13AFFF blue
// #AB12FF move
// #FF1431 red
// #0AD56E green

void	init(t_sora *sora) {
	sora->pos[0] = WIDTH / 2;
	sora->pos[1] = HEIGHT / 2;
	sora->des[0][0] = 7800;
	sora->des[0][1] = 7550;
	sora->des[1][0] = 2340;
	sora->des[1][1] = 1880;
	sora->des[2][0] = 2800;
	sora->des[2][1] = 6300;
	sora->des[3][0] = 6900;
	sora->des[3][1] = 2600;
	sora->des[4][0] = 50000;
	sora->des[4][1] = 50000;
	sora->me.x = WIDTH / 2;
	sora->me.y = HEIGHT / 2;
	sora->me.tar_x = WIDTH / 2;
	sora->me.tar_y = HEIGHT / 2;
	sora->me.back_x = WIDTH / 2;
	sora->me.back_y = HEIGHT / 2;
	sora->mouse_pressed = false;
	sora->colors[0] = 0x000000;
	sora->colors[1] = 0xFF1431;
	sora->colors[2] = 0x13AFFF;
	sora->colors[3] = 0xAB12FF;
	sora->colors[4] = 0x0AD56E;
	sora->currTex = 0;
	sora->mode = true;
}

int main() {
	t_sora	sora;

	get_sora(&sora);
	init(&sora);
	sora.mlx.__mlx = mlx_init();
	if (!sora.mlx.__mlx)
		terror(ERR_MLX_INIT);
	sora.mlx.__win = mlx_new_window(sora.mlx.__mlx, WIDTH, HEIGHT, "sora");
	if (!sora.mlx.__win)
		terror(ERR_MLX_WIN);
	sora.intro.__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/intro.xpm", &sora.intro.width, &sora.intro.height);
	if (!sora.intro.__img)
		terror(ERR_MLX_XPM);

	sora.img.__img = mlx_new_image(sora.mlx.__mlx, WIDTH, HEIGHT);
	if (!sora.img.__img)
		terror(ERR_MLX_IMG);
	sora.img.__addr = (int *)mlx_get_data_addr(sora.img.__img, \
	&sora.img.pixel_bits, &sora.img.line_bytes, &sora.img.endian);
	if (!sora.img.__addr)
		terror(ERR_MLX_ADDRESS);

	// -----------------------------player--------------------------------
	sora.player.__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/player.xpm", &sora.player.width, &sora.player.height);
	if (!sora.player.__img)
		terror(ERR_MLX_XPM);
	sora.player.__addr = \
		(int *)mlx_get_data_addr(sora.player.__img, \
		&sora.player.pixel_bits, &sora.player.line_bytes, \
		&sora.player.endian);
	if (!sora.player.__addr)
		terror(ERR_MLX_ADDRESS);

	// -----------------------------indicator--------------------------------
	sora.indicator.__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/indicator.xpm", &sora.indicator.width, &sora.indicator.height);
	if (!sora.indicator.__img)
		terror(ERR_MLX_XPM);
	sora.indicator.__addr = \
		(int *)mlx_get_data_addr(sora.indicator.__img, \
		&sora.indicator.pixel_bits, &sora.indicator.line_bytes, \
		&sora.indicator.endian);
	if (!sora.indicator.__addr)
		terror(ERR_MLX_ADDRESS);

	// -----------------------------collitions--------------------------------
	sora.coll.__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/backcoll.xpm", &sora.coll.width, &sora.coll.height);
	if (!sora.coll.__img)
		terror(ERR_MLX_XPM);
	sora.coll.__addr = \
		(int *)mlx_get_data_addr(sora.coll.__img, \
		&sora.coll.pixel_bits, &sora.coll.line_bytes, \
		&sora.coll.endian);
	if (!sora.coll.__addr)
		terror(ERR_MLX_ADDRESS);

	// -----------------------------background--------------------------------
	sora.back[0].__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/gray.xpm", &sora.back[0].width, &sora.back[0].height);
	if (!sora.back[0].__img)
		terror(ERR_MLX_XPM);
	sora.back[1].__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/red.xpm", &sora.back[1].width, &sora.back[1].height);
	if (!sora.back[1].__img)
		terror(ERR_MLX_XPM);
	sora.back[2].__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/blue.xpm", &sora.back[2].width, &sora.back[2].height);
	if (!sora.back[2].__img)
		terror(ERR_MLX_XPM);
	sora.back[3].__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/move.xpm", &sora.back[3].width, &sora.back[3].height);
	if (!sora.back[3].__img)
		terror(ERR_MLX_XPM);
	sora.back[4].__img = mlx_xpm_file_to_image(sora.mlx.__mlx, "final/green.xpm", &sora.back[3].width, &sora.back[3].height);
	if (!sora.back[4].__img)
		terror(ERR_MLX_XPM);
	for (int i = 0; i < 5; i++) {
		sora.back[i].__addr = \
			(int *)mlx_get_data_addr(sora.back[i].__img, \
			&sora.back[i].pixel_bits, &sora.back[i].line_bytes, \
			&sora.back[i].endian);
		if (!sora.back[i].__addr)
			terror(ERR_MLX_ADDRESS);
	}
	mlx_mouse_hide();
	mlx_loop_hook(sora.mlx.__mlx, update_frame, &sora);
	mlx_hook(sora.mlx.__win, ON_KEYUP, 0, key_up, &sora);
	mlx_hook(sora.mlx.__win, ON_KEYDOWN, 0, key_down, &sora);
	mlx_hook(sora.mlx.__win, ON_MOUSEMOVE, 0, mouse_move, &sora);
	mlx_hook(sora.mlx.__win, ON_MOUSEDOWN, 0, mouse_press, &sora);
	mlx_hook(sora.mlx.__win, ON_MOUSEUP, 0, mouse_release, &sora);
	mlx_hook(sora.mlx.__win, ON_DESTROY, 0, exit_program, &sora);
	mlx_loop(sora.mlx.__mlx);

	return 0;
}
