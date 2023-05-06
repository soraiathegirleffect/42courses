/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:02:19 by somartin          #+#    #+#             */
/*   Updated: 2023/05/06 14:02:42 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct all_piles
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	x_pile;

#endif

void	push_swap(char **av);
