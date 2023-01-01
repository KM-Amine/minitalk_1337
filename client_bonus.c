/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:51:21 by mkhellou          #+#    #+#             */
/*   Updated: 2023/01/01 11:12:09 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	ft_putstr_fd("Error in signal sending or process does not exist\n",2);
	exit(EXIT_FAILURE);
}

void	sleep_system(void)
{
	if (sleep(5) == 0)
	{
		ft_putstr_fd("server dead or busy with an other client\n",2);
		exit(EXIT_FAILURE);
	}
}

void	input(unsigned char *str, int pid)
{
	size_t	i;
	int		j;
	int		error;
	size_t	len;
	char	c;

	error = 0;
	j = 0;
	i = 0;
	len = ft_strlen((const char *)str);
	while (i <= len)
	{
		c = str[i];
		j = 0;
		while (j++ < 8)
		{
			if ((str[i] & 1) == 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error();
				sleep_system();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error();
				sleep_system();
			}
			str[i] = str[i] >> 1;
		}
		//ft_putstr_fd("byte recieved successfully \n",1);
		if (c == 0)
			ft_putstr_fd("----message recieved successfully-----\n",1);
		i++;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		usleep(100);
}

int	main(int argc, char	**argv)
{
	int		pid;
	size_t	j;

	j = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Error : incorrect number of arguments\n",2);
		exit(EXIT_FAILURE);
	}
	while (j < ft_strlen(argv[1]))
	{
		if (ft_isalpha(argv[1][j]))
		{
			ft_putstr_fd("Error : incorrect PID\n",2);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	pid = ft_atoi(argv[1]);
	input((unsigned char *)argv[2], pid);
	return (0);
}
