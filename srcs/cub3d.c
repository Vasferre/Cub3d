#include "../includes/cub3d.h"
int main(int argc, char **argv) // main function
{
    t_game *game;
    (void) argv;

    if (argc != 2)
        ft_mperror("Error\n");
    game = malloc(sizeof(t_game));
    ft_initializer(game);
}