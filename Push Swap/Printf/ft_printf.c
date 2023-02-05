/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:32:58 by somartin          #+#    #+#             */
/*   Updated: 2022/12/08 19:12:53 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_checkprintf(char str, va_list args)
{
	if (str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (str == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (str == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (str == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (str == '%')
		return (ft_putchar(str));
	else if (str == 'p')
		return (ft_putptr(args));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

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
