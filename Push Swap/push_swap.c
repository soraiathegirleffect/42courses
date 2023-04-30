/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:08:11 by somartin          #+#    #+#             */
/*   Updated: 2023/04/30 15:46:56 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

void	push_swap(char **av)
{
	x_piles		pile; /* Declare pile as type x_piles */
	int			size;
	int			i;
	
	i = 1;
	size = ps_strlen(av);
	pile.a = malloc(size * sizeof(int)); /* pile.specification */
	if (!pile.a)
		return 0;
	pile.size_a = size;
	pile.b = malloc(size * sizeof(int));
	if (!pile.b)
	{
		free(pile.a);
		return 0;
	}
	pile.size_b = 0;
	while (i++ < size)
		pile.a[i] = ps_atoi(av[i], pile.a);
	dupecheck(pile.a, size);
	sort(&pile, size);
	free(pile.a);
	free(pile.b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		push_swap(av);
		return (0);
	}
	return (0);
}
