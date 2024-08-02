#include "../includes/sora.h"

void	putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

t_sora	*get_sora(t_sora *sora) {
	static t_sora	*__sora;
	if (sora)
		__sora = sora;
	return __sora;
}

void	terror(char *__err__message)
{
	// t_cub3d	*cub;

	putendl_fd(__err__message, 2);
	// cub = get_cub(NULL);
	// destroy_images(cub->imgcontainer);
	// if (cub->img.__img)
	// 	mlx_destroy_image(cub->mlx.__mlx, cub->img.__img);
	// if (cub->mlx.__win)
	// 	mlx_destroy_window(cub->mlx.__mlx, cub->mlx.__win);
	// clearheap(&cub->heap);
	exit(EXIT_FAILURE);
}

int	exit_program(t_sora *sora)
{
	(void)sora;
	exit(EXIT_SUCCESS);
}
