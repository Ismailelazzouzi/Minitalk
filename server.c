#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_pid(unsigned int pid)
{
	if (pid >= 10)
	{
		print_pid(pid / 10);
		pid = pid % 10;
	}
	if (pid < 10)
		ft_putchar(pid + 48);
}

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
	print_pid(getpid());
	write(1, "\n", 1);
	while (1)
	{
	}
	return (0);
}
