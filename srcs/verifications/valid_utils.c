/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:27 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/14 16:34:52 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_get_trimmed_line(char *line)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	if (!ft_strcmp(line, "\n"))
	{
		return (ft_strdup(line));
	}
	tmp = ft_strtrim(line, "\n");
	tmp1 = ft_strtrim(tmp, " ");
	tmp2 = ft_strtrim(tmp1, "\t");
	free(tmp);
	free(tmp1);
	return (tmp2);
}

bool	ft_valid_identifier(char *id, char *path, t_game *game)
{
	if (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO") || !ft_strcmp(id, "WE")
		|| !ft_strcmp(id, "EA") || !ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
	{
		return (ft_paths(id, path, game->info, game->mlx));
	}
	return (false);
}

bool	ft_is_text_or_color_filled(char *id, t_info *info)
{
	if (!ft_strcmp(id, "F"))
		return (ft_is_color_complete(info->floor));
	else if (!ft_strcmp(id, "C"))
		return (ft_is_color_complete(info->ceil));
	else if (!ft_strcmp(id, "NO"))
		return (info->north.img);
	else if (!ft_strcmp(id, "SO"))
		return (info->south.img);
	else if (!ft_strcmp(id, "WE"))
		return (info->west.img);
	else if (!ft_strcmp(id, "EA"))
		return (info->east.img);
	return (false);
}
