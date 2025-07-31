/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:13:01 by maaugust          #+#    #+#             */
/*   Updated: 2025/07/29 15:24:18 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

bool	is_valid(int *queens, int row, int col)
{
	int	i;

	i = -1;
	while (++i < row)
		if (queens[i] == col
			|| (queens[i] - i) == (col - row)
			|| (queens[i] + i) == (col + row))
			return (false);
	return (true);
}

void	solve(int n, int row, int *queens)
{
	int	col;
	int	i;

	if (row == n)
	{
		i = -1;
		while (++i < n)
		{
			printf("%d", queens[i]);
			if (i < n - 1)
				printf(" ");
		}
		return ((void) printf("\n"));
	}
	col = -1;
	while (++col < n)
	{
		if (is_valid(queens, row, col))
		{
			queens[row] = col;
			solve(n, row + 1, queens);
		}
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*queens;

	if (argc != 2)
		return (EXIT_FAILURE);
	n = atoi(argv[1]);
	if (n <= 0)
		return (EXIT_FAILURE);
	queens = (int *) malloc(sizeof(int) * n);
	if (!queens)
	{
		write(STDERR_FILENO, "Error: memory allocation\n", 25);
		return (EXIT_FAILURE);
	}
	solve(n, 0, queens);
	free(queens);
	return (EXIT_SUCCESS);
}
