/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:23 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/19 19:01:05 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_map_array(t_map *map)
{
	int		map_file;
	int		i;

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

void	ft_init_player_direction(char c, t_player *player)
{
	if (c == 'N' || c == 'S')
	{
		player->p_y = 0;
		player->dir_x = 0;
		if (c == 'N')
			set_y_axis(player, FOV, -1, 90);
		else
			set_y_axis(player, -FOV, 1, 270);
	}
	else
	{
		player->p_x = 0;
		player->dir_y = 0;
		if (c == 'W')
			set_x_axis(player, -FOV, -1, 180);
		else
			set_x_axis(player, FOV, 1, 0);
	}
}

bool	ft_init_player(char c, int x, int y, t_player *player)
{
	if (player_check(c))
	{
		if (++player->n_player > 1)
			return (false);
		player->x = (double)x + 0.50;
		player->y = (double)y + 0.50;
		ft_init_player_direction(c, player);
	}
	return (true);
}

bool	ft_map_file(t_map *map)
{
	int		map_file;
	char	*line;
	int		i;

	map_file = open(MAP, O_RDONLY);
	if (map_file < 0)
		return (false);
	line = get_next_line(map_file);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (i > map->n_col)
			map->n_col = i;
		map->n_lines++;
		free(line);
		line = get_next_line(map_file);
	}
	ft_map_array(map);
	close(map_file);
	printf("TESTE\n");
	return (true);
}

bool	ft_add_map_file(char *line)
{
	int	map_file;

	map_file = open(MAP, O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
	if (map_file < 0)
		return (false);
	while (*line)
	{
		if (*line == '\t')
			write(map_file, "    ", 4);
		else
			write(map_file, line, 1);
		line++;
	}
	close(map_file);
	return (true);
}
