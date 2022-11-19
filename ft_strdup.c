/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:55:29 by somartin          #+#    #+#             */
/*   Updated: 2022/11/13 18:28:21 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	c;
	
	char	*strd;

	c = 0;
	i = ft_strlen(s) + 1;
	strd = malloc(sizeof(char) * i);
	if (!strd)
		return (NULL);
	while (i > c)
	{
		strd[c] = s[c];
		c++;
	}
	strd[c] = '\0';
	return (strd);
}
