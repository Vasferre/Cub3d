# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 16:35:56 by vasferre          #+#    #+#              #
#    Updated: 2024/06/21 16:39:30 by vasferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc -Wall -Wextra -Werror
RM = rm -rf
MLXFLAGS = -L ./libs/mlx -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libs/libft/libft.a

SRCS = ./srcs/cub3d.c ./srcs/map_verif.c
	   
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) --no-print-directory -C ./libs/mlx
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