/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:23:54 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/13 15:51:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	mini_init(t_mini *mini, char **envp)
{
	mini->prompt.info.host = NULL;
	mini->prompt.info.user = NULL;
	env_init(mini, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	t_env	*tmp;
	char	*prompt;

	(void) argc;
	(void) argv;
	mini_init(&mini, envp);
	get_prompt_info(&mini.prompt.info, mini.env);
	while (true)
	{
		printf("%s@%s:", mini.prompt.info.user, mini.prompt.info.host);
		prompt = readline(" ");
		if (!prompt)
			break;
		if (!ft_strncmp(prompt, "env", 3))
		{
			tmp = mini.env;
			while (tmp)
			{
				printf("%s=%s\n", tmp->key, tmp->val);
				tmp = tmp->next;
			}
		}
		free(prompt);
	}
	// free(mini.prompt.info.host);
	// free(mini.prompt.info.user);
	env_list_clear(&mini.env);
	return (EXIT_SUCCESS);
}
