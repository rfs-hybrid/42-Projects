/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:40:47 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/17 15:52:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>

/* Stack double circular linked list */
typedef struct s_stack
{
	int				val;
	int				idx;
	int				cost;
	bool			top;
	bool			lis;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lis
{
	int		*arr;
	int		size;
}	t_lis;

/* Stack initialization */
void	ft_stack_init(t_stack **stack, int argc, char **argv);
t_stack	*ft_string_to_stack(char *str);
t_stack	*ft_argv_to_stack(char **argv);
void	validation(char **words, bool is_argv);

/* Utility functions */
bool	ft_stack_is_semi_sorted(t_stack *stack, bool is_rev);
bool	ft_stack_is_sorted(t_stack *stack, bool is_rev);
void	ft_free_words(char **words);
long	ft_atol(const char *nptr);
int		ft_strcmp(const char *s1, const char *s2);

void	ft_print_error(void);\
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);
int		ft_stack_size(t_stack *stack);
int		ft_stack_max_val(t_stack *stack);
int		ft_stack_min_val(t_stack *stack);
void	ft_stack_reset_indexes(t_stack **stack);

/* Commands */
void	ft_run_push(t_stack **a, t_stack **b, int op);
void	ft_run_swap(t_stack **a, t_stack **b, int op);
void	ft_run_rotation(t_stack **a, t_stack **b, int op);
void	ft_run_reverse_rotation(t_stack **a, t_stack **b, int op);

/* Algorithm functions */
void	ft_push_swap(t_stack **a, t_stack **b, int size);
int		*ft_lis_sequence(int *arr, int size, int *lis_len);
void	ft_lis_algorithm(t_stack **a, t_stack **b, t_lis lis);
t_stack	*find_cheapest(t_stack **stack);
void	run_commands(t_stack **s1, t_stack **s2, t_stack *node, bool is_a);
void	stack_index_cost(t_stack **stack);

#endif