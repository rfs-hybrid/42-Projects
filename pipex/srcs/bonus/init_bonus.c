/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:37:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 21:45:04 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_pipes(t_data *data, int n)
{
	int	i;

	if (!data->p_fd || n <= 0)
		return ;
	i = -1;
	while (++i < n)
	{
		if (data->p_fd[i])
		{
			if (data->p_fd[i][0] >= 0)
				close(data->p_fd[i][0]);
			if (data->p_fd[i][1] >= 0)
				close(data->p_fd[i][1]);
			free(data->p_fd[i]);
		}
	}
	free(data->p_fd);
	data->p_fd = NULL;
}

static void	init_pipes(t_data *data)
{
	int	i;

	if (data->n_pipes <= 0)
		return ;
	data->p_fd = ft_calloc(data->n_pipes, sizeof(int *));
	if (!data->p_fd)
		error_handler(data, CALLOC, 1);
	i = -1;
	while (++i < data->n_pipes)
	{
		data->p_fd[i] = ft_calloc(2, sizeof(int));
		if (!data->p_fd[i])
		{
			free_pipes(data, i);
			error_handler(data, CALLOC, 1);
		}
		data->p_fd[i][0] = -1;
		data->p_fd[i][1] = -1;
		if (pipe(data->p_fd[i]) < 0)
		{
			free_pipes(data, i + 1);
			error_handler(data, PIPE, 1);
		}
	}
}

static void	init_fds(t_data *data, int argc, char **argv)
{
	if (data->here_doc)
	{
		data->fd.in = -1;
		data->fd.out = safe_open(data, argv[argc - 1],
				O_CREAT | O_RDWR | O_APPEND, 0644);
		data->n_cmds = argc - 4;
		return ;
	}
	data->fd.in = safe_open(data, argv[1], O_RDONLY, 0);
	data->fd.out = safe_open(data, argv[argc - 1],
			O_CREAT | O_RDWR | O_TRUNC, 0644);
	data->n_cmds = argc - 3;
}

void	init(t_data *data, int argc, char **argv)
{
	data->fd.in = -1;
	data->fd.out = -1;
	data->p_fd = NULL;
	data->pid = NULL;
	data->n_cmds = 0;
	data->n_pipes = 0;
	data->here_doc = !ft_strcmp(argv[1], "here_doc");
	init_fds(data, argc, argv);
	data->n_pipes = data->n_cmds - 1;
	data->pid = ft_calloc(data->n_cmds, sizeof(pid_t));
	if (!data->pid)
		error_handler(data, CALLOC, 1);
	init_pipes(data);
}
