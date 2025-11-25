/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:10:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/25 03:09:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* --- External Libraries --- */
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* --- Error enum --- */
typedef enum e_error
{
	CALLOC,
	OPEN,
	CLOSE,
	PIPE,
	FORK,
	WAIT,
	DUP2,
	NOT_EXEC,
	NOT_FOUND
}	t_error;

/* --- File descriptors --- */
typedef struct s_fd
{
	int	in;
	int	out;
}	t_fd;

/* --- Main data structure --- */
typedef struct s_data
{
	pid_t	pid[2];
	t_fd	fd;
	int		p_fd[2];
}	t_data;

/* --- Utils --- */
int		safe_open(t_data *data, char *file, int flags, mode_t mode);
void	safe_close(t_data *data, int *fd);
void	free_data(t_data *data);

/* --- Init --- */
void	init(t_data *data, char **argv);

/* --- Parsing --- */
char	**ft_get_path(char *var, char **envp);

/* --- Execution --- */
void	execute(t_data *data, char *str, char **envp);

/* --- Error Handling --- */
void	error_handler(t_data *data, t_error error, unsigned char status_code);

#endif
