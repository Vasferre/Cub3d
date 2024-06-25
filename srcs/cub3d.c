#include "../includes/cub3d.h"

void loop_game(void *ml)
{
    t_mlx *mlx;

    mlx = ml;
    mlx_delete_image(mlx->mlx_ptr, mlx->img);
    mlx->img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDHT, SCREEN_HEIGHT);
    hook(mlx, 0, 0);
    cast_rays(mlx);
    mlx_image_to_window(mlx->mlx_ptr, mlx->img, 0, 0);
}



int main ()