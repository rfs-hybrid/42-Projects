/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:23:28 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/13 15:39:08 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	env_add_back(t_env **env, t_env *new)
{
	t_env	*tmp;

	if (env)
	{
		tmp = *env;
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			*env = new;
	}
}

void	env_list_clear(t_env **env)
{
	t_env	*tmp;

	if (!env || !*env)
		return ;
	while (*env)
	{
		tmp = (*env)->next;
		free((*env)->key);
		free((*env)->val);
		free(*env);
		*env = tmp;
	}
}
