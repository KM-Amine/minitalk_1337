/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:56 by mkhellou          #+#    #+#             */
/*   Updated: 2022/11/23 09:56:02 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(1, "Error in signal sending", 25);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	long long		i;
	int				sign;
	long long		result;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0' );
		i++;
	}
	result = result * sign;
	return (result);
}

void	input(unsigned char *str, int pid)
{
	int	i;
	int	j;
	int	error;

	error = 0;
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] & 1) == 1)
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			error = usleep(100);
			str[i] = str[i] >> 1;
			j++;
			if (error == -1)
				ft_error();
		}
		i++;
	}
}

int	main(int argc, char	**argv)
{
	int	i;

	if (argc > 3)
		return (0);
	i = ft_atoi(argv[1]);
	input((unsigned char *)argv[2], i);
	return (0);
}
