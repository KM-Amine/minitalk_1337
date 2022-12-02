/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:52:31 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/10 07:53:45 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_len(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*filling_array(char *str, int len, long nbr)
{
	while (nbr > 0)
	{
		len--;
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	nbr = n;
	len = number_len(nbr);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	return (filling_array(str, len, nbr));
}
