/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 19:08:30 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	safe_close(t_data *data, int *fd)
{
	if (*fd >= 0)
	{
		if (close(*fd) < 0)
			error_handler(data, CLOSE, 1);
		*fd = -1;
	}
}

char	**ft_get_path(char *var, char **envp)
{
	size_t	len;
	int		i;

	if (!envp)
		return (NULL);
	len = ft_strlen(var);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], var, len) && envp[i][len] == '=')
			return (ft_split(envp[i] + len + 1, ':'));
	}
	return (NULL);
}

void	here_doc(t_data *data, char *limiter)
{
	char	*line;
	int		hdoc_fd[2];
	size_t	limiter_len;

	if (pipe(hdoc_fd) == -1)
		error_handler(data, PIPE, 1);
	limiter_len = ft_strlen(limiter);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!ft_strncmp(line, limiter, limiter_len)
			&& (line[limiter_len] == '\n' || line[limiter_len] == '\0'))
			break ;
		if (write(hdoc_fd[1], line, ft_strlen(line)) < 0)
		{
			free(line);
			safe_close(data, &hdoc_fd[1]);
			error_handler(data, WRITE, 1);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	safe_close(data, &hdoc_fd[1]);
	data->fd.in = hdoc_fd[0];
}

void	error_handler(t_data *data, t_error error, unsigned char status_code)
{
	if (error == CALLOC)
		perror("calloc failed");
	else if (error == OPEN)
		perror("open failed");
	else if (error == CLOSE)
		perror("close failed");
	else if (error == READ)
		perror("read failed");
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

void	free_data(t_data *data)
{
	int	i;

	safe_close(data, &data->fd.in);
	safe_close(data, &data->fd.out);
	free(data->pid);
	data->pid = NULL;
	i = -1;
	if (data->p_fd)
	{
		while (++i < data->n_pipes)
		{
			if (data->p_fd[i])
			{
				safe_close(data, &data->p_fd[i][0]);
				safe_close(data, &data->p_fd[i][1]);
				free(data->p_fd[i]);
			}
		}
		free(data->p_fd);
		data->p_fd = NULL;
	}
	data->n_cmds = 0;
	data->n_pipes = 0;
}
