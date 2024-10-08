/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:31 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/14 16:34:47 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	ft_rgb(char *path, int *arr)
{
	int		i;
	int		j;
	int		start;
	int		res;
	char	*tmp;

	i = 0;
	start = 0;
	j = -1;
	while (++j < 3)
	{
		while (path[i] != ',' && path[i + 1])
			i++;
		tmp = ft_substr(path, start, i - start);
		res = ft_atoi(tmp);
		free(tmp);
		if (res < 0 || res > 255)
			return (false);
		arr[j] = res;
		if (!path[i] || !path[i + 1])
			break ;
		i++;
		start = i;
	}
	return (true);
}

void	add_path_to_image(t_data *direction, t_mlx *mlx, char *path)
{
	int	w;
	int	h;

	direction->img = mlx_xpm_file_to_image(mlx->mlx, path, &w, &h);
	direction->adr = mlx_get_data_addr(direction->img,
			&direction->bits_px, &direction->line_len,
			&direction->endian);
}

bool	ft_paths(char *id, char *path, t_info *info, t_mlx *mlx)
{
	if (!id)
		return (false);
	if (ft_is_text_or_color_filled(id, info))
		return (false);
	if (!ft_strcmp(id, "F"))
		return (ft_rgb(path, info->floor));
	else if (!ft_strcmp(id, "C"))
		return (ft_rgb(path, info->ceil));
	if (open(path, O_RDONLY) == -1 || !ft_valid_extension(path, ".xpm"))
		return (false);
	else if (!ft_strcmp(id, "NO") && !info->north.img)
		add_path_to_image(&info->north, mlx, path);
	else if (!ft_strcmp(id, "SO") && !info->south.img)
		add_path_to_image(&info->south, mlx, path);
	else if (!ft_strcmp(id, "WE") && !info->west.img)
		add_path_to_image(&info->west, mlx, path);
	else if (!ft_strcmp(id, "EA") && !info->east.img)
		add_path_to_image(&info->east, mlx, path);
	return (true);
}

bool	ft_verify_identifiers(char *str, t_game *game)
{
	int		i;
	char	*tmp2;
	char	*identifier;
	char	*path;
	bool	result;

	if (!ft_strcmp(str, "\n"))
		return (true);
	tmp2 = ft_get_trimmed_line(str);
	i = 0;
	result = true;
	i = 0;
	while (tmp2[i] && tmp2[i] != ' ')
		i++;
	identifier = ft_substr(tmp2, 0, i);
	while (tmp2[i] && tmp2[i] == ' ')
		i++;
	path = ft_substr(tmp2, i, (ft_strlen(tmp2) - i));
	if (!ft_valid_identifier(identifier, path, game))
		result = false;
	free(tmp2);
	free(path);
	free(identifier);
	return (result);
}
