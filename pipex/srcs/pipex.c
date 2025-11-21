/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:11:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/21 21:12:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"

static void	pipex(t_data *data, int n_cmds, char **argv, char **envp)
{
	int	i;
	int j;

	i = -1;
	while (++i < data->n_cmds)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			error_handler(data, FORK);
		if (!data->pid[i])
		{
			if ((i == 0 && dup2(data->fd.in, STDIN_FILENO) < 0)
				|| (i < data->n_cmds - 1 && dup2(data->p_fd[i][1],
				STDOUT_FILENO) < 0) || (i > 0 && dup2(data->p_fd[i - 1][0],
				STDIN_FILENO) < 0) || (i == data->n_cmds - 1
				&& dup2(data->fd.out, STDOUT_FILENO) < 0))
				error_handler(data, DUP2);
		}
		close_pipes(data);
	}
}

static void	init(t_data *data, int argc, char **argv, char **envp)
{
	int	i;

	if (argc != 5)
		error_handler(NULL, ARGS);
	open_file(&data->fd, argv[1], READ);
	open_file(&data->fd, argv[argc - 1], WRITE);
	if (data->fd.in < 0 || data->fd.out < 0)
		error_handler(NULL, OPEN);
	data->n_cmds = argc - 3;
	data->n_pipes = data->n_cmds - 1;
	data->pid = ft_calloc(data->n_cmds, sizeof(pid_t));
	data->p_fd[0] = ft_calloc(data->n_pipes, sizeof(int));
	data->p_fd[1] = ft_calloc(data->n_pipes, sizeof(int));
	if (!data->pid || !data->p_fd[0] || !data->p_fd[1])
		error_handler(data, CALLOC);
	i = -1;
	while (++i < data->n_pipes)
		if (pipe(data->p_fd) == -1)
			error_handler(data, PIPE);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	init(&data, argc, argv, envp);
	pipex(&data, argc, argv, envp);
	return (EXIT_SUCCESS);
}

