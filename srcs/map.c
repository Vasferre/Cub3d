#include "../includes/cub3d.h"

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
			color = ft_create_argb(TRANSPARENCY, game->info->ceil[0],
					game->info->ceil[1], game->info->ceil[2]);
		else
			color = ft_create_argb(TRANSPARENCY, game->info->floor[0],
					game->info->floor[1], game->info->floor[2]);
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