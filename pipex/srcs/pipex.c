/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:11:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 14:29:27 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "init.h"
#include "exec.h"
#include "utils.h"

static void	close_pipes(t_data *data)
{
	int	i;

	if (!data->p_fd)
		return ;
	i = -1;
	while (++i < data->n_pipes)
	{
		if (close(data->p_fd[i][0]) < 0)
			error_handler(data, CLOSE, 1);
		if (close(data->p_fd[i][1]) < 0)
			error_handler(data, CLOSE, 1);
	}
}

static void	child(t_data *data, int idx, char **argv, char **envp)
{
	if (idx == 0 && dup2(data->fd.in, STDIN_FILENO) < 0)
		error_handler(data, DUP2, 1);
	else if (idx > 0 && dup2(data->p_fd[idx - 1][0], STDIN_FILENO) < 0)
		error_handler(data, DUP2, 1);
	if (idx < data->n_cmds - 1 && dup2(data->p_fd[idx][1], STDOUT_FILENO) < 0)
		error_handler(data, DUP2, 1);
	else if (idx == data->n_cmds - 1 && dup2(data->fd.out, STDOUT_FILENO) < 0)
		error_handler(data, DUP2, 1);
	close_pipes(data);
	if (close(data->fd.in) < 0 || close(data->fd.out) < 0)
		error_handler(data, CLOSE, 1);
	execute(data, argv[idx], envp);
}

static void	pipex(t_data *data, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (++i < data->n_cmds)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			error_handler(data, FORK, 1);
		if (!data->pid[i])
			child(data, i, argv, envp);
	}
	close_pipes(data);
	if (close(data->fd.in) < 0 || close(data->fd.out) < 0)
		error_handler(data, CLOSE, 1);
	i = -1;
	while (++i < data->n_cmds)
		if (waitpid(data->pid[i], NULL, 0) < 0)
			error_handler(data, WAIT, 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
	{
		ft_printf("Wrong number of arguments!\n");
		ft_printf("Usage:\t./pipex file1 cmd1 cmd2 file2");
		return (EXIT_FAILURE);
	}
	init(&data, argc, argv);
	argv += 2;
	if (data.here_doc)
	{
		if (argc < 6)
		{
			ft_printf("Wrong number of arguments!\n");
			ft_printf("Usage:\t./pipex here_doc LIMITER cmd1 cmd2 ... file2");
			free_data(&data);
			return (EXIT_FAILURE);
		}
		here_doc(&data, *argv++);
	}
	pipex(&data, argv, envp);
	free_data(&data);
	return (EXIT_SUCCESS);
}
