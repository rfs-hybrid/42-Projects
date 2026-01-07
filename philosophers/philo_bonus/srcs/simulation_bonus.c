/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 15:04:25 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/07 15:52:43 by maaugust         ###   ########.fr       */
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
 * @fn static void handle_fork_error(t_data *data, long count)
 * @brief Handles partial cleanup if a fork fails during startup.
 * @details Kills and waits only for the processes created so far (up to
 * `count`), then exits the program to prevent undefined behavior.
 * @param data Pointer to the shared data.
 * @param count The number of processes successfully created before the
 * failure.
 */
static void	handle_fork_error(t_data *data, long count)
{
	long	i;

	i = -1;
	while (++i < count)
		kill(data->philos[i].pid, SIGKILL);
	i = -1;
	while (++i < count)
		waitpid(data->philos[i].pid, NULL, 0);
	exit_error(FORK, data);
}

/**
 * @fn static void start_processes(t_data *data)
 * @brief Forks a child process for each philosopher.
 * @details Loops through the total number of philosophers and forks a new
 * process for each. Each child process runs the `dining` routine.
 * If a fork fails, it calls `handle_fork_error` to cleanly destroy existing
 * processes before exiting.
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
			handle_fork_error(data, i);
		if (philo_pid == 0)
			dining(&data->philos[i]);
		data->philos[i].pid = philo_pid;
	}
}

/**
 * @fn void simulation(t_data *data)
 * @brief Orchestrates the main simulation flow in the parent process.
 * @details
 * 1. Starts all philosopher processes.
 * 2. If a meal limit is set, forks a dedicated monitoring process.
 * 3. Blocks on `waitpid(-1)` waiting for ANY child process to terminate
 * (due to death, full meals, or manual kill).
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
	waitpid(-1, NULL, 0);
	if (usleep(5000) != 0)
		exit_error(SLEEP, data);
	kill_all_philos(data);
	if (data->total_meals != -1 && meal_pid != -1)
	{
		kill(meal_pid, SIGKILL);
		waitpid(meal_pid, NULL, 0);
	}
	wait_all_philos(data);
}
