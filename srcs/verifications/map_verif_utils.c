/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:15 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/15 17:14:13 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_replace(t_map *map, int i, int *j)
{
	int	index;

	index = -1;
	while (map->map_array[i][++index])
	{
		if (map->map_array[i][index] == ' ')
			map->map_array[i][index] = '0';
	}
	while (*j < map->n_col)
		map->map_array[i][(*j)++] = '-';
}

bool	ft_str_is_map_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != ' '
			&& !player_check(str[i]) && str[i] != '\n' && str[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_sides(t_map *map, int y, int x)
{
	if (y == 0 || y == map->n_lines - 1 || x == 0 || x == map->n_col - 1)
		return (false);
	if (map->map_array[y - 1][x] == '-' || map->map_array[y + 1][x] == '-'
		|| map->map_array[y][x - 1] == '-' || map->map_array[y][x + 1] == '-')
		return (false);
	return (true);
}

bool	ft_is_valid_map(t_game *game)
{
	if (!ft_map_file(game->map))
		return (false);
	if (!ft_check_map(game->map, game->player))
		return (false);
	return (true);
}

bool	ft_check_map(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (player_check(map->map_array[i][j])
				|| map->map_array[i][j] == '0')
			{
				if (!ft_check_sides(map, i, j)
					|| !ft_init_player(map->map_array[i][j], j, i, player))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (player->n_player != 0);
}
