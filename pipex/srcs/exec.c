/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 03:46:59 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/25 03:34:27 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	errno = 0;
	execve(cmd[0], cmd, envp);
	free_cmd_paths(cmd, NULL);
	if (errno == ENOENT)
		error_handler(data, NOT_FOUND, 127);
	error_handler(data, NOT_EXEC, 126);
}

static char	*get_cmd_path(t_data *data, char **cmd, char **paths)
{
	char	*full_path;
	char	*partial_path;
	int		i;

	i = -1;
	while (paths[++i])
	{
		partial_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(partial_path, cmd[0]);
		free(partial_path);
		if (!full_path)
		{
			free_cmd_paths(cmd, paths);
			error_handler(data, CALLOC, 1);
		}
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
	}
	return (NULL);
}

static void	run_cmd(t_data *data, char **cmd, char *cmd_path, char **envp)
{
	if (!cmd_path)
	{
		free_cmd_paths(cmd, NULL);
		error_handler(data, NOT_FOUND, 127);
	}
	errno = 0;
	execve(cmd_path, cmd, envp);
	free_cmd_paths(cmd, NULL);
	free(cmd_path);
	cmd_path = NULL;
	if (errno == ENOENT)
		error_handler(data, NOT_FOUND, 127);
	error_handler(data, NOT_EXEC, 126);
}

void	execute(t_data *data, char *str, char **envp)
{
	char	**cmd;
	char	**paths;
	char	*cmd_path;

	cmd = ft_split(str, ' ');
	if (!cmd || !cmd[0] || !*cmd[0])
	{
		free_cmd_paths(cmd, NULL);
		error_handler(data, NOT_FOUND, 127);
	}
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
	run_cmd(data, cmd, cmd_path, envp);
}
