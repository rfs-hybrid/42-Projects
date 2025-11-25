/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 21:46:51 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 21:47:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
