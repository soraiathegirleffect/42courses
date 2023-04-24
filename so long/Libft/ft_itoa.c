/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:12:06 by somartin          #+#    #+#             */
/*   Updated: 2022/11/20 17:08:07 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_digit(int nn)
{
	int	c;

	c = 0;
	if (nn == 0)
		return (1);
	if (nn < 0)
		c++;
	while (nn != 0)
	{
		nn = nn / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	long int		nb;

	nb = n;
	size = number_digit(nb);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	if (nb == 0)
		str[0] = '0';
	str[size] = '\0';
	while (nb != 0)
	{
		str[size - 1] = (nb % 10) + 48;
		nb = nb / 10;
		size--;
	}
	return (str);
}
