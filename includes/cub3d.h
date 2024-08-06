#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/mlx/mlx.h"
#include "../libs/get_next_line/get_next_line.h"

#define ESC 65307
#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363
#define MAP "map_file"

#define SCREEN_WIDHT 1920
#define SCREEN_HEIGHT 1080
#define TILE_SOZE 30
#define FOV 60
#define ROTATION_SPEED 0.045
#define MAX 1e30
#define PLAYER_SPEED 2
#define PI 3.14159265359
#define TRANSPARENCY 0x00980088

typedef struct s_data
{
    void *img;
    char adr;
    int bits_px;
    int line_len;
    int endian;
} t_data; 

typedef struct s_info
{
    t_data north;
    t_data west;
    t_data east;
    t_data south;
    int    ceil[3];
    int    floor[3];

}   t_info;

typedef struct s_player
{
    double x;
    double y;
    double p_x;
    double p_y;
    double dir_x;
    double plane_x;
    double plane_y;
    double dir_y;
    double angle;
    int n_player;
} t_player;

typedef struct s_ray
{
    double ray_dir_x;
    double ray_dir_y;
    double side_x;
    double side_y;
    double delta_x;
    double delta_y;
    double  distance;
    int     step_x;
    int     step_y;
    int     color;
    int     side;
    int     line_height;
    int     draw_start;
    int     draw_end;
    double  texture_step;
    double  texture_pos;
    t_data  xpm_img;
    struct  s_ray   *next;
} t_ray;

typedef struct s_map
{
    char **map_array;
    int is_allocated;
    int n_col;
    int n_lines;
    t_data img[3];
    int map_x;
    int map_y;
}   t_map;

typedef struct s_moves
{
    int w_press;
    int s_press;
    int a_press;
    int d_press;
    int left_press;
    int right_press;
}   t_moves;

typedef struct s_mlx
{
    void *mlx;
    void *mlx_ptr;
    void *win_ptr;
    t_data map;
} t_mlx;

typedef struct s_game
{
    int exit;
    bool    is_empty_file;
    int     hit_wall;
    int     end;
    double  camera_x;
    t_ray *rays;
    t_map *map;
    t_mlx *mlx;
    t_player *player;
    t_moves *moves;
    t_info *info;
}   t_game;

char	*get_next_line(int fd);
void ft_free_text(t_game *game);
void free_all(t_game *game);
void colision(double x_value, double y_value, t_game *game);
bool ft_cardinal_dir(int key_code, t_player *player, t_game *game);
void    ft_movement(t_player *player, int key_code, t_game *game);
void ft_rotation(t_player *player, int key_code);
void hooks(t_game *game);
bool player_check(char c);
void ft_spaces_or_tabs(char *line);
void ft_replace(t_map *map, int i, int *j);
void get_map_array(t_map *mao, int map_file);
void ft_map_array(t_map *map);
void ft_mperror(char *error);
void	ft_init_moves(t_game *game);
int quit_cub(t_game *game);
int handle_keys(int key, int flag,  t_moves *moves);
int key_press(int key, t_game *game);
int key_release(int key, t_game *game);
void ft_moves(t_game *game, t_player *player, t_moves *moves);
void	ft_ray_length(t_ray *ray);
void ft_rays(t_ray *ray, t_player *player, t_map *map);
void	until_hits_wall(t_game *game, t_ray *ray, t_map *map);
void	ft_algorithm(t_game *game, t_ray *ray, t_map *map);
int	ft_render_map(t_game *game);
int extension_verif(char *argv);
char	*get_next_line(int fd);
void	ft_initializer(t_game *game);
size_t	ft_strlen(const char *str);
t_ray	*last_ray(t_ray *lst);
void	add_ray(t_ray **lst, t_ray *new);
void	create_rays(t_game *game);
void	ft_cast_rays(t_game *game);
void	ft_init_ray(t_game *game, t_player *player, int i);
int	ft_get_pixel(t_data img, int x, int y);
void	ft_create_map_image(t_mlx *mlx);
int	ft_create_argb(int transparency, int r, int g, int b);
int	ft_render_map(t_game *game);

#endif