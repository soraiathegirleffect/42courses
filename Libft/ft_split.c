/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:11:55 by somartin          #+#    #+#             */
/*   Updated: 2022/11/26 17:39:03 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	counter(char const *str, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			counter++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		start;
	int		k;

	i = 0;
	k = 0;
	str = malloc(sizeof(char **) * (counter(s, c) + 1));
	if (!s || !str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			str[k] = ft_substr(s, start, i - start);
			k++;
		}
	}
	str[k] = NULL;
	return (str);
}
