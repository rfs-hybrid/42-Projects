/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 02:11:40 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/21 03:19:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "utils.h"

static void	pipex(t_fd fd, int argc, char **argv, char **envp)
{
	int	n_cmds;
	int	n_pipes;
	int	*p_fd[2];

	n_cmds = argc - 3;
	n_pipes = n_cmds - 1;
	
}

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	int		n_cmds;
	int		n_pipes;

	if (argc != 5)
	{
		ft_printf("Wrong number of arguments!\n");
		ft_printf("Usage:\t./pipex file1 cmd1 cmd2 file2");
		return (EXIT_FAILURE);
	}
	n_pipes = argc - 4;
	open_file(&fd, argv[1], READ);
	open_file(&fd, argv[argc - 1], WRITE);
	if (fd.in < 0 || fd.out < 0)
	{
		perror ("open");
		return (EXIT_FAILURE);
	}
	pipex(fd, argc, argv, envp);
	return (EXIT_SUCCESS);
}

