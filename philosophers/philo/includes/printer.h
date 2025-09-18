/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:04:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/17 23:48:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include "philo.h"
# include <stdlib.h>

# define RESET			"\033[0m"

// Styles
# define BOLD			"\033[1m"
# define ITALIC			"\033[3m"
# define UNDER			"\033[4m"
# define SLOW_BLINK		"\033[5m"
# define FAST_BLINK		"\033[6m"

# define BOLD_OFF		"\033[22m"
# define ITALIC_OFF		"\033[23m"
# define UNDER_OFF		"\033[24m"
# define SLOW_BLINK_OFF	"\033[25m"
# define FAST_BLINK_OFF	"\033[26m"

// Colors
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

typedef enum e_print_code
{
	NUM_ARGS,
	POS_ARGS,
	MALLOC,
	SLEEP,
	TH_CREATE,
	TH_JOIN,
	TH_DETACH,
	TH_INVALID,
	MTX_INIT,
	MTX_LOCK,
	MTX_UNLOCK,
	MTX_DESTROY,
	MTX_INVALID,
	PHILO_FORK,
	PHILO_EAT,
	PHILO_SLEEP,
	PHILO_THINK,
	PHILO_DEAD
}	t_print_code;

void	print_message(t_print_code code, t_philo *philo);

#endif
