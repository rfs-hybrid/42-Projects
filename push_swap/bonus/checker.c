/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:19:28 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/19 20:08:43 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_error(t_stack **a, t_stack **b)
{
	ft_stackclear(a);
	ft_stackclear(b);
	ft_print_error();
}

static void	parse_command(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		ft_run_swap(a, b, 0, true);
	if (!ft_strcmp(cmd, "sb"))
		ft_run_swap(a, b, 1, true);
	if (!ft_strcmp(cmd, "ss"))
		ft_run_swap(a, b, 2, true);
	if (!ft_strcmp(cmd, "pa"))
		ft_run_push(a, b, 0, true);
	if (!ft_strcmp(cmd, "pb"))
		ft_run_push(a, b, 1, true);
	if (!ft_strcmp(cmd, "ra"))
		ft_run_rotation(a, b, 0, true);
	if (!ft_strcmp(cmd, "rb"))
		ft_run_rotation(a, b, 1, true);
	if (!ft_strcmp(cmd, "rr"))
		ft_run_rotation(a, b, 2, true);
	if (!ft_strcmp(cmd, "rra"))
		ft_run_reverse_rotation(a, b, 0, true);
	if (!ft_strcmp(cmd, "rrb"))
		ft_run_reverse_rotation(a, b, 1, true);
	if (!ft_strcmp(cmd, "rrr"))
		ft_run_reverse_rotation(a, b, 2, true);
	else
		print_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !*argv[1]))
		return (0);
	ft_stack_init(&a, argc, argv);
	size = ft_stack_size(a);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		parse_command(a, b, line);
		free (line);
		get_next_line(STDIN_FILENO);
	}
	if (ft_stack_is_sorted(a, false) && ft_stack_size(a) == size)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
