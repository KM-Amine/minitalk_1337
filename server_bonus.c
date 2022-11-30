#include <stdio.h>
#include "minitalk.h"

int i;

void	ft_error(void)
{
	write(1, "Error in signal handling", 25);
	exit(EXIT_FAILURE);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = i * -1;
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + '0', fd);
}

void handler_action(int sig, struct __siginfo *info,void *str)
{
	static unsigned char	c;
	static int				i;
	pid_t id;

	(void)str;
	id = info->si_pid;
	if (sig == SIGUSR1)
	{
		c |= (unsigned char)(1 << 7);
		kill(i,SIGUSR1);
	}
	else
		kill(i,SIGUSR2);
	if (i < 7)
		c >>= 1;
	if (i == 7)
	{	
		write(1, &c, 1);
		if (c == 0)
			kill(id,SIGUSR1);
		c = 0;
		i = 0;
		return ;
	}
	i++;
}

int	main(void)
{
	struct sigaction new_handler;
	sigset_t set;
	
	sigemptyset(&set);
	sigaddset(&set,0);
	new_handler.sa_flags = SA_SIGINFO;
	new_handler.sa_mask = set;
	new_handler.__sigaction_u.__sa_sigaction = handler_action;
	sigaction(SIGUSR1,&new_handler,NULL);
	sigaction(SIGUSR2,&new_handler,NULL);
	write(1, "- process id of the server : ", 29);
	ft_putnbr_fd(getpid(), 1);
	while (1)
		pause();
	return (0);
}
