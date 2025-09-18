/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:04:47 by maaugust          #+#    #+#             */
/*   Updated: 2025/09/18 00:20:02 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"

static void	thread_message(t_print_code code)
{
	if (code == TH_CREATE)
		printf("║                 FAILED TO CREATE THREAD                 ║\n");
	else if (code == TH_JOIN)
		printf("║                  FAILED TO JOIN THREAD                  ║\n");
	else if (code == TH_DETACH)
		printf("║                 FAILED TO DETACH THREAD                 ║\n");
	else
		printf("║                 INVALID THREAD OPERATION                ║\n");
}

static void	mutex_message(t_print_code code)
{
	if (code == MTX_INIT)
		printf("║                FAILED TO INITIALIZE MUTEX               ║\n");
	else if (code == MTX_LOCK)
		printf("║                   FAILED TO LOCK MUTEX                  ║\n");
	else if (code == MTX_UNLOCK)
		printf("║                  FAILED TO UNLOCK MUTEX                 ║\n");
	else if (code == MTX_DESTROY)
		printf("║                 FAILED TO DESTROY MUTEX                 ║\n");
	else
		printf("║                 INVALID MUTEX OPERATION                 ║\n");
}

static void	error_message(t_print_code code)
{
	printf(BOLD RED SLOW_BLINK);
	printf("\n╔═════════════════════════════════════════════════════════╗\n");
	if (code == NUM_ARGS)
		printf("║                WRONG NUMBER OF ARGUMENTS                ║\n");
	else if (code == POS_ARGS)
		printf("║         ALL ARGUMENTS MUST BE POSITIVE INTEGERS         ║\n");
	else if (code == MALLOC)
		printf("║                 MEMORY ALLOCATION FAILED                ║\n");
	else if (code == SLEEP)
		printf("║                   SLEEP ERROR DETECTED                  ║\n");
	else if (code >= TH_CREATE && code <= TH_INVALID)
		thread_message(code);
	else if (code >= MTX_INIT && code <= MTX_INVALID)
		mutex_message(code);
	printf("╚═════════════════════════════════════════════════════════╝\n");
	printf(RESET);
	if (code != NUM_ARGS && code != POS_ARGS)
		return ;
	printf(BOLD GREEN "\nUsage:" BOLD_OFF "\t./philo " ITALIC "number\
_of_philosophers time_to_die time_to_eat time_to_sleep " ITALIC_OFF "[" ITALIC\
"number_of_times_each_philosopher_must_eat" ITALIC_OFF "]\n");
	printf(BOLD YELLOW"\nExamples:\n" BOLD_OFF "\t./philo 5 800 200 200\n\
\t./philo 5 800 200 200 7\n\n" RESET);
}

static void	philo_message(t_print_code code, size_t id)
{
	if (code == PHILO_FORK)
		printf("Philosopher [%zu] has taken a fork\n", id);
	else if (code == PHILO_EAT)
		printf("Philosopher [%zu] is eating\n", id);
	else if (code == PHILO_SLEEP)
		printf("Philosopher [%zu] is sleeping\n", id);
	else if (code == PHILO_THINK)
		printf("Philosopher [%zu] is thinking\n", id);
	else
		printf("Philosopher [%zu] died\n", id);
	printf(RESET);
}

void	print_message(t_print_code code, t_philo *philo)
{
	static const char	*colors[] = {
		WHITE,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN
	};
	const size_t		color_count = sizeof(colors) / sizeof(colors[0]);
	const char			*text_color;

	if (code >= NUM_ARGS && code <= MTX_INVALID)
	{
		error_message(code);
		return ;
	}
	if (philo->is_dead)
		text_color = RED;
	else
		text_color = colors[philo->id % color_count];
	printf(BOLD "%s%zu\t" BOLD_OFF, text_color, philo->start_time); // TODO: Fix timestamp
	philo_message(code, philo->id);
}
