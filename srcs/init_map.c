#include "../includes/cub3d.h"

void	ft_init_ray(t_game *game, t_player *player, int i)
{
	game->map->map_x = (int)player->x;
	game->map->map_y = (int)player->y;
	game->camera_x = 2 * i / (double)SCREEN_WIDHT- 1;
	game->rays->ray_dir_x = player->dir_x
		+ player->plane_x * game->camera_x;
	game->rays->ray_dir_y = player->dir_y + player->plane_y * game->camera_x;
	game->rays->line_height = -1;
	game->hit_wall = 0;
}

int	ft_get_pixel(t_data img, int x, int y)
{
	return (*(unsigned int *)((img.adr
			+ (y * img.line_len) + (x * img.bits_px / 8))));
}

void	ft_create_map_image(t_mlx *mlx)
{
	t_data	map;

	map.img = mlx_new_image(mlx->mlx, SCREEN_WIDHT, SCREEN_HEIGHT);
	map.addr = mlx_get_data_adr(map.img, &map.bits_per_pixel,
			&map.line_len, &map.endian);
	mlx->map = map;
}

int	ft_create_argb(int transparency, int r, int g, int b)
{
	return (transparency << 24 | r << 16 | g << 8 | b);
}

int	ft_render_map(t_game *game)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		if (i < SCREEN_HEIGHT / 2)
			color = ft_create_argb(TRANSPARENCY, game->tinfo->ceil[0],
					game->tinfo->ceil[1], game->tinfo->ceil[2]);
		else
			color = ft_create_argb(TRANSPARENCY, game->tinfo->floor[0],
					game->tinfo->floor[1], game->tinfo->floor[2]);
		while (++j < SCREEN_WIDTH)
			my_mlx_pixel_put(&game->mlx->map, j, i, color);
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->mlx->map.img, 0, 0);
	ft_cast_rays(game);
	ft_render_mini_map(game->mlx, game->map, game->player, game->rays);
	ft_movements(game, game->player, game->moves);
	return (0);
}