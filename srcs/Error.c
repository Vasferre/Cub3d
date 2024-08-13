#include "../includes/cub3d.h"

void ft_mperror(char *error, t_game *game)
{
    write(2, "Error\n", 6);
    write(2, error, ft_strlen(error));
    write(2, "\n", 1);
    ft_panic(game);
    exit(1);
}