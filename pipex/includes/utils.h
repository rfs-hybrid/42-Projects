/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/22 17:51:16 by maaugust         ###   ########.fr       */
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
	READ,
	WRITE,
	PIPE,
	FORK,
	WAIT,
	DUP2,
	EXECVE
}	t_error;

void	error_handler(t_data *data, t_error error);
void	close_pipes(t_data *data);
void	free_data(t_data *data);

#endif
