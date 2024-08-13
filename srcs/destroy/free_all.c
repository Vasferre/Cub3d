#include "../../includes/cub3d.h"

void ft_free_text(t_game *game)
{
    (void)game;
    if (game->info->north.img)
        mlx_destroy_image(game->mlx->mlx, game->info->north.img);
    if (game->info->west.img)
        mlx_destroy_image(game->mlx->mlx, game->info->west.img); 
    if (game->info->east.img)
        mlx_destroy_image(game->mlx->mlx, game->info->east.img); 
    if (game->info->south.img)
       mlx_destroy_image(game->mlx->mlx, game->info->south.img);
}

void free_all(t_game *game)
{
    if (!game)
        return ;
    ft_free_text(game);
    if (game->mlx->win_ptr)
        mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
    if(game->mlx->mlx_ptr)
    {
        mlx_destroy_display(game->mlx->mlx_ptr);
        free(game->mlx->mlx_ptr);
    }
}

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