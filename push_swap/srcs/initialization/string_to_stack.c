/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:38:42 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 17:49:51 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_words(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free (words);
	words = NULL;
}

static t_list	*get_split_list(char **words)
{
	t_list	*split;
	t_list	*tmp;
	size_t	i;

	split = NULL;
	tmp = split;
	i = -1;
	while (words[++i])
	{
		tmp = (t_list *)ft_calloc(1, sizeof(t_list));
		tmp->content = ft_strdup(words[i]);
		if (!(tmp->content))
		{
			ft_lstclear(&split, free);
			ft_lstdelone(tmp, free);
			return (NULL);
		}
		ft_lstadd_back(&split, tmp);
		tmp = tmp->next;
	}
	return (split);
}

static void	split_to_stack(t_stack **stack, t_list **split)
{
	t_stack	*new;
	t_list	*tmp;
	int		i;

	tmp = *split;
	i = -1;
	while (tmp)
	{
		new = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (!new)
		{
			ft_stackclear(stack);
			ft_lstclear(split, free);
			ft_print_error();
		}
		new->val = ft_atoi(tmp->content);
		new->idx = ++i;
		new->lis = false;
		new->next = NULL;
		ft_stackadd_back(stack, new);
		tmp = tmp->next;
	}
}

t_stack	*ft_string_to_stack(char *str)
{
	t_stack	*stack;
	t_list	*split;
	char	**words;

	stack = NULL;
	words = ft_split(str, ' ');
	if (!words)
		return (stack);
	if (!ft_validation(words))
	{
		free_words(words);
		ft_print_error();
	}
	split = get_split_list(words);
	free_words(words);
	if (!split)
		return (stack);
	split_to_stack(&stack, &split);
	ft_lstclear(&split, free);
	return (stack);
}
