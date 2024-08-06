#include "../../includes/cub3d.h"

void ft_replace(t_map *map, int i, int *j)
{
    int index;

    index = -1;
    while(map->map_array[i][++index])
    {
        if (map->map_array[i][index] == ' ')
            map->map_array[i][index] = '0';
    }
    while(*j < map->n_col)
        map->map_array[i][(*j)++] = '-';
}

void get_map_array(t_map *map, int map_file)
{
    int i;
    int j;
    char *line;

    line = get_next_line(map_file);
    i = 0;
    while(line)
    {
        j = 0;
        while (line[j] && line[j] != '\n')
        {
            map->map_array[i][j] = line[j];
            j++;
        }
        ft_replace(map, i, &j);
        map->map_array[i][j] = '\0';
        free(line);
        i++;
        line = get_next_line(map_file);
    }
    free(line);
}