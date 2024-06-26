#ifndef CUB3D_H
# define CUB3D_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/mlx/mlx.h"

#define SCREEN_WIDHT 1920
#define SCREEN_HEIGHT 1080
#define TILE_SOZE 30
#define FOV 60
#define ROTATION_SPEED 0.045
#define PLAYER_SPEED 2


typedef struct s_player
{
    int player_x;
    int player_y;
    int player_left;
    float rd;
    int rotate;
    int player_right;
    int player_down;
    int player_up;
} t_player;

typedef struct s_ray
{
    double ray_angle;
    double distance;
    int flag;
} t_ray;


typedef struct s_game
{
    char **map;
    int px_map;
    int pt_map;
    int w_map;
    int h_map;
} t_game;

typedef struct s_mlx
{
    mlx_t *mlx_ptr;
    t_ray *ray;
    t_game *game;
    t_player *player;
    mlx_image_t *img;
} t_mlx;

#endif