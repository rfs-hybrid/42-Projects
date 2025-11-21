/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:22 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/21 03:18:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	error_handler(t_error error)
{

}

void	open_file(t_fd *fd, char *filename, t_redir redir)
{
	if (redir == READ)
		fd->in = open(filename, O_RDONLY);
	else if (redir == WRITE)
		fd->out = open(filename, O_CREAT | O_RDWR | O_APPEND, 0777);
	else
	{
		ft_printf("Invalid file operation!\n");
		exit (EXIT_FAILURE);
	}
}
