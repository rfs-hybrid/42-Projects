/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:28 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/02 22:11:46 by maaugust         ###   ########.fr       */
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

static void	handle_signal (int signal, siginfo_t *info, void *extra)
{
	static t_byte	c = 0;
	static size_t	i = 0;
	static int		cli_pid = 0;

	(void) extra;
	if (!cli_pid)
		cli_pid = info->si_pid;
	if (++i < 8)
	{
		c << 1;
		return ;
	}

}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	write(STDOUT_FILENO, "The process ID is: ", 19);
	putnbr(pid);
	write(STDOUT_FILENO, ".\n", 2);
	sa = { 0 };
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_handler = &handle_signal;
	if(sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(STDERR_FILENO, "sigaction failed to handle SIGUSR1!\n", 18);
		return (EXIT_FAILURE);
	}
	sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(STDERR_FILENO, "sigaction failed to handle SIGUSR1!\n", 18);
		return (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
