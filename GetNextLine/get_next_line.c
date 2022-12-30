/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:31:41 by somartin          #+#    #+#             */
/*   Updated: 2022/12/30 19:43:38 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*int    main(void)
{
    char    *line;
    int        i;
    int        fd;
    fd = open("file1.txt", O_RDONLY);
    i = 1;
    while (i < 7)
    {
        line = get_next_line(fd);
        printf("line [%02d]: %s", i, line);
        free(line);
        i++;
    }
	if (i == -1)
	{
		printf("<ERROR>\n");
		close(fd);
		return (-1);
	}
    close(fd);
    return (0);
}*/
/* gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> 
get_next_line.c get_next_line_utils.c && ./a.out */
