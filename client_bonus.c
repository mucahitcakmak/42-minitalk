/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:44:49 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/17 23:52:11 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	reveice_send(int signal)
{
	static int	i = 0;

	if ((signal == SIGUSR2 || signal == SIGUSR1) && i++ == 0)
		ft_printf("Message Sent!\n");
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void	send_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		signal(SIGUSR1, reveice_send);
		signal(SIGUSR2, reveice_send);
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Incorrect argument!\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID!");
		return (1);
	}
	i = -1;
	while (argv[2][++i])
		send_bit(pid, argv[2][i]);
	send_bit(pid, '\n');
	return (0);
}
