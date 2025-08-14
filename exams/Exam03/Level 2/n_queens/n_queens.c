#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool	is_safe(int row, int col, int *queens)
{
	for (int i = 0; i < row; i++)
		if (queens[i] == col
			|| queens[i] - i == col - row
			|| queens[i] + i == col + row)
			return (false);
	return (true);
}

static void	solve(int n, int row, int *queens)
{
	if (row == n)
	{
		for (row = 0; row < n; row++)
		{
			fprintf(stdout, "%d", queens[row]);
			if (row < n - 1)
				fprintf(stdout, " ");
		}
		return ((void) fprintf(stdout, "\n"));
	}
	for (int col = 0; col < n; col++)
	{
		if (is_safe(row, col, queens))
		{
			queens[row] = col;
			solve(n, row + 1, queens);
		}
	}
}

int	main(int argc, char **argv)
{
	int	*queens;
	int	n;

	if (argc != 2)
		return (EXIT_FAILURE);
	n = atoi (argv[1]);
	if (n <= 0)
		return (EXIT_FAILURE);
	queens = (int *) malloc(sizeof(int) * n);
	if (!queens)
		return (EXIT_FAILURE);
	solve(n, 0, queens);
	return (free(queens), EXIT_SUCCESS);
}
