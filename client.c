/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:56 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/27 11:59:24 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	ft_printf("Error in signal sending or process does not exist");
	exit(EXIT_FAILURE);
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
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
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
	size_t j;
	int error;
	j = 0;
	if (argc != 3 )
	{
		ft_printf("Error : incorrect number of arguments");
		return (0);
	}
	while (j < ft_strlen(argv[1]))
	{
		if (ft_isalpha(argv[1][j]))
		{
			ft_printf("Error : incorrect PID");
			return(0);
		}
		j++;
	}
	i = ft_atoi(argv[1]);
	error = kill(i,0);
	if (error == -1)
	{
		ft_printf("Error in signal sending or process does not exist");
		exit(EXIT_FAILURE);
	}
	input((unsigned char *)argv[2], i);
	return (0);
}
