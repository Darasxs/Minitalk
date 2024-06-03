/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:01:29 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/05/14 14:47:50 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	send_signal(int pid, char *message, size_t len);
void	signal_handling(int signal);
void	ft_putnbr(int n);
void	ft_bzero(void *s, size_t n);

#endif