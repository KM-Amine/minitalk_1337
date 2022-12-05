/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:39:43 by mkhellou          #+#    #+#             */
/*   Updated: 2022/12/05 12:01:20 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(1, "Error in signal handling", 25);
	exit(EXIT_FAILURE);
}

void	handler(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR1)
		c |= (unsigned char)(1 << 7);
	else if (sig == SIGUSR2)
		c |= (unsigned char)0;
	if (i < 7)
		c >>= 1;
	if (i == 7)
	{	
		write(1, &c, 1);
		c = 0;
		i = 0;
		return ;
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
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
