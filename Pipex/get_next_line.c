/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:20:22 by somartin          #+#    #+#             */
/*   Updated: 2023/04/26 18:20:56 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_clean(char *str)
{
	int	i;
	int	j;
	int	is_nl;

	i = 0;
	j = 0;
	is_nl = 0;
	while (str[i])
	{
		if (is_nl == 1)
		{
			str[j] = str[i];
			j++;
		}
		if (str[i] == '\n')
			is_nl = 1;
		str[i] = '\0';
		i++;
	}
	return (is_nl);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next_line = ft_strjoin(0, buff);
	if (ft_clean(buff) > 0)
		return (next_line);
	i = read(fd, buff, BUFFER_SIZE);
	if (i < 0)
	{
		free(next_line);
		return (NULL);
	}
	while (i > 0)
	{
		next_line = ft_strjoin(next_line, buff);
		if (ft_clean(buff) > 0)
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (next_line);
}