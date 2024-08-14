/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:41 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/14 16:43:51 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_moves(t_game *game)
{
	t_moves	*moves;

	moves = malloc(sizeof(t_moves));
	moves->w_press = 0;
	moves->s_press = 0;
	moves->a_press = 0;
	moves->d_press = 0;
	moves->left_press = 0;
	moves->right_press = 0;
	game->moves = moves;
}

void	ft_init_textures(t_info *info)
{
	memset(&info->north, 0, sizeof(t_data));
	memset(&info->south, 0, sizeof(t_data));
	memset(&info->west, 0, sizeof(t_data));
	memset(&info->east, 0, sizeof(t_data));
}

void	ft_init_map(t_map *map)
{
	map->n_col = 0;
	map->n_lines = 0;
	map->is_allocated = 0;
}

void	ft_init_colors(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		info->floor[i] = -1;
		info->ceil[i] = -1;
	}
}

void	ft_initializer(t_game *game)
{
	t_info		*info;
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;

	info = malloc(sizeof(t_info));
	map = malloc(sizeof(t_map));
	mlx = malloc(sizeof(t_mlx));
	player = malloc(sizeof(t_player));
	create_rays(game);
	mlx->mlx = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx, SCREEN_WIDHT,
			SCREEN_HEIGHT, "Cub3D");
	game->info = info;
	game->map = map;
	game->mlx = mlx;
	game->player = player;
	player->n_player = 0;
	ft_init_colors(game->info);
	ft_init_textures(game->info);
	ft_init_moves(game);
	ft_init_map(game->map);
	game->is_empty_file = false;
}
