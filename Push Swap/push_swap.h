/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:48:55 by somartin          #+#    #+#             */
/*   Updated: 2023/05/09 22:52:50 by somartin         ###   ########.fr       */
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
}	t_pile;

void	push_swap(char **av);

#endif