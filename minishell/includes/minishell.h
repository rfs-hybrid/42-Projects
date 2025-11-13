/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:21:46 by maaugust          #+#    #+#             */
/*   Updated: 2025/11/13 15:02:16 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "env.h"
# include "extras.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_info
{
	char	*user;
	char	*host;
}	t_info;

typedef struct s_prompt
{
	t_info	info;
}	t_prompt;

typedef struct s_mini
{
	t_prompt	prompt;
	t_env		*env;
}	t_mini;

#endif
