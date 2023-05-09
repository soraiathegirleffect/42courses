/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:45:58 by somartin          #+#    #+#             */
/*   Updated: 2023/05/09 22:50:15 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"
#include "Printf/ft_printf.h"

void	revrotatea(t_pile *pile)
{
	int	tmp;
	int	i;

	i = pile->size_a - 1;
	tmp = pile->a[i];
	while (i > 0)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[0] = tmp;
	ft_printf("rra\n");
}

void	revrotareb(t_pile *pile)
{
	int	tmp;
	int	i;

	i = pile->size_b - 1;
	tmp = pile->b[i];
	while (i > 0)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[0] = tmp;
	ft_printf("rrb\n");
}

void	pb(t_pile *pile)
{
	int	i;

	if (pile->size_a)
	{
		pile->size_b++;
		i = pile->size_b - 1;
		while (i > 0)
		{
			pile->b[i] = pile->b[i - 1];
			i--;
		}
		pile->b[0] = pile->a[0];
		pile->size_a--;
		i = -1;
		while (++i < pile->size_a)
			pile->a[i] = pile->a[i + 1];
		ft_printf("pb\n");
	}
	else
		return ;
}

void	pa(t_pile *pile)
{
	int	i;

	if (pile->size_b)
	{
		pile->size_a++;
		i = pile->size_a - 1;
		while (i > 0)
		{
			pile->a[i] = pile->a[i - 1];
			i--;
		}
		pile->a[0] = pile->b[0];
		pile->size_b--;
		i = -1;
		while (++i < pile->size_b)
			pile->b[i] = pile->b[i + 1];
		ft_printf("pa\n");
	}
	else
		return ;
}
