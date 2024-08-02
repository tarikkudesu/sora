# include "../includes/sora.h"

void	update_pos(t_sora *sora) {

	int dx, dy;
	int	newP[2];

    if (sora->mouse_pressed) {
        dx = sora->me.tar_x - sora->me.x;
        dy = sora->me.tar_y - sora->me.y;

		newP[0] = sora->me.x + dx * MOVE_SPEED;
		newP[1] = sora->me.y + dy * MOVE_SPEED;

			sora->me.x = newP[0];
			sora->me.y = newP[1];
		if (sora->background[newP[1]][newP[0]] != 0x000000) {


			dx = sora->me.x - WIDTH / 2;
			dy = sora->me.y - HEIGHT / 2;

			double	distance = sqrt(dx * dx + dy * dy) / WIDTH;
		
			newP[0] = sora->pos[0] + dx * distance;
			newP[1] = sora->pos[1] + dy * distance;
		
			if (newP[0] >= 0 && newP[0] <= sora->back[sora->currTex].width - WIDTH)
				sora->pos[0] = newP[0];
			if (newP[1] >= 0 && newP[1] <= sora->back[sora->currTex].height - HEIGHT)
				sora->pos[1] = newP[1];

		} else {

			sora->me.x = newP[0];
			sora->me.y = newP[1];

			dx = sora->me.x - WIDTH / 2;
			dy = sora->me.y - HEIGHT / 2;

			double	distane = sqrt(dx * dx + dy * dy) / WIDTH / 2;
		
			newP[0] = sora->pos[0] + dx * distane * 0.1;
			newP[1] = sora->pos[1] + dy * distane * 0.1;
		
			if (newP[0] >= WIDTH / 2 && newP[0] <= sora->back[sora->currTex].width - WIDTH / 2)
				sora->pos[0] = newP[0];
			if (newP[1] >= HEIGHT / 2 && newP[1] <= sora->back[sora->currTex].height - HEIGHT / 2)
				sora->pos[1] = newP[1];
		}

    } else {

		dx = sora->me.x - WIDTH / 2;
		dy = sora->me.y - HEIGHT / 2;
		
		double	distane = sqrt(dx * dx + dy * dy) / WIDTH / 2;

		if (dx > 0 && (sora->me.x > WIDTH / 2 + 10 || sora->me.x < WIDTH / 2 + 10)) {
			sora->me.x -= fabs(dx * distane * 0.3);
			newP[0] = sora->pos[0] + fabs(dx * distane * 0.3);
			if (newP[0] > WIDTH / 2 && newP[0] < sora->back[sora->currTex].width - WIDTH)
				sora->pos[0] = newP[0];
		}
		else if (sora->me.x > WIDTH / 2 + 10 || sora->me.x < WIDTH / 2 + 10) {
			sora->me.x += fabs(dx * distane * 0.3);
			newP[0] = sora->pos[0] - fabs(dx * distane * 0.3);
			if (newP[0] > WIDTH / 2 && newP[0] < sora->back[sora->currTex].width - WIDTH)
				sora->pos[0] = newP[0];
		}
		if (dy > 0 && (sora->me.y > HEIGHT / 2 + 10 && sora->me.y < HEIGHT / 2 + 10)) {
			sora->me.y -= fabs(dy * distane * 0.3);
			newP[1] = sora->pos[1] + fabs(dy * distane * 0.3);
			if (newP[1] > HEIGHT / 2 && newP[1] < sora->back[sora->currTex].height - HEIGHT)
				sora->pos[1] = newP[1];
		}
		else if (sora->me.y > HEIGHT / 2 + 10 && sora->me.y < HEIGHT / 2 + 10) {
			sora->me.y += fabs(dy * distane * 0.3);
			newP[1] = sora->pos[1] - fabs(dy * distane * 0.3);
			if (newP[1] > HEIGHT / 2 && newP[1] < sora->back[sora->currTex].height - HEIGHT)
				sora->pos[1] = newP[1];
		}
	}
}
