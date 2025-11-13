/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:28:39 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/13 15:38:15 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "minishell.h"

void	env_init(t_mini *mini, char **envp)
{
	t_env	*tmp;
	char	*ptr;

	mini->env = NULL;
	while (*envp)
	{
		tmp = ft_calloc(1, sizeof(t_env));
		if (!tmp)
			exit(EXIT_FAILURE);
		ptr = ft_strchr(*envp, '=');
		tmp->key = ft_substr(*envp, 0, ptr - *envp);
		tmp->val = ft_strdup(ptr + 1);
		tmp->is_set = 1;
		tmp->next = NULL;
		env_add_back(&mini->env, tmp);
		envp++;
	}
}
