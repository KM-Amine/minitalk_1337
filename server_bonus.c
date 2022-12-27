/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:45:55 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/27 17:54:57 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(1, "Error in signal handling", 25);
	exit(EXIT_FAILURE);
}

void	handler_action(int sig, siginfo_t *info, void *str)
{
	static int				i;
	static int				pid;
	static unsigned char	c;

	(void)str;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		c = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
	{
		c |= (unsigned char)(1 << 7);
		usleep(50);
		kill(pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		c |= (unsigned char)0;
		usleep(50);
		kill(pid, SIGUSR2);
	}
	if (i < 7)
		c >>= 1;
	if (i == 7)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
		return ;
	}
	i++;
}

int	main(void)
{
	struct sigaction	new_handler;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, 0);
	new_handler.sa_flags = SA_SIGINFO;
	new_handler.sa_mask = set;
	new_handler.sa_sigaction = handler_action;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	ft_printf("- process id of the server : %d\n",getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
