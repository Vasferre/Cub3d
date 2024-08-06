#include "../../includes/cub3d.h"

void colision(double x_value, double y_value, t_game *game)
{
    int x;
    int y;

    x = (int)x_value;
    y = (int)y_value;
    if(game->map->map_array[y][x] &&(game->map->map_array[y][x] == '0' ||
        player_check(game->map->map_array[y][x])))
    {
        game->player->x = x_value;
        game->player->y = y_value;
    }
}

bool ft_cardinal_dir(int key_code, t_player *player, t_game *game)
{
    double angle;
    double x_value;
    double y_value;

    angle = round(player->angle);
    if(angle == 0 || angle == 90 || angle == 180 || angle == 270)
        return(false);
    x_value = player->p_x * PLAYER_SPEED;
    y_value = player->p_y * PLAYER_SPEED;
    if (key_code == A)
        colision(player->x - x_value, player->y - y_value, game);
    if (key_code == D)
        colision(player->x + x_value, player->y - y_value, game);
    return(true);
}

void    ft_movement(t_player *player, int key_code, t_game *game)
{
    double angle;
    double x_value;
    double y_value;

    angle = round(player->angle);
    x_value = player->dir_x * PLAYER_SPEED;
    y_value = player->dir_y * PLAYER_SPEED;
    if (key_code == W)
        colision(player->x + x_value, player->y - y_value, game);
    else if (key_code == S)
        colision(player->x - x_value, player->y - y_value, game);
    else if (!ft_cardinal_dir(key_code, player, game))
    {
        if((key_code == A && angle == 0) || (key_code == D && angle == 180))
            colision(player->x, player->y - PLAYER_SPEED / 2, game);
        if((key_code == A && angle == 90) || (key_code == D && angle == 270))
            colision(player->x - PLAYER_SPEED / 2, player->y, game);
        if((key_code == A && angle == 180) || (key_code == D && angle == 0))
            colision(player->x, player->y + PLAYER_SPEED / 2, game);
        if((key_code == A && angle == 270) || (key_code == D && angle == 90))
            colision(player->x + PLAYER_SPEED / 2, player->y, game);
    }
}

void ft_rotation(t_player *player, int key_code)
{
    double old_dirx;
    double old_planex;
    double rotation;

    old_dirx = player->dir_x;
    old_planex = player->p_x;
    rotation = PLAYER_SPEED;
    if (key_code == LEFT)
        rotation *= -1;
    player->dir_x = old_dirx * cos(rotation) - player->dir_y * sin(rotation);
    player->dir_x = old_dirx * sin(rotation) - player->dir_y * cos(rotation);
    player->p_x = old_planex * cos(rotation) - player->p_y
        * sin(rotation);
    player->p_y = old_planex * sin(rotation) + player->p_y
        * cos(rotation);
    player->angle = acos(player->dir_x) * (180 / PI);
    if(player->dir_y > 0)
        player->angle = (double)(360 - player->angle);
    if(round(player->angle) == 360)
        player->angle = 0;
}

void hooks(t_game *game)
{
    (void)game;
    /* mlx_hook(game->mlx->win_ptr, 2 ,1L << 0, key_press, game);
    mlx_hook(game->mlx->win_ptr, 3, 1L << 1, key_press, game);
    mlx_hook(game->mlx->win_ptr, 17, (1L << 2), quit_cub, game);
    mlx_loop_hook(game->mlx->mlx, ft_render_map, game);
    mlx_loop(game->mlx->mlx); */
}