/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:45:47 by somartin          #+#    #+#             */
/*   Updated: 2023/05/09 22:49:57 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"
#include "Printf/ft_printf.h"

void	sa(t_pile *pile)
{
	int	swit;

	swit = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = swit;
	ft_printf("sa\n");
}

void	sb(t_pile *pile)
{
	int	swit;

	swit = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = swit;
	ft_printf("sb\n");
}

void	rotatea(t_pile *pile)
{
	int	tmp;
	int	i;

	tmp = pile->a[0];
	i = 0;
	while (i < pile->size_a - 1)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->a[i] = tmp;
	ft_printf("ra\n");
}

void	rotateb(t_pile *pile)
{
	int	tmp;
	int	i;

	tmp = pile->b[0];
	i = 0;
	while (i < pile->size_b - 1)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->b[i] = tmp;
	ft_printf("rb\n");
}
