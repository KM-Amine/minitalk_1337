/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mkhellou < mkhellou@student.1337.ma>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:29:32 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/25 19:09:07 by  mkhellou        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	number_creator(const char *str, int i, int sign)
{
	int	save;
	int	result;

	result = 0;
	save = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		save = result;
		result = result * 10 ;
		if (save != result / 10)
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		result = result +(str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (number_creator(str, i, sign));
}
