/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:20 by maaugust          #+#    #+#             */
/*   Updated: 2026/01/07 15:52:52 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_bonus.h"
#include "philo_bonus.h"
#include "printer_bonus.h"
#include "safety_bonus.h"
#include "utils_bonus.h"

/**
 * @fn static void semaphore_init(t_data *data)
 * @brief Initializes all named semaphores used in the simulation.
 * @details Unlinks any existing semaphores with the same names first, then
 * opens new ones.
 * - `print`: Serializes output (1).
 * - `full`: Counts full philosophers (0).
 * - `waiter`: Limits concurrent eaters (total_philos - 1).
 * - `forks`: The pool of forks (total_philos).
 * @param data Pointer to the main data structure.
 */
static void	semaphore_init(t_data *data)
{
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_FULL);
	sem_unlink(SEM_WAITER);
	sem_unlink(SEM_FORKS);
	data->print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	data->full = sem_open(SEM_FULL, O_CREAT, 0644, 0);
	data->waiter = sem_open(SEM_WAITER, O_CREAT, 0644, data->total_philos - 1);
	data->forks = sem_open(SEM_FORKS, O_CREAT, 0644, data->total_philos);
	if (data->print == SEM_FAILED || data->full == SEM_FAILED
		|| data->waiter == SEM_FAILED || data->forks == SEM_FAILED)
		exit_error(SEM_OPEN, data);
}

/**
 * @fn static int number_of_digits(int num)
 * @brief Helper function to count the digits in an integer.
 * @details Used to calculate exactly how much memory to allocate for the
 * semaphore name string when appending the philosopher's ID.
 * @param num The number to count.
 * @return The number of digits.
 */
static int	number_of_digits(int num)
{
	int	count;

	count = 1;
	while (num >= 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}

/**
 * @fn static char *generate_meal_sem_name(long index)
 * @brief Generates a unique name for a philosopher's meal semaphore.
 * @details Concatenates the base name defined in `SEM_MEAL` with the
 * philosopher's specific index (e.g., "/philo_meal_1").
 * This is crucial because `sem_open` requires unique names to create
 * distinct semaphores for each process.
 * @param index The philosopher's index (0 to total_philos - 1).
 * @return A dynamically allocated string containing the unique name,
 * or NULL if allocation fails.
 */
static char	*generate_meal_sem_name(long index)
{
	char	*name;
	long	tmp;
	int		name_len;
	int		index_len;

	name_len = -1;
	while (SEM_MEAL[++name_len])
		;
	index_len = number_of_digits(index);
	name = safe_malloc(sizeof(char) * (name_len + index_len + 1));
	if (!name)
		return (NULL);
	name[name_len + index_len] = '\0';
	tmp = -1;
	while (++tmp < name_len)
		name[tmp] = SEM_MEAL[tmp];
	while (index_len-- > 0)
	{
		name[name_len + index_len] = (index % 10) + '0';
		index /= 10;
	}
	return (name);
}

/**
 * @fn static void philo_data(t_data *data, t_philo *philo, long index)
 * @brief Initializes individual philosopher data.
 * @details Generates a unique named semaphore (e.g., "/philo_meal_1") 
 * to protect this specific philosopher's `last_meal` variable.
 * Unlinks the name immediately after opening so it cleans up on exit.
 * @param data Pointer to shared data.
 * @param philo Pointer to the philosopher to init.
 * @param index The philosopher's index.
 */
static void	philo_data(t_data *data, t_philo *philo, long index)
{
	char	*name;

	memset(philo, 0, sizeof(t_philo));
	philo->philo_id = index + 1;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->data = data;
	name = generate_meal_sem_name(index);
	if (!name)
		exit_error(MALLOC, data);
	sem_unlink(name);
	philo->meal = sem_open(name, O_CREAT, 0644, 1);
	if (philo->meal == SEM_FAILED)
	{
		free(name);
		exit_error(SEM_OPEN, data);
	}
	if (sem_unlink(name) != 0)
	{
		free(name);
		exit_error(SEM_UNLINK, data);
	}
	free(name);
}

/**
 * @fn void initialization(t_data *data, char **argv)
 * @brief Parses arguments and initializes the main data structure.
 * @details Converts arguments to integers, allocates memory for philosophers,
 * and calls sub-initialization functions for data and semaphores.
 * @param data Pointer to the main data structure to initialize.
 * @param argv Command line arguments (shifted to start at the first parameter).
 */
void	initialization(t_data *data, char **argv)
{
	long	i;

	data->total_philos = ft_atol(*argv++);
	data->time_to_die = ft_atol(*argv++);
	data->time_to_eat = ft_atol(*argv++);
	data->time_to_sleep = ft_atol(*argv++);
	data->total_meals = -1;
	if (*argv)
		data->total_meals = ft_atol(*argv);
	data->start_time = 0;
	data->philos = safe_malloc(sizeof(t_philo) * data->total_philos);
	if (!data->philos)
		exit_error(MALLOC, data);
	i = -1;
	while (++i < data->total_philos)
		philo_data(data, &data->philos[i], i);
	semaphore_init(data);
}
