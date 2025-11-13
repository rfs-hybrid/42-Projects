/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:29:29 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/13 15:52:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extras.h"
#include "minishell.h"

static void	get_hostname(char **host)
{
	char	*ptr;
	int		fd;
	size_t	len;

	fd = open("/etc/hostname", O_RDONLY);
	if (fd != -1)
	{
		*host = get_next_line(fd);
		len = ft_strlen(*host);
		if ((*host)[len - 1] == 'n')
			(*host)[len - 1] = '\0';
		ptr = ft_strchr(*host, '.');
		(*host)[ptr - *host] = '\0';
		close (fd);
		return (free(ptr));
	}
	*host = ft_strdup("localhost");
}

static void	get_username(char **user, t_env *env)
{
	*user = NULL;
	while (env)
	{
		if ((ft_strlen(env->key) < ft_strlen("USER")
				&& !ft_strncmp(env->key, "USER", ft_strlen("USER")))
			|| (ft_strlen(env->key) >= ft_strlen("USER")
				&& !ft_strncmp(env->key, "USER", ft_strlen(env->key))))
		{
			*user = ft_strdup(env->val);
			break ;
		}
		env = env->next;
	}
	if (!*user)
		*user = ft_strdup("minishell");
}

void	get_prompt_info(t_info *info, t_env *env)
{
	get_hostname(&info->host);
	get_username(&info->user, env);
}
