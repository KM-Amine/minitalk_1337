#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	number_creator(const char *str, int i, int sign)
{
	int	save;
	int	result;

	result = 0;
	save = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		save = result;
		result = result * 10 ;
		if (save != result / 10)
		{
			if (sign > 0)
				return (-1);
			else
				return (0);
		}
		result = result +(str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (number_creator(str, i, sign));
}

int input(char *s ,int pid)
{
	int i;
	int j;
	unsigned char*str;

	str = (unsigned char *)s;
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j<=6)
		{
			if((str[i] & 1) == 1)
			{
				kill(pid,SIGUSR1);
				usleep(50);
			}
			else
			{
				kill(pid,SIGUSR2);
				usleep(50);
			}
			str[i] = str[i] >> 1;
			j++;
 		}
		i++;
	}
	return (0);
}

int main(int argc, char** argv)
{
	int i = ft_atoi(argv[1]);
	input(argv[2],i);
}