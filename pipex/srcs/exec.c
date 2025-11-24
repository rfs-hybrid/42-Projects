/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 03:46:59 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 05:15:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	free_cmd_paths(char **cmd, char **paths)
{
	int	i;

	if (cmd)
	{
		i = -1;
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
	}
	if (paths)
	{
		i = -1;
		while (paths[++i])
			free(paths[i]);
		free(paths);
	}
}

static void	try_exec_absolute_relative(t_data *data, char **cmd, char **envp)
{
	if (access(cmd[0], X_OK) < 0)
	{
		free_cmd_paths(cmd, NULL);
		error_handler(data, NOT_FOUND);
	}
	if (execve(cmd[0], cmd, envp) < 0)
	{
		free_cmd_paths(cmd, NULL);
		error_handler(data, EXECVE);
	}
}

static char	*get_cmd_path(t_data *data, char **cmd, char **paths)
{
	char	*full_path;
	char	*tmp;
	int		i;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], '/');
		full_path = ft_strjoin(tmp, cmd[0]);
		if (!tmp || !full_path)
		{
			free(tmp);
			free_cmd_paths(cmd, paths);
			error_handler(data, CALLOC);
		}
		if (!access(full_path, X_OK))
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

void	execute(t_data *data, char *str, char **envp)
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	cmd = ft_parse_path(str, ' ');
	if (!cmd)
		error_handler(data, CALLOC);
	if (ft_strchr(cmd[0], '/'))
		try_exec_absolute_relative(data, cmd, envp);
	paths = ft_get_path("PATH", envp);
	if (!paths)
	{
		free_cmd_paths(cmd, NULL);
		error_handler(data, NOT_FOUND);
	}
	cmd_path = get_cmd_path(data, cmd, paths);
	if (!cmd_path)
	{
		free_cmd_paths(cmd, paths);
		error_handler(data, NOT_FOUND);
	}
	free_cmd_paths(NULL, paths);
	execve(cmd_path, cmd, envp);
	free_cmd_paths(cmd, NULL);
	free(cmd_path);
}
