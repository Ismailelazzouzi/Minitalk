/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:19:13 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/16 13:19:15 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
