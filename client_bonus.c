/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:04:12 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/02 12:54:18 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(1, "Error in signal sending", 25);
	exit(EXIT_FAILURE);
}

void	input(unsigned char *str, int pid)
{
	size_t	i;
	int		j;
	int		error;
	size_t	len;

	error = 0;
	j = 0;
	i = 0;
	len = ft_strlen((const char *)str);
	while (i <= len)
	{
		j = 0;
		while (j++ < 8)
		{
			if ((str[i] & 1) == 1)
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			usleep(100);
			str[i] = str[i] >> 1;
			if (error == -1)
				ft_error();
		}
		i++;
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("message recieved successfully");
}

int	main(int argc, char	**argv)
{
	int	i;

	signal(SIGUSR1, handler);
	if (argc > 3)
		return (0);
	i = ft_atoi(argv[1]);
	input((unsigned char *)argv[2], i);
	return (0);
}
