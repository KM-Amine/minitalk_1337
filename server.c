/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:43 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/27 11:48:25 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(1, "Error in signal handling", 25);
	exit(EXIT_FAILURE);
}

void	handler_action(int sig, struct __siginfo *info, void *str)
{
	static unsigned char	c;
	static int				i;
	static int pid;

	(void)str;
	(void)info;
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
	}
	else if (sig == SIGUSR2)
		c |= (unsigned char)0;
	if (i < 7)
		c >>= 1;
	if (i == 7)
	{	
		ft_printf("%c",c);
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
	sigaddset(&set, 0);
	new_handler.sa_flags = SA_SIGINFO;
	new_handler.sa_mask = set;
	new_handler.sa_sigaction = handler_action;
	sigaction(SIGUSR1, &new_handler, NULL);
	sigaction(SIGUSR2, &new_handler, NULL);
	ft_printf("- process id of the server : %d\n",getpid());

	// if (signal(SIGUSR1, handler) == SIG_ERR)
	// 	ft_error();
	// if (signal(SIGUSR2, handler) == SIG_ERR)
	// 	ft_error();
	while (1)
		pause();
	//regler le decalage de bit en mettant c to 0 
	return (0);
}
