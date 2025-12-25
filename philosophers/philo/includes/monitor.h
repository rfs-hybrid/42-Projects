/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:19:01 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/25 16:15:08 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

/**
 * @fn void *monitor(void *arg)
 * @brief The routine for the monitor thread.
 * @details Watches for philosopher deaths or if the meal quota is met.
 * @param arg Void pointer to the shared `t_data` structure.
 * @return NULL (Standard pthread return).
 */
void	*monitor(void *arg);

#endif
