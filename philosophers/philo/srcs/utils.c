/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:13:07 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/17 18:27:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "printer.h"

size_t	ft_atoul(char *str)
{
	size_t	res;

	res = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		print_message(POS_ARGS, NULL);
		return (res);
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (res == 0)
		print_message(POS_ARGS, NULL);
	return (res);
}

size_t	ft_gettimeofday_us(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return ((size_t)(-1));
	return ((size_t)(tv.tv_sec * 1e6 + tv.tv_usec));
}

int	ft_usleep(size_t usec)
{
	size_t	start;
	size_t	now;

	start = ft_gettimeofday_us();
	if (start == (size_t)(-1))
		return (usleep(usec));
	while (true)
	{
		now = ft_gettimeofday_us();
		if (now == (size_t)(-1))
			return (usleep(usec));
		if (now - start >= usec)
			break ;
		if (usec - (now - start) > 1e3)
			usleep((usec - (now - start)) / 2);
		else
		{
			now = ft_gettimeofday_us();
			while (now != (size_t)(-1) && now - start < usec)
				now = ft_gettimeofday_us();
			break ;
		}
	}
	return (0);
}

// void	ft_usleep(size_t usec)
// {
// 	size_t	start;
// 	size_t	elapsed;

// 	start = ft_gettimeofday_us();
// 	while (ft_gettimeofday_us() - start < usec)
// 	{
// 		elapsed = ft_gettimeofday_us() - start;
// 		if (usec - elapsed > 1e3)
// 			usleep((usec - elapsed) / 2);
// 		else
// 			while (ft_gettimeofday_us() - start < usec)
// 				;
// 	}
// }
