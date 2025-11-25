/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:46:10 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/25 03:17:32 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_handler(t_data *data, t_error error, unsigned char status_code)
{
	if (error == CALLOC)
		perror("calloc failed");
	else if (error == OPEN)
		perror("open failed");
	else if (error == CLOSE)
		perror("close failed");
	else if (error == WRITE)
		perror("write failed");
	else if (error == PIPE)
		perror("pipe failed");
	else if (error == FORK)
		perror("fork failed");
	else if (error == DUP2)
		perror("dup2 failed");
	else if (error == NOT_EXEC)
		perror("found but not executable");
	else if (error == NOT_FOUND)
		perror("command not found");
	if (data)
		free_data(data);
	exit(status_code);
}
