/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/22 17:57:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_handler(t_data *data, t_error error)
{
	if (error == ARGS)
	{
		ft_printf("Wrong number of arguments!\n");
		ft_printf("Usage:\t./pipex file1 cmd1 cmd2 file2");
	}
	else if (error == CALLOC)
		perror("calloc");
	else if (error == OPEN)
		perror("open");
	else if (error == CLOSE)
		perror("close");
	else if (error == READ)
		perror("read");
	else if (error == WRITE)
		perror("write");
	else if (error == PIPE)
		perror("pipe");
	else if (error == FORK)
		perror("fork");
	else if (error == DUP2)
		perror("dup2");
	if (data)
		free_data(data);
	exit(EXIT_FAILURE);
}

void	close_pipes(t_data *data)
{
	int	i;

	if (!data->p_fd)
		return ;
	i = -1;
	while (++i < data->n_pipes)
	{
		if (close(data->p_fd[i][0]) < 0)
			error_handler(data, CLOSE);
		if (close(data->p_fd[i][1]) < 0)
			error_handler(data, CLOSE);
	}
}

void	free_data(t_data *data)
{
	int	i;

	free(data->pid);
	i = -1;
	if (data->p_fd)
	{
		while (++i < data->n_pipes)
			free(data->p_fd[i]);
		free(data->p_fd);
	}
}
