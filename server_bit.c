/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:45:55 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/04 10:28:14 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	g_c;

void	ft_error(void)
{
	write(1, "Error in signal handling", 25);
	exit(EXIT_FAILURE);
}

void	handler_action(int sig, struct __siginfo *info, void *str)
{
	static int				i;

	(void)str;
	if (sig == SIGUSR1)
	{
		g_c |= (unsigned char)(1 << 7);
		usleep(100);
		kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		g_c |= (unsigned char)0;
		usleep(100);
		kill(info->si_pid, SIGUSR2);
	}
	if (i < 7)
		g_c >>= 1;
	if (i == 7)
	{
		write(1, &g_c, 1);
		g_c = 0;
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
	new_handler.__sigaction_u.__sa_sigaction = handler_action;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	write(1, "- process id of the server : ", 29);
	ft_printf("%d", getpid());
	write (1, "\n", 1);
	while (1)
	{
		pause();
	}
	return (0);
}
