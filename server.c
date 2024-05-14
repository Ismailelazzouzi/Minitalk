#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	handler(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c += 1;
	i++;
	if (i != 8)
		c = c << 1;
	else
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
