/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:29:11 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/13 15:46:17 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_H
# define EXTRAS_H

# include "env.h"
# include "get_next_line.h"
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_info	t_info;

void	get_prompt_info(t_info *info, t_env *env);

#endif
