#include "../includes/cub3d.h"

t_ray	*last_ray(t_ray *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_ray(t_ray **lst, t_ray *new)
{
	t_ray	*tail;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tail = last_ray(*lst);
	tail->next = new;
}


void	create_rays(t_game *game)
{
	int		i;
	t_ray	*head;
	t_ray	*current;

	i = 0;
	head = new_ray();
	current = head;
	while (++i < SCREEN_WIDTH)
	{
		current = new_ray();
		add_ray(&head, current);
	}
	game->rays = head;
}

void	ft_cast_rays(t_game *game)
{
	int		i;
	t_ray	*head;

	head = game->rays;
	i = -1;
	while (++i < SCREEN_WIDTH)
	{
		ft_init_ray(game, game->player, i);
		ft_set_ray_length(game->rays);
		ft_set_step_and_side_dist(game->rays, game->player, game->map);
		ft_dda_algorithm(game, game->rays, game->map);
		ft_draw(game->rays, game, i);
		game->rays = game->rays->next;
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win,
		game->mlx->map.img, 0, 0);
	game->rays = head;
}