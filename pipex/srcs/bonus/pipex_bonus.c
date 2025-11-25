/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:11:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 22:09:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	close_pipes(t_data *data, int idx)
{
	int	i;

	if (!data->p_fd)
		return ;
	i = -1;
	while (++i < data->n_pipes)
	{
		if (i != idx - 1)
			safe_close(data, &data->p_fd[i][0]);
		if (i != idx)
			safe_close(data, &data->p_fd[i][1]);
	}
}

static void	child(t_data *data, int idx)
{
	if (idx == 0)
	{
		if (dup2(data->fd.in, STDIN_FILENO) < 0)
			error_handler(data, DUP2, 1);
		safe_close(data, &data->fd.in);
	}
	else
	{
		if (dup2(data->p_fd[idx - 1][0], STDIN_FILENO) < 0)
			error_handler(data, DUP2, 1);
		safe_close(data, &data->p_fd[idx - 1][0]);
	}
	if (idx < data->n_cmds - 1)
	{
		if (dup2(data->p_fd[idx][1], STDOUT_FILENO) < 0)
			error_handler(data, DUP2, 1);
		safe_close(data, &data->p_fd[idx][1]);
	}
	else
	{
		if (dup2(data->fd.out, STDOUT_FILENO) < 0)
			error_handler(data, DUP2, 1);
		safe_close(data, &data->fd.out);
	}
	close_pipes(data, idx);
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
		{
			child(data, i);
			execute(data, argv[i], envp);
		}
	}
	close_pipes(data, -1);
	safe_close(data, &data->fd.in);
	safe_close(data, &data->fd.out);
	i = -1;
	while (++i < data->n_cmds)
		if (waitpid(data->pid[i], NULL, 0) < 0)
			error_handler(data, WAIT, 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5 || (argc < 6 && argv[1] && !ft_strcmp(argv[1], "here_doc")))
	{
		ft_printf("Wrong number of arguments!\n");
		if (argc < 5)
			ft_printf("Usage:\t./pipex file1 cmd1 cmd2 file2\n");
		else
			ft_printf("Usage:\t./pipex here_doc LIMITER cmd1 cmd2 ... file2\n");
		return (EXIT_FAILURE);
	}
	init(&data, argc, argv);
	argv += 2;
	if (data.here_doc)
		here_doc(&data, *argv++);
	pipex(&data, argv, envp);
	free_data(&data);
	return (EXIT_SUCCESS);
}
