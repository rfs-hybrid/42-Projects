/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 01:24:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/10/23 19:21:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"
# include "printer.h"
# include <stdbool.h>
# include <stdint.h>

void	exit_error(t_print_code code, t_data *data, long count);
bool	destroy_mutexes(t_data *data, long count);
long	ft_atol(char *str);
int64_t	ft_gettimeofday_us(void);
int		ft_usleep(long usec);

#endif
