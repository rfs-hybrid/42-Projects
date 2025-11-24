/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:24:17 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/24 18:46:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "pipex.h"
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_error
{
	CALLOC,
	OPEN,
	CLOSE,
	READ,
	WRITE,
	PIPE,
	FORK,
	WAIT,
	DUP2,
	NOT_EXEC,
	NOT_FOUND
}	t_error;

void	safe_close(t_data *data, int *fd);
char	**ft_get_path(char *var, char **envp);
void	here_doc(t_data *data, char *limiter);
void	error_handler(t_data *data, t_error error, unsigned char status_code);
void	free_data(t_data *data);

#endif
