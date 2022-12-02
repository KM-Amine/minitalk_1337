/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:05:21 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/02 11:24:47 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(1, "Error in signal handling", 25);
	exit(EXIT_FAILURE);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

void	handler_action(int sig, struct __siginfo *info, void *str)
{
	static unsigned char	c;
	static int				i;

	(void)str;
	if (sig == SIGUSR1)
		c |= (unsigned char)(1 << 7);
	else if (sig == SIGUSR2)
		c |= (unsigned char)0;
	if (i < 7)
		c >>= 1;
	if (i == 7)
	{
		write(1, &c, 1);
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
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
	new_handler.__sigaction_u.__sa_sigaction = handler_action;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	write(1, "- process id of the server : ", 29);
	ft_putnbr(getpid());
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
