/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:32:58 by somartin          #+#    #+#             */
/*   Updated: 2022/12/04 19:59:52 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkprintf(char str, va_list args)
{
	if (str == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (str == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (str == 'd' || str == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	if (str == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	if (str == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (str == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (str == '%')
		return (ft_putchar(str));
	if (str == 'p')
		return (ft_putpointer(args));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_checkprintf(str[i], args);
			i++;
		}
		else
			len = len + ft_putchar(str[i++]);
	}
	va_end(args);
	return (len);
}