/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 00:37:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/25 03:29:34 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_data *data, char **argv)
{
	data->fd.in = safe_open(data, argv[1], O_RDONLY, 0);
	data->fd.out = safe_open(data, argv[4],
			O_CREAT | O_RDWR | O_TRUNC, 0644);
	data->p_fd[0] = -1;
	data->p_fd[1] = -1;
	if (pipe(data->p_fd) < 0)
		error_handler(data, PIPE, 1);
}
