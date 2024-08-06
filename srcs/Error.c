#include "../includes/cub3d.h"

void ft_mperror(char *error)
{
    write(2, "Error\n", 6);
    write(2, error, ft_strlen(error));
    write(2, "\n", 1);
    exit(1);
}