/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasco <vasco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:48:33 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/16 02:53:32 by vasco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_panic(t_game *game)
{
	free(game->player);
	fr_free_ray(game->rays);
	ft_free_mlx(game);
	free(game->info);
	if (game->map->is_allocated)
		ft_free_double_arr(game->map->map_array);
	free(game->mlx);
	free(game->map);
	free(game->moves);
	free(game);
	unlink(MAP);
	return (0);
}
