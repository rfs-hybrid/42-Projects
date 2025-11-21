/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/21 03:17:35 by maaugust         ###   ########.fr       */
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
	MALLOC,
	OPEN,
	PIPE,
	FORK,
	DUP,
	UNKNOWN
}	t_error;

typedef enum e_redir
{
	READ,
	WRITE,
	INVALID
}	t_redir;

#endif
