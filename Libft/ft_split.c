/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:11:55 by somartin          #+#    #+#             */
/*   Updated: 2022/11/20 17:59:31 by somartin         ###   ########.fr       */
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
	int		end;
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
		end = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > end)
		{
			str[k] = ft_substr(s, end, i - end);
			k++;
		}
	}
	str[k] = NULL;
	return (str);
}
