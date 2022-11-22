/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:43 by mkhellou          #+#    #+#             */
/*   Updated: 2022/11/22 15:52:03 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

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
	{
		c |= (unsigned char)(1 << 7);
		c >>= 1;
	}
	else if (sig == SIGUSR2)
	{
		c >>= 1;
	}
	i++;
	if (i == 7)
	{	
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	write(1, "- process id of the server : ", 29);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
