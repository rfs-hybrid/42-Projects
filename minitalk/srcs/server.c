/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:28 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/08 02:36:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	putnbr(long nbr)
{
	char	c;

	if (nbr < 0)
	{
		nbr *= -1;
		write(STDOUT_FILENO, "-", 1);
	}
	if (nbr >= 10)
		putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(STDOUT_FILENO, &c, sizeof(char));
}

static void	print_error(void)
{
	write(STDERR_FILENO, "Failed to send signal!\n", 23);
	exit(EXIT_FAILURE);
}

static void	handle_char(t_byte *c, size_t *n_bits, pid_t *pid)
{
	pid_t	tmp;

	tmp = *pid;
	if (!*c)
	{
		write(STDOUT_FILENO, "\n", 1);
		if (kill(*pid, SIGUSR2) == -1)
			print_error();
		*pid = 0;
	}
	else
		write(STDOUT_FILENO, c, sizeof(t_byte));
	*c = 0;
	*n_bits = CHAR_BITS;
	if (tmp && kill(tmp, SIGUSR1) == -1)
		print_error();
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static t_byte	c = 0;
	static size_t	n_bits = CHAR_BITS;
	static pid_t	cli_pid = 0;

	(void) context;
	if (!cli_pid)
	{
		cli_pid = info->si_pid;
		c = 0;
		n_bits = CHAR_BITS;
	}
	else if (info->si_pid != cli_pid)
		return ;
	c |= (sig == SIGUSR1) << --n_bits;
	if (n_bits == 0)
	{
		handle_char(&c, &n_bits, &cli_pid);
		return ;
	}
	if (kill(cli_pid, SIGUSR1) == -1)
		print_error();
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write(STDOUT_FILENO, "The process ID is: ", 19);
	putnbr(pid);
	write(STDOUT_FILENO, ".\n", 2);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = &handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(STDERR_FILENO, "sigaction failed to setup handlers!\n", 36);
		return (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
