/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:49:44 by maaugust          #+#    #+#             */
/*   Updated: 2025/02/27 13:05:05 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_ptr);
}
