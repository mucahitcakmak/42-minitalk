/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:44:42 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/14 16:22:14 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdarg.h>

// ft_printf.c
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);
void	arg_check(va_list lst, char c);
void	ft_printf(const char *str, ...);

// server.c
void	handler(int signal);

// client.c
int		ft_atoi(char *str);
void	send_bit(int pid, char c);

#endif