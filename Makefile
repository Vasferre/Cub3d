
NAME = cub3D
CC = cc -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf
MLXFLAGS = -lm -L ./mlx -lmlx -Ilmlx_linux -lXext -lX11 -lbsd
LIBFT = ./libs/libft/libft.a ./libs/get_next_line/get_next_line.a

SRCS = ./srcs/destroy/free_all.c ./srcs/player/movement.c ./srcs/player/player_check.c \
	./srcs/verifications/file_verif.c ./srcs/verifications/map_verif_utils.c ./srcs/verifications/map_verif.c \
	./srcs/cub3d.c ./srcs/Error.c ./srcs/ft_init.c ./srcs/init_map.c ./srcs/keys.c ./srcs/raycaster.c \
	./srcs/utils.c ./srcs/verifications/valid.c ./srcs/verifications/valid_utils.c ./srcs/destroy/free.c \
	./srcs/verifications/file_verif_utils.c ./srcs/verifications/map_verif_utils2.c ./srcs/ray.c \
	./srcs/rays_utils.c
	   
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) --no-print-directory -C ./mlx
	$(MAKE) --no-print-directory -C ./libs/libft
	$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

.SILENT: