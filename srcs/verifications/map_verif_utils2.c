#include "../../includes/cub3d.h"

void	set_y_axis(t_player *player, double plane_x,
	double dir_y, double angle)
{
	player->plane_x = plane_x;
	player->dir_y = dir_y;
	player->angle = angle;
}

void	set_x_axis(t_player *player, double plane_y,
	double dir_x, double angle)
{
	player->plane_y = plane_y;
	player->dir_x = dir_x;
	player->angle = angle;
}

void	get_map_array(t_map *map, int map_file)
{
	int		i;
	int		j;
	char	*line;

	line = get_next_line(map_file);
	i = 0;
	while (line)
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