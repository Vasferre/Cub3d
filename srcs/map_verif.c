#include "../includes/cub3d.h"

//verifica a extencao do ficheiro
static int extension_verif(char *argv)
{
    int i;

    if (!argv)
        return (0);
    i = 0;
    while (argv[i])
        i++;
    i -= 1;
    if (argv[i] == 'c' && argv[i - 1] == 'u' && argv[i - 2] == 'b' && argv[i - 3] == '.')
        return (1);
    return (0);
}

static int check_Wall(char **map)
{

}

static int char_check(t_game *game)
{
    int i;
    int j;
}