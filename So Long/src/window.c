/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:23:05 by somartin          #+#    #+#             */
/*   Updated: 2023/04/30 16:37:54 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window (mlx_ptr, w, h, str), w, h});
}
