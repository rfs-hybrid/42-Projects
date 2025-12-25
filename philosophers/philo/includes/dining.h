/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:43:27 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 16:14:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINING_H
# define DINING_H

/**
 * @fn void *dining(void *arg)
 * @brief The main thread routine for a philosopher.
 * @details Handles the synchronization start and the Eat -> Sleep -> Think
 * cycle.
 * @param arg Void pointer to the `t_philo` structure for this thread.
 * @return NULL (Standard pthread return).
 */
void	*dining(void *arg);

#endif
