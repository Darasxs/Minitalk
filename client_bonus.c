/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaluszk <dpaluszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:13:12 by dpaluszk          #+#    #+#             */
/*   Updated: 2024/05/14 15:09:23 by dpaluszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(char *str)
{
	size_t	counter;
	int		result;
	int		sign;

	counter = 0;
	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		counter++;
		if (counter > 1)
			return (0);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	signal_handling(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Signal received.\n", 18);
}

void	send_signal(int pid, char *message, size_t len)
{
	size_t	i;
	ssize_t	j;
	int		result;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 8)
		{
			result = (message[i] & (1 << j));
			if (result == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(42);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	size_t				len;
	char				*message;
	struct sigaction	sa;

	sa.sa_handler = &signal_handling;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "Error.", 7);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		len = ft_strlen(message) + 1;
		send_signal(pid, message, len);
	}
	else
		write(1, "Wrong number of arguments.\n", 27);
	return (0);
}
