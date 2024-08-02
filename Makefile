SRC		=	./srcs/key_down.c  \
./srcs/key_up.c  \
./srcs/main.c  \
./srcs/mouse_move.c  \
./srcs/mouse_press.c  \
./srcs/mouse_release.c  \
./srcs/sora.c  \
./srcs/terror.c  \
./srcs/update_frame.c  \
./srcs/window.c \
./srcs/put_player.c \
./srcs/indicator.c \
./srcs/update_pos.c

OBJ			=	$(SRC:.c=.o)
NAME		=	sora
MLXFLAGS	=	mlx/libmlx.a -framework OpenGL -framework AppKit

all: $(NAME) clean

$(NAME): $(OBJ)
	@cc -Wall -Wextra -Werror -g -fsanitize=address $(OBJ) -o $(NAME) $(MLXFLAGS)

%.o: %.c ./includes/macros.h ./includes/sora.h ./includes/struct.h 
	@cc -Wall -Wextra -Werror -g -fsanitize=address -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
