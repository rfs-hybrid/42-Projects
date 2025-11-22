/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:11:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/22 17:53:01 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "init.h"
#include "utils.h"

static void	execute(t_data *data, char **argv, char **envp)
{
	return ;
}

static void	child(t_data *data, int idx, char **argv, char **envp)
{
	if (idx == 0 && dup2(data->fd.in, STDIN_FILENO) < 0)
		error_handler(data, DUP2);
	else if (idx > 0 && dup2(data->p_fd[idx - 1][0], STDIN_FILENO) < 0)
		error_handler(data, DUP2);
	if (idx < data->n_cmds - 1 && dup2(data->p_fd[idx][1], STDOUT_FILENO) < 0)
		error_handler(data, DUP2);
	else if (idx == data->n_cmds - 1 && dup2(data->fd.out, STDOUT_FILENO) < 0)
		error_handler(data, DUP2);
	close_pipes(data);
	if (close(data->fd.in) < 0 || close(data->fd.out) < 0)
		error_handler(data, CLOSE);
	execute(data, &argv[idx], envp);
	error_handler(data, EXECVE);
}

static void	here_doc(t_data *data, char *limiter)
{
	char	*line;
	int		hdoc_fd[2];
	size_t	limiter_len;

	if (pipe(hdoc_fd) == -1)
		error_handler(data, PIPE);
	limiter_len = ft_strlen(limiter);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, limiter, limiter_len)
			&& (line[limiter_len] == '\n' || line[limiter_len] == '\0'))
			break ;
		if (write(hdoc_fd[1], line, ft_strlen(line)) < 0)
			error_handler(data, WRITE);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(hdoc_fd[1]);
	data->fd.in = hdoc_fd[0];
}

static void	pipex(t_data *data, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (++i < data->n_cmds)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			error_handler(data, FORK);
		if (!data->pid[i])
			child(data, i, argv, envp);
	}
	close_pipes(data);
	if (close(data->fd.in) < 0 || close(data->fd.out) < 0)
		error_handler(data, CLOSE);
	i = -1;
	while (++i < data->n_cmds)
		if (waitpid(data->pid[i], NULL, 0) < 0)
			error_handler(data, WAIT);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		error_handler(NULL, ARGS);
	init(&data, argc, argv);
	argv += 2;
	if (data.here_doc)
		here_doc(&data, *argv++);
	pipex(&data, argv, envp);
	return (EXIT_SUCCESS);
}
