/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:09:41 by vasco             #+#    #+#             */
/*   Updated: 2022/11/08 17:55:34 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((n == 0 && !*s2) || !*s2)
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0'
			&& s1[i + j] == s2[j] && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&(s1[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}
