#include "../../includes/cub3d.h"

//verifica a extencao do ficheiro
int extension_verif(char *argv)
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

void ft_spaces_or_tabs(char *line)
{
    if (line[0] == ' ' || line[0] == '\t')
        ft_mperror("Invalid spaces or tabs");
}