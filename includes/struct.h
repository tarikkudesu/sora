
#ifndef STRUCT
# define STRUCT


typedef struct s_sora			t_sora;
typedef struct s_image			t_image;
typedef struct s_mlx			t_mlx;
typedef enum e_hooks			t_hooks;
typedef struct s_player			t_player;
typedef struct s_vect			t_vect;
typedef struct s_color			t_color;

struct	s_vect
{
	double	x;
	double	y;
};

struct	s_color
{
	int	red;
	int	green;
	int	blue;
};

struct s_player {
	int	x, y;
	int tar_x, tar_y;
	int back_x, back_y;
};

enum e_hook
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

struct s_image
{
	void	*__img;
	int		*__addr;
	int		pixel_bits;
	int		line_bytes;
	int		width;
	int		height;
	int		endian;
};

struct s_mlx
{
	void	*__mlx;
	void	*__win;
	// void	*__intro;
	// void	*__menu;
};

struct s_sora {
	t_mlx			mlx;
	t_image			img;
	t_image			coll;
	t_image			indicator;
	t_image			back[5];
	t_image			player;
	t_image			intro;
	t_player		me;
	int				pos[2];
	int				des[5][2];
	unsigned int	colors[5];
	int				*path;
	bool			mouse_pressed;
	bool			mode;
	int				currTex;
	int 			background[800][1200];
	struct timeval	last_update;
};

#endif