/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:35 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/14 16:41:26 by vasferre         ###   ########.fr       */
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
	ft_panic(game);
}
