/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:52:58 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/02 11:57:46 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

void	ft_puthex(unsigned int i, int *len, char *base)
{
	if (i > 15)
		ft_puthex(i / 16, len, base);
	ft_putchar(base[i % 16], len);
}

static void	ft_putsubptr(unsigned long long i, int *len, char *base)
{
	if (i > 15)
		ft_putsubptr(i / 16, len, base);
	ft_putchar(base[i % 16], len);
}

void	ft_putptr(unsigned long long i, int *len)
{
	ft_putstr("0x", len);
	ft_putsubptr(i, len, "0123456789abcdef");
}

static void	ft_format(char c, va_list ptr, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(ptr, int), len);
	else if (c == 's')
		ft_putstr(va_arg(ptr, char *), len);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(ptr, int), len);
	else if (c == 'u')
		ft_putuns(va_arg(ptr, unsigned int), len);
	else if (c == 'x')
		ft_puthex(va_arg(ptr, unsigned int), len, "0123456789abcdef");
	else if (c == 'X')
		ft_puthex(va_arg(ptr, unsigned int), len, "0123456789ABCDEF");
	else if (c == 'p')
		ft_putptr(va_arg(ptr, unsigned long long), len);
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &len);
		else
		{
			i++;
			ft_format(str[i], ptr, &len);
		}
		i++;
	}
	va_end(ptr);
	return (len);
}
