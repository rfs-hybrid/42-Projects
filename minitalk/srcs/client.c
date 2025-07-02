/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:19:21 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/02 22:08:21 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Invalid input parameters!\n", 26);
		write(STDERR_FILENO, "Usage: ./client <server_pid> <message>\n", 39);
		return (EXIT_FAILURE);
	}
	return (0);
}