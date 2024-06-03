/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:40:47 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/05/14 14:47:54 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	signal_handler(int signal, siginfo_t *info, void *context);
void	send_signal(int pid, char *message, size_t len);
void	ft_putnbr(int n);
void	ft_bzero(void *s, size_t n);

#endif