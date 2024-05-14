#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(const char *str)
{
	int neg;
	int i;
	int num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

void	send_signals(int pid, char c)
{
	int				i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[2][i])
			send_signals(ft_atoi(argv[1]), argv[2][i++]);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}