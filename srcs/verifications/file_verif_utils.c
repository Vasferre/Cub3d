#include "../../includes/cub3d.h"

bool	ft_valid_extension(char *str, char *extension)
{
	int	ext_len;
	int	str_len;
	int	i;

	ext_len = ft_strlen(extension);
	str_len = ft_strlen(str);
	i = 0;
	while (i++ < str_len - ext_len)
		str++;
	if (ft_strncmp(str, extension, ext_len) == 0)
		return (true);
	return (false);
}

bool	ft_is_color_complete(int *color)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (color[i] == -1)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_isinfo_complete(t_info *info)
{
	if (!info->north.adr || !info->south.adr || !info->west.adr
		|| !info->east.adr || !ft_is_color_complete(info->floor)
		|| !ft_is_color_complete(info->ceil))
		return (false);
	return (true);
}