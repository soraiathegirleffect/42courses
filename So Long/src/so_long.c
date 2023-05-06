/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:27:19 by somartin          #+#    #+#             */
/*   Updated: 2023/05/06 20:50:25 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	t_win	tutorial;

	tutorial = new_program(300, 300, "somartin");
	if (!tutorial.mlx_ptr || !tutorial.win_ptr)
		return (1);
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}
