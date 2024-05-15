/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:54:10 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/15 12:54:13 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static int	pid;

	context = NULL;
	if (pid != info->si_pid)
	{
		c = 0;
		i = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		c += 1;
	i++;
	if (i != 8)
		c = c << 1;
	else
	{
		if (c == '\0')
			kill(pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc == 1 && argv)
	{
		print_pid(getpid());
		sa.sa_sigaction = handler;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		write(1, "\n", 1);
		while (1)
			pause();
	}
	return (0);
}
