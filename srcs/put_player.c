# include "../includes/sora.h"

void rotate_point(t_sora *sora, int *x, int *y) {
	int	dx, dy;
	dx = sora->me.tar_x - WIDTH / 2;
	dy = sora->me.tar_y - HEIGHT / 2;
    double rad = atan2(dy, dx) + 90.0f * (M_PI / 180.0);
    int x_new = (int)(*x * cos(rad) - *y * sin(rad));
    int y_new = (int)(*x * sin(rad) + *y * cos(rad));
    *x = x_new;
    *y = y_new;
}

void	put_player(t_sora *sora)
{
	int	i, j;
	int	player_width = 100;
	double	x_frac, y_frac;
	i = 0;
	while (++i < player_width) {
		j = 0;
		x_frac = ((double)i + 1) / (double)player_width;
		while (++j < player_width) {
			y_frac = ((double)j + 1) / (double)player_width;
			double		old_x, old_y;
			old_x = x_frac * sora->player.width;
			old_y = y_frac * sora->player.height;
			int		colorIdx = old_x + old_y * sora->player.line_bytes / 4;

			if (colorIdx > 0 && colorIdx < sora->player.width * sora->player.height) {
				unsigned int color = sora->player.__addr[colorIdx];
				if (color != 0xff000000) {
					int new_x = i - player_width / 2, new_y = j - player_width / 2;
					rotate_point(sora, &new_x, &new_y);
					pixel_put(new_x + sora->me.x, new_y + sora->me.y, color);
				}

			}
		}
	}
}
