#ifndef CUB3D_H
# define CUB3D_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <../libs/mlx/mlx.h>

#define SCREEN_WIDHT 1920;
#define SCREEN_HEIGHT 1080;
#define FOV 60;
#define PLAYER_SPEED 2;


typedef struct s_player
{
    int player_x;
    int player_y;
    int player_left;
    int player_right;
    int player_down;
    int player_up;
} t_player;

typedef struct s_mlx
{
    void mlx_ptr;
} t_mlx;

typedef struct s_game
{
    char **map;
} t_game;
