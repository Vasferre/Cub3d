#include "../../includes/cub3d.h"

void ft_map_array(t_map *map)
{
    int map_file;
    int i;

    map_file = open(MAP, O_RDONLY);
    map->is_allocated = 1;
    map->map_array = calloc(sizeof(char *), map->n_lines + 1);
    i = -1;
    while (++i < map->n_lines)
        map->map_array[i] = calloc(sizeof(char), map->n_col + 1);
    get_map_array(map, map_file);
    if (map_file > 0)
        close(map_file);
}