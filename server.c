/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:27:44 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/10 19:20:19 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signal)
{
	static int i = 0;
	static char c = 0;

	if (signal == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int main(int argc, char *argv[])
{
	pid_t pid;
	struct sigaction sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Hatalı argüman!\n");
		return (1);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Sigaction Hatası!\n");

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		pause();
	}
}