/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:48:28 by somartin          #+#    #+#             */
/*   Updated: 2023/05/09 23:01:42 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "Printf/ft_printf.h"
#include <stdlib.h>

int	ps_strlen(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

void	error(int *pile)
{
	free(pile);
	ft_printf("Error\n");
	exit (1);
}

int	ps_atoi(const char *str, int *pile)
{
	int	i;
	int	sign;
	unsigned int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		error(pile);
	if ((result > 2147483648 && sign == -1)
		|| (result > 2147483647 && sign == 1))
		error(pile);
	return (result * sign);
}

void	dupecheck(int *pile, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (pile[i] == pile[j])
				error(pile);
			j++;
		}
		i++;
		j = i + 1;
	}
}
