/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:04:12 by mkhellou          #+#    #+#             */
/*   Updated: 2022/11/30 17:43:52 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(unsigned char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', 1);
		i = i * -1;
	}
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar_fd(i % 10 + '0', 1);
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen((unsigned char*)s));
}

void	ft_error(void)
{
	write(1, "Error in signal sending", 25);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	long long		i;
	int				sign;
	long long		result;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = result * sign;
	return (result);
}

void	input(unsigned char *str, int pid)
{
	size_t	i;
	int	j;
	int	error;

	error = 0;
	j = 0;
	i = ft_strlen(str) + 1;
	while (i)
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] & 1) == 1)
				{
				error = kill(pid, SIGUSR1);
				}
			else
				{
				error = kill(pid, SIGUSR2);
				}
			error = usleep(100);
			str[i] = str[i] >> 1;
			j++;
			if (error == -1)
				ft_error();
		}
		i--;
	}
}
void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("message recieved");
}
int	main(int argc, char	**argv)
{
	int	i;

	signal(SIGUSR1,handler);
	if (argc > 3)
		return (0);
	i = ft_atoi(argv[1]);
	input((unsigned char *)argv[2], i);
	while (1)
		pause();
	return (0);
}
