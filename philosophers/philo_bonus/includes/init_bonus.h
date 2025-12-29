/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:26 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:28:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

# include <fcntl.h>
# include <semaphore.h>
# include <string.h>
# include <sys/stat.h>

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @fn void initialization(t_data *data, char **argv)
 * @brief Validates arguments and initializes the simulation data.
 * @details Allocates memory for philosophers, parses arguments, and
 * opens all necessary named semaphores.
 * @param data Pointer to the shared data structure to initialize.
 * @param argv Command line arguments (shifted to start at the first parameter).
 */
void	initialization(t_data *data, char **argv);

#endif
