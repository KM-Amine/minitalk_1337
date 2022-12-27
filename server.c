/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:43 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/27 17:43:51 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	character_creator(int *sig, unsigned char *c, int *i)
{
	if (*sig == SIGUSR1)
	{
		*c |= (unsigned char)(1 << 7);
	}
	else if (*sig == SIGUSR2)
		*c |= (unsigned char)0;
	if (*i < 7)
		*c >>= 1;
}

void	handler_action(int sig, siginfo_t *info, void *str)
{
	static unsigned char	c;
	static int				i;
	static int				pid;

	(void)str;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		c = 0;
		i = 0;
	}
	character_creator(&sig, &c, &i);
	if (i == 7)
	{	
		ft_printf("%c", c);
		c = 0;
		i = 0;
		return ;
	}
	i++;
}

int	main(int argc, char	**argv)
{
	struct sigaction	new_handler;
	sigset_t			set;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error : too much arguments");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&set);
	new_handler.sa_flags = SA_SIGINFO;
	new_handler.sa_mask = set;
	new_handler.sa_sigaction = handler_action;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	ft_printf("- process id of the server : %d\n", getpid());
	while (1)
		pause();
	return (0);
}


