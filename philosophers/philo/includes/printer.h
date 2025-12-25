/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:04:43 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 16:17:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include "philo.h"
# include <stdlib.h>

/*
────────────────────────────────────────────────────────────────────────────────
 ANSI COLOR CODES
────────────────────────────────────────────────────────────────────────────────
*/

// === RESET ===
# define RESET				"\x1b[0m"

// === STYLE ON ===
# define BOLD_ON			"\x1b[1m"
# define DIM_ON				"\x1b[2m"
# define ITALIC_ON			"\x1b[3m"
# define UNDERLINE_ON		"\x1b[4m"
# define BLINK_ON			"\x1b[5m"
# define REVERSE_ON			"\x1b[7m"
# define HIDDEN_ON			"\x1b[8m"
# define STRIKETHROUGH_ON	"\x1b[9m"

// === STYLE OFF ===
# define BOLD_OFF			"\x1b[22m"
# define DIM_OFF			"\x1b[22m"
# define ITALIC_OFF			"\x1b[23m"
# define UNDERLINE_OFF		"\x1b[24m"
# define BLINK_OFF			"\x1b[25m"
# define REVERSE_OFF		"\x1b[27m"
# define HIDDEN_OFF			"\x1b[28m"
# define STRIKETHROUGH_OFF	"\x1b[29m"

// === FOREGROUND COLORS ===
# define FG_BLACK			"\x1b[30m"
# define FG_RED				"\x1b[31m"
# define FG_GREEN			"\x1b[32m"
# define FG_YELLOW			"\x1b[33m"
# define FG_BLUE			"\x1b[34m"
# define FG_MAGENTA			"\x1b[35m"
# define FG_CYAN			"\x1b[36m"
# define FG_WHITE			"\x1b[37m"
# define FG_DEFAULT			"\x1b[39m"

// === BRIGHT FOREGROUND COLORS ===
# define BFG_BLACK			"\x1b[90m"
# define BFG_RED			"\x1b[91m"
# define BFG_GREEN			"\x1b[92m"
# define BFG_YELLOW			"\x1b[93m"
# define BFG_BLUE			"\x1b[94m"
# define BFG_MAGENTA		"\x1b[95m"
# define BFG_CYAN			"\x1b[96m"
# define BFG_WHITE			"\x1b[97m"

// === BACKGROUND COLORS ===
# define BG_BLACK			"\x1b[40m"
# define BG_RED				"\x1b[41m"
# define BG_GREEN			"\x1b[42m"
# define BG_YELLOW			"\x1b[43m"
# define BG_BLUE			"\x1b[44m"
# define BG_MAGENTA			"\x1b[45m"
# define BG_CYAN			"\x1b[46m"
# define BG_WHITE			"\x1b[47m"
# define BG_DEFAULT			"\x1b[49m"

// === BRIGHT BACKGROUND COLORS ===
# define BBG_BLACK			"\x1b[100m"
# define BBG_RED			"\x1b[101m"
# define BBG_GREEN			"\x1b[102m"
# define BBG_YELLOW			"\x1b[103m"
# define BBG_BLUE			"\x1b[104m"
# define BBG_MAGENTA		"\x1b[105m"
# define BBG_CYAN			"\x1b[106m"
# define BBG_WHITE			"\x1b[107m"

/**
 * @brief Enumeration for all print messages.
 * Includes errors (0-12) and Simulation status (13-17).
 */
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

/**
 * @fn void print_message(t_print_code code, t_philo *philo)
 * @brief Formats and prints a message to standard output.
 * @param code  The code corresponding to the event or error.
 * @param philo Pointer to the philosopher (NULL for error messages).
 */
void	print_message(t_print_code code, t_philo *philo);

#endif
