/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasco <vasco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:52:12 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/16 02:13:08 by vasco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libs/get_next_line/get_next_line.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define MAP "map_file"
# define SCREEN_WIDHT 1920
# define SCREEN_HEIGHT 1080
# define TILE_SOZE 30
# define FOV 0.60
# define ROTATION_SPEED 0.1745
# define MAX 1e30
# define PLAYER_SPEED 0.05
# define PI 3.14159265359
# define SQUARE_SIZE 16
# define TRANSPARENCY 0x00980088
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_data
{
	void	*img;
	char	*adr;
	int		bits_px;
	int		line_len;
	int		endian;
}			t_data;

typedef struct s_info
{
	t_data	north;
	t_data	west;
	t_data	east;
	t_data	south;
	double	wall_x;
	int		ceil[3];
	int		floor[3];
	int		tex_x;
	int		tex_y;

}			t_info;

typedef struct s_player
{
	double	x;
	double	y;
	double	p_x;
	double	p_y;
	double	dir_x;
	double	dir_y;
	double	angle;
	int		n_player;
}			t_player;

typedef struct s_ray
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	double			distance;
	int				step_x;
	int				step_y;
	int				color;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			texture_step;
	double			texture_pos;
	t_data			xpm_img;
	struct s_ray	*next;
}					t_ray;

typedef struct s_map
{
	char	**map_array;
	int		is_allocated;
	int		n_col;
	int		n_lines;
	t_data	img[3];
	int		map_x;
	int		map_y;
}			t_map;

typedef struct s_moves
{
	int	w_press;
	int	s_press;
	int	a_press;
	int	d_press;
	int	left_press;
	int	right_press;
}		t_moves;

typedef struct s_mlx
{
	void	*mlx;
	void	*win_ptr;
	t_data	map;
}			t_mlx;

typedef struct s_game
{
	int			exit;
	bool		is_empty_file;
	int			hit_wall;
	int			end;
	double		camera_x;
	t_ray		*rays;
	t_map		*map;
	t_mlx		*mlx;
	t_player	*player;
	t_moves		*moves;
	t_info		*info;
}				t_game;

char	*get_next_line(int fd);
int		ft_panic(t_game *game);
void	fr_free_ray(t_ray *rays);
void	ft_map_array(t_map *map);
void	ft_free_text(t_game *game);
void	ft_initial_validation(char *str, t_game *game);
void	ft_free_mlx(t_game *game);
t_ray	*skip_rays(t_ray *rays, int n);
void	print_rays(t_mlx *mlx, t_ray *rays, t_player *player);
int		ft_strcmp(char *s1, char *s2);
void	ft_free_double_arr(char **arr);
void	ft_init_draw_variables(t_game *game, t_ray *ray);
void	ft_draw(t_ray *ray, t_game *game, int i);
void	set_y_axis(t_player *player, double plane_x,
			double dir_y, double angle);
void	print_single_ray(t_ray *rays, t_mlx *mlx, double x, double y);
void	set_x_axis(t_player *player, double plane_y,
			double dir_x, double angle);
void	add_path_to_image(t_data *direction, t_mlx *mlx, char *path);
bool	ft_add_rgb(char *path, int *arr);
void	free_all(t_game *game);
bool	ft_isinfo_complete(t_info *info);
char	*ft_get_trimmed_line(char *line);
bool	ft_valid_identifier(char *id, char *path, t_game *game);
void	ft_init_player_direction(char c, t_player *player);
void	colision(double x_value, double y_value, t_game *game);
bool	ft_verify_identifiers(char *str, t_game *game);
bool	ft_cardinal_dir(int key_code, t_player *player, t_game *game);
bool	ft_paths(char *id, char *path, t_info *info, t_mlx *mlx);
void	ft_movement(t_player *player, int key_code, t_game *game);
void	ft_rotation(t_player *player, int key_code);
void	hooks(t_game *game);
bool	player_check(char c);
bool	ft_is_text_or_color_filled(char *id, t_info *info);
bool	ft_add_map_file(char *line);
void	ft_spaces_or_tabs(char *line, t_game *game);
void	ft_replace(t_map *map, int i, int *j);
void	get_map_array(t_map *map, int map_file);
void	ft_map_array(t_map *map);
t_ray	*new_ray(void);
bool	ft_check_all_sides(t_map *map, int y, int x);
bool	ft_init_player(char c, int x, int y, t_player *player);
void	ft_mperror(char *error, t_game *game);
void	ft_init_moves(t_game *game);
bool	ft_str_is_map_type(char *str);
bool	ft_is_valid_map(t_game *game);
int		quit_cub(t_game *game);
bool	ft_check_map(t_map *map, t_player *player);
int		handle_keys(int key, int flag, t_moves *moves);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
void	ft_moves(t_game *game, t_player *player, t_moves *moves);
void	ft_ray_length(t_ray *ray);
void	ft_rays_side_dist(t_ray *ray, t_player *player, t_map *map);
void	until_hits_wall(t_game *game, t_ray *ray, t_map *map);
void	ft_algorithm(t_game *game, t_ray *ray, t_map *map);
int		ft_render_map(t_game *game);
bool	ft_isinfo_complete(t_info *info);
void	ft_fill_and_replace(t_map *map, int i, int *j);
bool	ft_valid_extension(char *str, char *extension);
char	*get_next_line(int fd);
void	ft_initializer(t_game *game);
size_t	ft_strlen(const char *str);
bool	ft_is_color_complete(int *color);
t_ray	*last_ray(t_ray *lst);
void	add_ray(t_ray **lst, t_ray *new);
void	create_rays(t_game *game);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_cast_rays(t_game *game);
void	ft_init_ray(t_game *game, t_player *player, int i);
int		ft_get_pixel(t_data img, int x, int y);
void	ft_create_map_image(t_mlx *mlx);
int		ft_create_argb(int transparency, int r, int g, int b);
bool	ft_map_file(t_map *map);

#endif