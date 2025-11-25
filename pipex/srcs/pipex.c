/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:11:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/25 03:30:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_data *data, int idx)
{
	if (idx == 0)
	{
		safe_close(data, &data->p_fd[0]);
		if (dup2(data->fd.in, STDIN_FILENO) < 0)
			error_handler(data, DUP2, 1);
		safe_close(data, &data->fd.in);
		if (dup2(data->p_fd[1], STDOUT_FILENO) < 0)
			error_handler(data, DUP2, 1);
		safe_close(data, &data->p_fd[1]);
		return ;
	}
	safe_close(data, &data->p_fd[1]);
	if (dup2(data->p_fd[0], STDIN_FILENO) < 0)
		error_handler(data, DUP2, 1);
	safe_close(data, &data->p_fd[0]);
	if (dup2(data->fd.out, STDOUT_FILENO) < 0)
		error_handler(data, DUP2, 1);
	safe_close(data, &data->fd.out);
}

static void	pipex(t_data *data, char **argv, char **envp)
{
	int	i;

	i = -1;
	while (++i < 2)
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
	safe_close(data, &data->p_fd[0]);
	safe_close(data, &data->p_fd[1]);
	safe_close(data, &data->fd.in);
	safe_close(data, &data->fd.out);
	i = -1;
	while (++i < 2)
		if (waitpid(data->pid[i], NULL, 0) < 0)
			error_handler(data, WAIT, 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
	{
		ft_printf("Wrong number of arguments!\n");
		ft_printf("Usage:\t./pipex file1 cmd1 cmd2 file2\n");
		return (EXIT_FAILURE);
	}
	init(&data, argv);
	argv += 2;
	pipex(&data, argv, envp);
	free_data(&data);
	return (EXIT_SUCCESS);
}
