/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:26 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 16:15:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"
# include <string.h>

/**
 * @fn void initialization(t_data *data, char **argv)
 * @brief Validates arguments and initializes the main data structure.
 * @details Allocation errors will cause the program to exit.
 * @param data Pointer to the shared data structure to initialize.
 * @param argv Command line arguments (shifted to start at the first parameter).
 */
void	initialization(t_data *data, char **argv);

#endif
