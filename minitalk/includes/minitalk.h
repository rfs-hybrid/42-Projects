/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:58:08 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/09 17:10:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

/* Total number of bits in a char */
# define CHAR_BITS	8

/* Client timeout handling */
# define TIMEOUT_MS 3000
# define SLEEP_US   1000

/* Client signal handling status */
# define PAUSE	0
# define ACK	1

/* Typedef for byte declaration */
typedef unsigned char	t_byte;

#endif