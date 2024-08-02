# include "../includes/sora.h"

// #13AFFF blue
// #AB12FF move
// #FF1431 red
// #0AD56E green

t_color	hex_to_rgb(int color)
{
	t_color	rgb;

	rgb.red = (color >> 16) & 255;
	rgb.green = (color >> 8) & 255;
	rgb.blue = (color >> 0) & 255;
	return (rgb);
}

int	rgb_to_hex(t_color rgb)
{
	return (rgb.blue | rgb.green << 8 | rgb.red << 16);
}

unsigned int get_color(t_sora *sora) {
	t_color	start = hex_to_rgb(WHITE);
	t_color	end;
	if (sora->currTex == 4)
		end = hex_to_rgb(sora->colors[0]);
	else
		end = hex_to_rgb(sora->colors[sora->currTex + 1]);

	int	distance = abs(sora->pos[0] * sora->pos[0] + sora->pos[1] + sora->pos[1]);
	int	dx = abs(sora->des[sora->currTex][0] - sora->pos[0]);
	int	dy = abs(sora->des[sora->currTex][1] - sora->pos[1]);
	int	distanceTotal = abs(dx * dx + dy * dy);
	double frac = (double)distance / (double)distanceTotal;
	if (frac > 0.95 && frac < 1.05) {
		if (sora->currTex < 5)
			sora->currTex += 1;
	}
	t_color	res;
	res.red = start.red + (end.red - start.red) * frac;
	res.green = start.green + (end.green - start.green) * frac;
	res.blue = start.blue + (end.blue - start.blue) * frac;
	if (frac > 1)
		return (sora->colors[sora->currTex]);
	else if (frac < 0)
		return (0xffffff);
	return rgb_to_hex(res);
}

void put_indicator(t_sora *sora) {
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			unsigned	int	color = sora->indicator.__addr[i * 2 + j * 2 * sora->indicator.line_bytes / 4];
			if (color != 0xff000000)
				pixel_put(i, j, get_color(sora));
		}
	}
}
