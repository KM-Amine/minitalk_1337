#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

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

void handler(int sig)
{
	static unsigned char c;
	static int i;

	if (sig == SIGUSR1)
	{
		c |= (unsigned char)(1<<7);
		c >>=1;
		//printf("1");
	}
	else if (sig == SIGUSR2)
	{
		c >>=1;
		//printf("0");
	}
	i++;
	if (i == 7)
	{	
		write(1,&c,1);
		c = 0;
		i = 0;
		//printf("--%d-- \n",c);
	}
}

int main(int argc, char** argv)
{
	ft_putnbr_fd(getpid(),1);
	write (1,"\n",1);
	signal(SIGUSR1,handler);
	signal(SIGUSR2,handler);
	while (1)
		pause();
}