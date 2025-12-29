/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 00:18:26 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/29 17:43:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <stdbool.h>
# include <string.h>

/** @brief Forward declaration of main data structure. */
typedef struct s_data	t_data;

/**
 * @fn void initialization(t_data *data, char **argv)
 * @brief Validates arguments and initializes the main data structure.
 * @details Allocation errors will cause the program to exit.
 * @param data Pointer to the shared data structure to initialize.
 * @param argv Command line arguments (shifted to start at the first parameter).
 */
void	initialization(t_data *data, char **argv);

#endif
