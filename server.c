/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:01:31 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/05/16 16:02:18 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	signal_handling(int signal)
{
	static int	c;
	static int	bit;

	if (signal == SIGUSR1)
	{
		c = c | (0 << bit);
		bit++;
	}
	else if (signal == SIGUSR2)
	{
		c = c | (1 << bit);
		bit++;
	}
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = &signal_handling;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "Error.\n", 7);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "Error.\n", 7);
	while (1)
		pause();
	return (0);
}
