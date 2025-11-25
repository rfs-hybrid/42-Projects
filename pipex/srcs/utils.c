/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 22:50:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	safe_open(t_data *data, char *file, int flags, mode_t mode)
{
	int	fd;

	fd = open(file, flags, mode);
	if (fd < 0)
		error_handler(data, OPEN, 1);
	return (fd);
}

void	safe_close(t_data *data, int *fd)
{
	if (*fd >= 0)
	{
		if (close(*fd) < 0)
			error_handler(data, CLOSE, 1);
		*fd = -1;
	}
}

void	free_data(t_data *data)
{
	safe_close(data, &data->fd.in);
	safe_close(data, &data->fd.out);
	safe_close(data, &data->p_fd[0]);
	safe_close(data, &data->p_fd[1]);
}
