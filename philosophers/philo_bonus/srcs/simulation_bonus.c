/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:04:25 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/30 15:27:00 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation_bonus.h"
#include "dining_bonus.h"
#include "monitor_bonus.h"
#include "philo_bonus.h"
#include "safety_bonus.h"
#include "utils_bonus.h"

/**
 * @fn static void kill_all_philos(t_data *data)
 * @brief Sends SIGKILL to all philosopher processes.
 * @details Used to abruptly stop the simulation when a philosopher dies or
 * an error occurs.
 * @param data Pointer to the shared data.
 */
static void	kill_all_philos(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->total_philos)
		kill(data->philos[i].pid, SIGKILL);
}

/**
 * @fn static void wait_all_philos(t_data *data)
 * @brief Waits for all philosopher processes to terminate.
 * @details Ensures no zombie processes are left behind by reaping the exit
 * status of every child process created.
 * @param data Pointer to the shared data.
 */
static void	wait_all_philos(t_data *data)
{
	long	i;

	i = -1;
	while (++i < data->total_philos)
		waitpid(data->philos[i].pid, NULL, 0);
}

/**
 * @fn static void start_processes(t_data *data)
 * @brief Forks a child process for each philosopher.
 * @details Loops through the total number of philosophers and forks a new
 * process for each. Each child process runs the `dining` routine.
 * If a fork fails, it cleans up all previously created processes and exits.
 * @param data Pointer to the main data structure.
 */
static void	start_processes(t_data *data)
{
	pid_t	philo_pid;
	long	i;

	i = -1;
	while (++i < data->total_philos)
	{
		philo_pid = fork();
		if (philo_pid == -1)
		{
			while (--i >= 0)
				kill(data->philos[i].pid, SIGKILL);
			exit_error(FORK, data);
		}
		if (philo_pid == 0)
			dining(&data->philos[i]);
		data->philos[i].pid = philo_pid;
	}
}

/**
 * @fn void simulation(t_data *data)
 * @brief Orchestrates the main simulation flow in the parent process.
 * @details 1. Starts all philosopher processes.
 * 2. If a meal limit is set, forks a dedicated monitoring process.
 * 3. Waits on the `stop` semaphore (blocks until a death occurs or all eat).
 * 4. Kills and reaps all child processes (philosophers + monitor) to ensure
 * a clean exit without zombies or leaks.
 * @param data Pointer to the main data structure.
 */
void	simulation(t_data *data)
{
	pid_t	meal_pid;

	start_processes(data);
	if (data->total_meals != -1)
	{
		meal_pid = fork();
		if (meal_pid == -1)
		{
			kill_all_philos(data);
			wait_all_philos(data);
			exit_error(FORK, data);
		}
		if (meal_pid == 0)
			monitor_philo_meals(data);
	}
	safe_sem(data->stop, WAIT, data);
	kill_all_philos(data);
	if (data->total_meals != -1 && meal_pid != -1)
	{
		kill(meal_pid, SIGKILL);
		waitpid(meal_pid, NULL, 0);
	}
	wait_all_philos(data);
}
