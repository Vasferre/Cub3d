/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:35 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/19 19:05:01 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (printf("Error\n"));
	game = malloc(sizeof(t_game));
	ft_initializer(game);
	ft_create_map_image(game->mlx);
	ft_initial_validation(argv[1], game);
	ft_render_map(game);
	hooks(game);
	quit_cub(game);
}
