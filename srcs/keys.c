/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:47 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/14 16:54:42 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	quit_cub(t_game *game)
{
	free_all(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	handle_keys(int key, int flag, t_moves *moves)
{
	if (key == W)
		moves->w_press = flag;
	if (key == S)
		moves->s_press = flag;
	if (key == A)
		moves->a_press = flag;
	if (key == D)
		moves->d_press = flag;
	if (key == LEFT)
		moves->left_press = flag;
	if (key == RIGHT)
		moves->right_press = flag;
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		free_all(game);
	handle_keys(key, 1, game->moves);
	return (0);
}

int	key_release(int key, t_game *game)
{
	handle_keys(key, 0, game->moves);
	return (0);
}

void	ft_moves(t_game *game, t_player *player, t_moves *moves)
{
	if (moves->w_press)
		ft_movement(player, W, game);
	if (moves->s_press)
		ft_movement(player, S, game);
	if (moves->d_press)
		ft_movement(player, D, game);
	if (moves->a_press)
		ft_movement(player, A, game);
	if (moves->left_press)
		ft_rotation(player, LEFT);
	if (moves->w_press)
		ft_rotation(player, RIGHT);
}
