/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/21 21:11:01 by maaugust         ###   ########.fr       */
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

void	open_file(t_fd *fd, char *filename, t_redir redir)
{
	if (redir == READ)
		fd->in = open(filename, O_RDONLY);
	else if (redir == WRITE)
		fd->out = open(filename, O_CREAT | O_RDWR | O_APPEND, 0777);
	else
	{
		ft_printf("Invalid file open operation!\n");
		exit (EXIT_FAILURE);
	}
}

void	close_pipes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_pipes)
	{
		close(data->p_fd[0]);
		close(data->p_fd[1]);
	}	
}

void	free_data(t_data *data)
{
	free(data->pid);
	free(data->p_fd[0]);
	free(data->p_fd[1]);
}
