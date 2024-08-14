/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:50:00 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/14 16:57:19 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_single_ray(t_ray *rays, t_mlx *mlx, double x, double y)
{
	int	pixels;

	pixels = 50;
	while (pixels)
	{
		mlx_pixel_put(mlx->mlx, mlx->win_ptr, x, y, 0x000000FF);
		x += rays->ray_dir_x;
		y += rays->ray_dir_y;
		--pixels;
	}
}

t_ray	*skip_rays(t_ray *rays, int n)
{
	int	i;

	i = -1;
	if (!rays->next)
		return (NULL);
	while (++i < n)
	{
		if (!rays->next)
			break ;
		rays = rays->next;
	}
	return (rays);
}

void	print_rays(t_mlx *mlx, t_ray *rays, t_player *player)
{
	int		n_rays;
	int		i;
	double	x;
	double	y;
	t_ray	*head;

	i = -1;
	head = rays;
	n_rays = ((SCREEN_WIDHT / FOV) / 100) * 2;
	x = player->x * SQUARE_SIZE;
	y = (player->y - 0.25) * SQUARE_SIZE;
	while (++i < n_rays)
	{
		if (!rays)
			break ;
		print_single_ray(rays, mlx, x, y);
		rays = skip_rays(rays, n_rays);
	}
	rays = head;
}

void	ft_init_draw_variables(t_game *game, t_ray *ray)
{
	ray->line_height = (int)SCREEN_HEIGHT / ray->distance;
	ray->draw_start = (ray->line_height * -1) / 2 + SCREEN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (ray->side == 0)
		game->info->wall_x = game->player->y
			+ ray->distance * ray->ray_dir_y;
	if (ray->side == 1)
		game->info->wall_x = game->player->x
			+ ray->distance * ray->ray_dir_x;
	game->info->wall_x -= floor(game->info->wall_x);
	game->info->tex_x = (int)(game->info->wall_x * (double)(TEX_WIDTH));
	if ((ray->side == 0 && ray->ray_dir_x > 0))
		game->info->tex_x = TEX_WIDTH - game->info->tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		game->info->tex_x = TEX_WIDTH - game->info->tex_x - 1;
	ray->texture_step = 1.0 * TEX_HEIGHT / ray->line_height;
	ray->texture_pos = (ray->draw_start - SCREEN_HEIGHT
			/ 2 + ray->line_height / 2) * ray->texture_step;
}

void	ft_draw(t_ray *ray, t_game *game, int i)
{
	ft_init_draw_variables(game, ray);
	while (ray->draw_start <= ray->draw_end)
	{
		game->info->tex_y = (int)ray->texture_pos & (TEX_HEIGHT - 1);
		ray->texture_pos += ray->texture_step;
		ray->color = ft_get_pixel(ray->xpm_img,
				game->info->tex_x, game->info->tex_y);
		my_mlx_pixel_put(&game->mlx->map, i, ray->draw_start, ray->color);
		ray->draw_start++;
	}
}
