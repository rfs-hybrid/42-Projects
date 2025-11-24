/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 03:46:59 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 14:11:59 by maaugust         ###   ########.fr       */
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
	execve(cmd[0], cmd, envp);
	free_cmd_paths(cmd, NULL);
	if (errno == ENOENT)
		error_handler(data, NOT_FOUND, 127);
	error_handler(data, NOT_EXEC, 126);
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
		free(tmp);
		if (!full_path)
		{
			free_cmd_paths(cmd, paths);
			error_handler(data, CALLOC, 1);
		}
		if (!access(full_path, X_OK))
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

static void	run_cmd(t_data *data, char **cmd, char *cmd_path, char **envp)
{
	execve(cmd_path, cmd, envp);
	free_cmd_paths(cmd, NULL);
	free(cmd_path);
	if (errno == ENOENT)
		error_handler(data, NOT_FOUND, 127);
	error_handler(data, NOT_EXEC, 126);
}

void	execute(t_data *data, char *str, char **envp)
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	cmd = ft_parse_path(str, ' ');
	if (!cmd)
		error_handler(data, CALLOC, 1);
	if (ft_strchr(cmd[0], '/'))
		try_exec_absolute_relative(data, cmd, envp);
	paths = ft_get_path("PATH", envp);
	if (!paths)
	{
		free_cmd_paths(cmd, NULL);
		error_handler(data, NOT_FOUND, 127);
	}
	cmd_path = get_cmd_path(data, cmd, paths);
	free_cmd_paths(NULL, paths);
	if (!cmd_path)
	{
		free_cmd_paths(cmd, NULL);
		error_handler(data, NOT_FOUND, 127);
	}
	run_cmd(data, cmd, cmd_path, envp);
}
