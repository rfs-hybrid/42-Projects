/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 14:20:08 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_get_path(char *var, char **envp)
{
	char	*path;
	size_t	len;
	int		i;

	path = NULL;
	if (!envp)
		return (NULL);
	len = ft_strlen(var);
	i = -1;
	while (envp[++i])
	{
		path = ft_strchr(envp[i], '=');
		if (path && (path - envp[i] == len) && !ft_strncmp(envp[i], var, len))
			return (ft_split(path + 1, ':'));
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
			error_handler(data, WRITE, 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	if (close(hdoc_fd[1]) < 0)
		error_handler(data, CLOSE, 1);
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

	if (data->fd.in >= 0)
		close(data->fd.in);
	if (data->fd.out >= 0)
		close(data->fd.out);
	free(data->pid);
	i = -1;
	if (data->p_fd)
	{
		while (++i < data->n_pipes)
			free(data->p_fd[i]);
		free(data->p_fd);
	}
}
