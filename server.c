/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:43 by mkhellou          #+#    #+#             */
/*   Updated: 2022/11/23 09:51:08 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	handler(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR1)
		c |= (unsigned char)(1 << 7);
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
	write(1, "- process id of the server : ", 29);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	if (signal(SIGUSR1, handler) == SIG_ERR)
		ft_error();
	if (signal(SIGUSR2, handler) == SIG_ERR)
		ft_error();
	while (1)
		pause();
	return (0);
}
