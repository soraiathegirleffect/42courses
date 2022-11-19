/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:10:59 by somartin          #+#    #+#             */
/*   Updated: 2022/11/13 21:43:41 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*nstr;
	
	i = 0;
	j = 0;
	nstr = (char *)malloc(sizeof(*s) * (len + 1));
	if (nstr == 0)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			nstr[j] = s[i];
			j++;
		}
		i++;
	}
	nstr[j] = '\0';
	return (nstr);
}
