/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:49:23 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/30 17:52:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scanf.h"

char	next_char(t_reader *r)
{
	char	c;

	if (r->has_peek)
	{
		r->has_peek = false;
		return (r->peek_char);
	}
	if (read(STDIN_FILENO, &c, 1) > 0)
		return (c);
	return ('\0');
}

void	unread_char(t_reader *r, char c)
{
	r->has_peek = true;
	r->peek_char = c;
}
