/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:44:39 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/17 23:48:37 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *cnt)
{
	static int	i = 0;
	static char	c = 0;

	(void)cnt;
	if (signal == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		kill(info->si_pid, SIGUSR1);
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = 0;
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Incorrect argument!\n");
		return (1);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1 
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Sigaction error!\n");
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		pause();
	}
}
