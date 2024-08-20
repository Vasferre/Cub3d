/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrichard <mrichard@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:49:10 by vasferre          #+#    #+#             */
/*   Updated: 2024/08/20 17:55:32 by mrichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_spaces_or_tabs(char *line, t_game *game)
{
	if (line[0] == ' ' || line[0] == '\t')
		ft_mperror("Invalid spaces or tabs", game);
}

void	get_textures(t_game *game, char *line, int fd)
{
	char	*tmp;
	int		copy_map;

	copy_map = 0;
	while (line)
	{
		game->is_empty_file = false;
		ft_spaces_or_tabs(line, game);
		tmp = ft_strtrim(line, " ");
		if ((tmp[0] == '\n' && copy_map == 1) || ((ft_isdigit(tmp[0])
					|| tmp[0] == ' ') && ft_str_is_map_type(line)))
		{
			if (!ft_isinfo_complete(game->info))
				ft_mperror("wrong texture or color", game);
			copy_map = 1;
			ft_add_map_file(line);
		}
		else if (!ft_verify_identifiers(tmp, game) && ft_strcmp(tmp, "\n"))
			ft_mperror("wrong texture or color", game);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

bool	ft_is_valid_file(char *str, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (false);
	game->is_empty_file = true;
	line = get_next_line(fd);
	get_textures(game, line, fd);
	close(fd);
	if (game->is_empty_file)
		return (false);
	return (true);
}

void	ft_initial_validation(char *str, t_game *game)
{
	if (!ft_valid_extension(str, ".cub"))
		ft_mperror("invalid extension", game);
	if (!ft_is_valid_file(str, game))
		ft_mperror("invalid file", game);
	if (!ft_is_valid_map(game))
		ft_mperror("invalid map", game);
}
