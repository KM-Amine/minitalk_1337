#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

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
		printf("%c",c);
		c = 0;
		i = 0;
		//printf("--%d-- \n",c);
	}
}

int input(char *s)
{
	int i;
	int j;
	unsigned char*str;

	str = (unsigned char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		j = 1;
		while (j<8)
		{
			if((str[i] & 1) == 1)
			{
				kill(getpid(),SIGUSR1);
				//usleep(100);
			}
			else
			{
				kill(getpid(),SIGUSR2);
				//usleep(100);
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
	//printf("%d",getpid());
	signal(SIGUSR1,handler);
	signal(SIGUSR2,handler);
	input(argv[1]);
	/*kill(getpid(),SIGUSR2);
	kill(getpid(),SIGUSR2);
	kill(getpid(),SIGUSR2);
	kill(getpid(),SIGUSR2);
	kill(getpid(),SIGUSR1);
	kill(getpid(),SIGUSR1);
	kill(getpid(),SIGUSR1);
	kill(getpid(),SIGUSR1);*/
}