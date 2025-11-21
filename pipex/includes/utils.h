/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/21 19:27:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "pipex.h"
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_error
{
	ARGS,
	CALLOC,
	OPEN,
	CLOSE,
	PIPE,
	FORK,
	DUP2,
	UNKNOWN
}	t_error;

typedef enum e_redir
{
	READ,
	WRITE,
	INVALID
}	t_redir;

void	error_handler(t_data *data, t_error error);
void	open_file(t_fd *fd, char *filename, t_redir redir);
void	free_data(t_data *data);

#endif
