/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:09:59 by somartin          #+#    #+#             */
/*   Updated: 2023/01/12 20:25:06 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	next_line = ft_strjoin(0, buff[fd]);
	if (ft_clean(buff[fd]) > 0)
		return (next_line);
	i = read(fd, buff[fd], BUFFER_SIZE);
	if (i < 0)
	{
		free(next_line);
		return (NULL);
	}
	while (i > 0)
	{
		next_line = ft_strjoin(next_line, buff[fd]);
		if (ft_clean(buff[fd]) > 0)
			break ;
		i = read(fd, buff[fd], BUFFER_SIZE);
	}
	return (next_line);
}
