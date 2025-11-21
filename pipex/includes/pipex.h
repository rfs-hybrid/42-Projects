/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:10:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/21 17:50:27 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct s_fd
{
	int	in;
	int	out;
}	t_fd;

typedef struct s_data
{
	pid_t	*pid;
	t_fd	fd;
	int		*p_fd[2];
	int		n_cmds;
	int		n_pipes;
}	t_data;

#endif
