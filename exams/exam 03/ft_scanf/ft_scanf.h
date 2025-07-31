/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:39:45 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/30 18:15:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCANF_H
# define FT_SCANF_H

# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_reader
{
	bool	has_peek;
	char	peek_char;
}	t_reader;

int		ft_scanf(const char *format, ...);
char	next_char(t_reader *r);
void	unread_char(t_reader *r, char c);

#endif