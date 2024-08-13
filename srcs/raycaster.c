#include "../includes/cub3d.h"

void	ft_ray_length(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_x = MAX;
	else
		ray->delta_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_y = MAX;
	else
		ray->delta_y = fabs(1 / ray->ray_dir_y);
}

void ft_rays_side_dist(t_ray *ray, t_player *player, t_map *map)
{
    if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->x - map->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (map->map_x + 1.0 - player->x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->y - map->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (map->map_y + 1.0 - player->y) * ray->delta_y;
	}
}

void	until_hits_wall(t_game *game, t_ray *ray, t_map *map)
{
	while (game->hit_wall == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			map->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			map->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map->map_array[map->map_y][map->map_x] && \
		(map->map_array[map->map_y][map->map_x] != '0' && \
		!player_check(map->map_array[map->map_y][map->map_x])))
			game->hit_wall = 1;
	}
}

void	ft_algorithm(t_game *game, t_ray *ray, t_map *map)
{
	until_hits_wall(game, ray, map);
	if (ray->side == 0)
	{
		if (map->map_x - game->player->x < 0)
			ray->xpm_img = game->info->west;
		else
			ray->xpm_img = game->info->east;
		ray->distance = ray->side_x - ray->delta_x;
	}
	else
	{
		if (map->map_y - game->player->y < 0)
			ray->xpm_img = game->info->north;
		else
			ray->xpm_img = game->info->south;
		ray->distance = ray->side_y - ray->delta_y;
	}
}