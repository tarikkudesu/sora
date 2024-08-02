# include "../includes/sora.h"

void	pixel_put(int x, int y, int color)
{
	t_sora	*sora;
	int		*addr;
	int		pixel;

	sora = get_sora(NULL);
	addr = (int *)sora->img.__addr;
	pixel = y * sora->img.line_bytes / 4 + x;
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		addr[pixel] = color;
}

// void	put_background(t_sora *sora) {
// 	for (int i = 0; i < WIDTH / 2; i++) {
// 		for (int j = 0 ; j < HEIGHT / 2; j++) {
// 			if (i * 2 + sora->pos[0] > 0 && i * 2 + sora->pos[0] < sora->back[sora->currTex].width && j * 2 + sora->pos[1] > 0 && j * 2 + sora->pos[1] < sora->back[sora->currTex].height) {
// 				pixel_put(i * 2, j * 2, sora->back[sora->currTex].__addr[(i * 2 + sora->pos[0]) + (j * 2 + sora->pos[1]) * sora->back[sora->currTex].line_bytes / 4]);
// 				pixel_put(i * 2 + 1, j * 2 + 1, sora->back[sora->currTex].__addr[(i * 2 + sora->pos[0]) + (j * 2 + sora->pos[1]) * sora->back[sora->currTex].line_bytes / 4]);
// 				pixel_put(i * 2 + 1, j * 2, sora->back[sora->currTex].__addr[(i * 2 + sora->pos[0]) + (j * 2 + sora->pos[1]) * sora->back[sora->currTex].line_bytes / 4]);
// 				pixel_put(i * 2, j * 2 + 1, sora->back[sora->currTex].__addr[(i * 2 + sora->pos[0]) + (j * 2 + sora->pos[1]) * sora->back[sora->currTex].line_bytes / 4]);
// 			}
// 			if (i * 2 + sora->pos[0] > 0 && i * 2 + sora->pos[0] < sora->coll.width && j * 2 + sora->pos[1] > 0 && j * 2 + sora->pos[1] < sora->coll.height) {
// 				unsigned int	color = sora->coll.__addr[(i * 2 + sora->pos[0]) + (j * 2 + sora->pos[1]) * sora->coll.line_bytes / 4];
// 				sora->background[j * 2][i * 2] = color;
// 				sora->background[j * 2 + 1][i * 2 + 1] = color;
// 				sora->background[j * 2 + 1][i * 2] = color;
// 				sora->background[j * 2][i * 2 + 1] = color;
// 				if (color == 0x000000) {
// 					pixel_put(i * 2, j * 2, color);
// 					pixel_put(i * 2 + 1, j * 2 + 1, color);
// 					pixel_put(i * 2 + 1, j * 2, color);
// 					pixel_put(i * 2, j * 2 + 1, color);
// 				}
// 			}
// 		}
// 	}
// }

void	put_background(t_sora *sora) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0 ; j < HEIGHT; j++) {
			if (i + sora->pos[0] > 0 && i + sora->pos[0] < sora->back[sora->currTex].width && j + sora->pos[1] > 0 && j + sora->pos[1] < sora->back[sora->currTex].height)
				pixel_put(i, j, sora->back[sora->currTex].__addr[(i + sora->pos[0]) + (j + sora->pos[1]) * sora->back[sora->currTex].line_bytes / 4]);
			if (i + sora->pos[0] > 0 && i + sora->pos[0] < sora->coll.width && j + sora->pos[1] > 0 && j + sora->pos[1] < sora->coll.height) {
				unsigned int	color = sora->coll.__addr[(i + sora->pos[0]) + (j + sora->pos[1]) * sora->coll.line_bytes / 4];
				sora->background[j][i] = color;
				if (color == 0x000000)
					pixel_put(i, j, 0x222222);
			}
		}
	}
}

int	update_frame(t_sora *sora) {
	if (sora->mode == true)
		return mlx_put_image_to_window(sora->mlx.__mlx, sora->mlx.__win, sora->intro.__img, 0, 0);

	put_background(sora);
	update_pos(sora);
	put_player(sora);
	put_indicator(sora);

	mlx_put_image_to_window(sora->mlx.__mlx, sora->mlx.__win, sora->img.__img, 0, 0);
	return 0;
}
