/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:40:47 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/02 20:10:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"

typedef struct s_stack {
	int				value;
	int				current_i;
	int				final_i;
	int				ops;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	stack_init(t_stack **a, int argc, char **argv);
t_stack	*string_to_stack(char *str);
t_stack	*argv_to_stack(char **argv);
void	push_swap(t_stack *a, t_stack *b);
void	validation(char **words, bool is_argv);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);
void	free_words(char **words);
long	ft_atol(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);
void	print_error(void);
bool	is_sorted(t_stack *a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a);
void	pb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif