/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:37:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/22 18:34:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	init_pipes(t_data *data)
{
	int	i;

	data->p_fd = NULL;
	if (data->n_pipes > 0)
	{
		data->p_fd = ft_calloc(data->n_pipes, sizeof(int *));
		if (!data->p_fd)
			error_handler(data, CALLOC);
		i = -1;
		while (++i < data->n_pipes)
		{
			data->p_fd[i] = ft_calloc(2, sizeof(int));
			if (!data->p_fd[i])
				error_handler(data, CALLOC);
		}
		i = -1;
		while (++i < data->n_pipes)
			if (pipe(data->p_fd[i]) == -1)
				error_handler(data, PIPE);
	}
}

static void	init_fds(t_data *data, int argc, char **argv)
{
	data->n_cmds = argc - 3;
	if (data->here_doc)
	{
		data->fd.in = -1;
		data->fd.out = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
		data->n_cmds--;
		return ;
	}
	data->fd.in = open(argv[1], O_RDONLY, 0777);
	data->fd.out = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
}

void	init(t_data *data, int argc, char **argv)
{
	int	i;

	data->here_doc = !ft_strncmp(argv[1], "here_doc", 8)
		&& argv[1][ft_strlen("here_doc")] == '\0';
	init_fds(data, argc, argv);
	if ((!data->here_doc && data->fd.in < 0) || data->fd.out < 0)
		error_handler(NULL, OPEN);
	data->n_pipes = data->n_cmds - 1;
	data->pid = ft_calloc(data->n_cmds, sizeof(pid_t));
	if (!data->pid)
		error_handler(data, CALLOC);
	init_pipes(data);
}
