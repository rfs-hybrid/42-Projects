/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:21 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/05 15:47:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

static void	validate_inputs(pid_t *pid, char **argv)
{
	int		sign;

	*pid = 0;
	sign = 1;
	while (*argv[1] == ' ' || (*argv[1] >= '\t' && *argv[1] <= '\r'))
		argv[1]++;
	if (*argv[1] == '+' || *argv[1] == '-')
		if (*argv[1]++ == '-')
			sign *= -1;
	while (*argv[1] >= '0' && *argv[1] <= '9')
		*pid = *pid * 10 + (*argv[1]++ - '0');
	*pid *= sign;
	while (*argv[1] == ' ' || (*argv[1] >= '\t' && *argv[1] <= '\r'))
		argv[1]++;
	if (!(*argv[1] || kill(*pid, 0) || !*argv[2]))
		return ;
	if (*argv[1])
		write(STDERR_FILENO, "Server PID must be one integer value!\n", 38);
	else if (kill(*pid, 0))
		write(STDERR_FILENO, "Server PID does not exist!\n", 27);
	if (!*argv[2])
		write(STDERR_FILENO, "The message to send is empty!\n", 30);
	exit (EXIT_FAILURE);
}

static void	handle_signal (int sig)
{
	(void) sig;
	g_ack = 1;
}

static void	send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		write (STDERR_FILENO, "Failed to send signal!\n", 23);
		exit (EXIT_FAILURE);
	}
}

static void	send_message(int pid, char *str)
{
	size_t	i;

	while (*str)
	{
		i = CHAR_BYTE;
		while (i-- > 0)
		{
			g_ack = 0;
			if (*str & (1 << i))
				send_signal(pid, SIGUSR1);
			else
				send_signal(pid, SIGUSR2);
			while (!g_ack)
				pause();
		}
		str++;
	}
	i = CHAR_BYTE;
	while (i-- > 0)
	{
		g_ack = 0;
		kill(pid, SIGUSR2);
		while (!g_ack)
			pause();
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				srv_pid;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Invalid input parameters!\n", 26);
		write(STDERR_FILENO, "Usage: ./client <server_pid> <message>\n", 39);
		return (EXIT_FAILURE);
	}
	validate_inputs(&srv_pid, argv);
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &handle_signal;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(STDERR_FILENO, "sigaction failed to handle SIGUSR1!\n", 37);
		return (EXIT_FAILURE);
	}
	send_message(srv_pid, argv[2]);
	write(STDOUT_FILENO, "Message sent successfully!\n", 27);
	return (EXIT_SUCCESS);
}
