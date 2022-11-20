/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:07:00 by somartin          #+#    #+#             */
/*   Updated: 2022/11/20 18:29:45 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*auxiliar;

	if (!*lst)
		return ;
	while (*lst)
	{
		auxiliar = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = auxiliar;
	}
	free(*lst);
}
