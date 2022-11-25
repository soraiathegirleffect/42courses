/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:22:14 by somartin          #+#    #+#             */
/*   Updated: 2022/11/25 19:06:46 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (str + i);
	while (i != 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	if (s[0] == (char)c)
		return (str);
	return (0);
}
