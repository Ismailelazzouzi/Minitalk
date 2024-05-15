/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:21 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/15 15:21:35 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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
