/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:38:42 by maaugust          #+#    #+#             */
/*   Updated: 2025/05/30 17:36:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_split_list(char **words)
{
	t_list	*split;
	t_list	*tmp;
	size_t	i;

	split = NULL;
	tmp = split;
	i = 0;
	while (words[i])
	{
		tmp = (t_list *)ft_calloc(1, sizeof(t_list));
		tmp->content = ft_strdup(words[i++]);
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

	i = 0;
	tmp = *split;
	while (tmp)
	{
		new = (t_stack *)ft_calloc(1, sizeof(t_stack));
		if (!new)
		{
			ft_stackclear(stack);
			ft_lstclear(split, free);
			print_error();
		}
		new->current_i = i++;
		new->final_i = new->current_i;
		new->value = ft_atoi(tmp->content);
		new->next = NULL;
		if (!*stack)
			*stack = new;
		else
			ft_stackadd_back(stack, new);
		tmp = tmp->next;
	}
}

t_stack	*string_to_stack(char *str)
{
	t_stack	*stack;
	t_list	*split;
	char	**words;

	stack = NULL;
	words = ft_split(str, ' ');
	if (!words)
		return (stack);
	validation(words, false);
	split = get_split_list(words);
	free_words(words);
	if (!split)
		return (stack);
	split_to_stack(&stack, &split);
	ft_lstclear(&split, free);
	return (stack);
}
