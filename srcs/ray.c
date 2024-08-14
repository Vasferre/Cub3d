/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:54 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/14 16:56:38 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_ray	*last_ray(t_ray *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_ray(t_ray **lst, t_ray *new)
{
	t_ray	*tail;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = last_ray(*lst);
	tail->next = new;
}

void	create_rays(t_game *game)
{
	int		i;
	t_ray	*head;
	t_ray	*current;

	i = 0;
	head = new_ray();
	current = head;
	while (++i < SCREEN_WIDHT)
	{
		current = new_ray();
		add_ray(&head, current);
	}
	game->rays = head;
}

t_ray	*new_ray(void)
{
	t_ray	*node;

	node = malloc(sizeof(t_ray));
	if (node == NULL)
		return (NULL);
	node->ray_dir_x = 0;
	node->ray_dir_y = 0;
	node->next = NULL;
	return (node);
}

void	ft_cast_rays(t_game *game)
{
	int		i;
	t_ray	*head;

	head = game->rays;
	i = -1;
	while (++i < SCREEN_WIDHT)
	{
		ft_init_ray(game, game->player, i);
		ft_ray_length(game->rays);
		ft_rays_side_dist(game->rays, game->player, game->map);
		ft_algorithm(game, game->rays, game->map);
		ft_draw(game->rays, game, i);
		game->rays = game->rays->next;
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win_ptr,
		game->mlx->map.img, 0, 0);
	game->rays = head;
}
