/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:48:43 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/19 18:49:32 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fr_free_ray(t_ray *rays)
{
	t_ray	*tmp;

	while (rays != NULL)
	{
		tmp = rays->next;
		free(rays);
		rays = tmp;
	}
	free(rays);
}

void	ft_free_double_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_mlx(t_game *game)
{
	(void)game;
	mlx_destroy_image(game->mlx->mlx, game->mlx->map.img);
	if (game->info->north.img)
		mlx_destroy_image(game->mlx->mlx, game->info->north.img);
	if (game->info->south.img)
		mlx_destroy_image(game->mlx->mlx, game->info->south.img);
	if (game->info->east.img)
		mlx_destroy_image(game->mlx->mlx, game->info->east.img);
	if (game->info->west.img)
		mlx_destroy_image(game->mlx->mlx, game->info->west.img);
	if (game->mlx->win_ptr)
		mlx_destroy_window(game->mlx->mlx, game->mlx->win_ptr);
	if (game->mlx->mlx)
	{
		mlx_destroy_display(game->mlx->mlx);
		free(game->mlx->mlx);
	}
}
