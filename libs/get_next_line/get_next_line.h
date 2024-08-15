/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:04:35 by riolivei-         #+#    #+#             */
/*   Updated: 2023/10/19 17:48:05 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_find_newline(char *ptr);
// size_t	ft_strlen(const char *s);
char	*ft_join_stash(char *stash, char *buffer);
char	*get_next_line(int fd);

#endif