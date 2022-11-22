/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:38 by mkhellou          #+#    #+#             */
/*   Updated: 2022/11/22 14:50:43 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

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

int	input(unsigned char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 1;
		while (j < 8)
		{
			if ((str[i] & 1) == 1)
			{
				kill(getpid(), SIGUSR1);
				usleep(100);
			}
			else
			{
				kill(getpid(), SIGUSR2);
				usleep(100);
			}
			str[i] = str[i] >> 1;
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	(void)argc;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	input((unsigned char *)argv[1]);
}
