/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 21:21:38 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/04 14:47:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(int std, char c)
{
	write (std, &c, 1);
}

void	ft_putstr(int std, char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		ft_putchar(std, str[i++]);
}

int	ft_display_file(char *str)
{
	int		fd;
	int		not_eof;
	char	c;

	not_eof = 1;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (not_eof)
	{
		not_eof = read(fd, &c, 1);
		if (not_eof < 0)
			return (-1);
		if (not_eof > 0)
			ft_putchar(1, c);
	}
	if (close(fd) < 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr(2, "File name missing.\n");
	else if (argc > 2)
		ft_putstr(2, "Too many arguments.\n");
	else
	{
		if (ft_display_file(argv[1]) < 0)
			ft_putstr(2, "Cannot read file.\n");
	}
	return (0);
}
