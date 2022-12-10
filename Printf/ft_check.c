/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:01:41 by somartin          #+#    #+#             */
/*   Updated: 2022/12/10 12:39:33 by somartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long int n, char *base)
{
	long int	blen;
	int			c;

	c = 0;
	blen = (long int)ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		c++;
	}
	if (n >= 0 && n < blen)
	{
		ft_putchar(base[n]);
		c++;
	}
	else if (n >= blen)
	{
		c = c + ft_putnbr_base(n / blen, base);
		c = c + ft_putnbr_base(n % blen, base);
	}
	return (c);
}

int	ft_putptr(va_list args)
{
	size_t	p;

	p = va_arg(args, size_t);
	if (!p)
		return (ft_putstr("(nil)"));
	else
		return (ft_putstr("0x") + ft_putptr_base(p, "0123456789abcdef"));
}

int	ft_putptr_base(size_t n, char *base)
{
	size_t	blen;
	int		c;

	c = 0;
	blen = ft_strlen(base);
	if (n < blen)
	{
		ft_putchar(base[n]);
		c++;
	}
	else if (n >= blen)
	{
		c = c + ft_putptr_base(n / blen, base);
		c = c + ft_putptr_base(n % blen, base);
	}
	return (c);
}
