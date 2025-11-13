/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:24:58 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/13 15:27:57 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_mini	t_mini;

typedef struct s_env
{
	char			*key;
	char			*val;
	bool			is_set;
	struct s_env	*next;
}	t_env;

void	env_add_back(t_env **env, t_env *new);
void	env_list_clear(t_env **env);
void	env_init(t_mini *mini, char **envp);

#endif
