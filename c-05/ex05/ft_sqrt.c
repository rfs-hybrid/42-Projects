/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:24:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/05 18:06:37 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	root;

	if (nb < 0)
		return (0);
	root = 0;
	while (root * root <= nb && !(root * root < 0))
	{
		if (root * root == nb)
			return (root);
		root++;
	}
	return (0);
}
