#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	send_signals(int pid, char c);
void	handler(int sig, siginfo_t *info, void *context);
void	ft_putchar(char c);
void	print_pid(unsigned int pid);
void	handler(int sig, siginfo_t *info, void *context);

#endif