/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:19:28 by maaugust          #+#    #+#             */
/*   Updated: 2025/06/21 16:56:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "ft_printf.h"

static void	print_error(t_stack **a, t_stack **b)
{
	ft_stackclear(a);
	ft_stackclear(b);
	ft_print_error();
}

static void	parse_command(t_stack **a, t_stack **b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		ft_run_swap(a, b, 0, true);
	else if (!ft_strcmp(cmd, "sb\n"))
		ft_run_swap(a, b, 1, true);
	else if (!ft_strcmp(cmd, "ss\n"))
		ft_run_swap(a, b, 2, true);
	else if (!ft_strcmp(cmd, "pa\n"))
		ft_run_push(a, b, 0, true);
	else if (!ft_strcmp(cmd, "pb\n"))
		ft_run_push(a, b, 1, true);
	else if (!ft_strcmp(cmd, "ra\n"))
		ft_run_rotation(a, b, 0, true);
	else if (!ft_strcmp(cmd, "rb\n"))
		ft_run_rotation(a, b, 1, true);
	else if (!ft_strcmp(cmd, "rr\n"))
		ft_run_rotation(a, b, 2, true);
	else if (!ft_strcmp(cmd, "rra\n"))
		ft_run_reverse_rotation(a, b, 0, true);
	else if (!ft_strcmp(cmd, "rrb\n"))
		ft_run_reverse_rotation(a, b, 1, true);
	else if (!ft_strcmp(cmd, "rrr\n"))
		ft_run_reverse_rotation(a, b, 2, true);
	else
		print_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	line = NULL;
	if (argc < 2 || (argc == 2 && !*argv[1]))
		return (0);
	ft_stack_init(&a, argc, argv);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		parse_command(&a, &b, line);
		free (line);
		line = get_next_line(STDIN_FILENO);
	}
	if (ft_stack_is_sorted(a, false) && !ft_stack_size(b))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
