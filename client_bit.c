/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:51:21 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/04 10:35:26 by mkhellou         ###   ########.fr       */
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
				usleep(100);
				error = kill(pid, SIGUSR1);
				pause();
			}
			else
			{
				usleep(100);
				error = kill(pid, SIGUSR2);
				pause();
			}
			str[i] = str[i] >> 1;
			if (error == -1)
				ft_error();
		}
		ft_printf("\n");
		ft_printf("byte recieved successfully\n");
		if (c == 0)
			ft_printf("message recieved successfully\n");
		i++;
	}
}

void	handler_action(int sig, struct __siginfo *info, void *str)
{
	static int				i;

	(void)str;
	(void)info;
	i = 0;
	if (sig == SIGUSR1)
		ft_printf("1");
	if (sig == SIGUSR2)
		ft_printf("0");
	i++;
}

int	main(int argc, char	**argv)
{
	int	i;
	struct sigaction	new_handler;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, 0);
	new_handler.sa_flags = SA_SIGINFO;
	new_handler.sa_mask = set;
	new_handler.__sigaction_u.__sa_sigaction = handler_action;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	if (argc > 3)
		return (0);
	i = ft_atoi(argv[1]);
	input((unsigned char *)argv[2], i);
	return (0);
}
