#include <stdio.h>
#include <stdlib.h>

static void	find_subsets(int *set, int set_size, int target, int *subset,
						int subset_size, int subset_sum, int index)
{
	if (subset_sum == target)
	{
		for (int i = 0; i < subset_size; i++)
		{
			printf("%d", subset[i]);
			if (i < subset_size - 1)
				printf(" ");
		}
		printf("\n");
	}
	for (int i = index; i < set_size; i++)
	{
		subset[subset_size] = set[i];
		find_subsets(set, set_size, target, subset,
					subset_size + 1, subset_sum + set[i], i + 1);
	}
}

int	main(int argc, char **argv)
{
	int	*set;
	int	*subset;
	int	target;
	int	set_size;

	if (argc < 2)
		return (EXIT_FAILURE);
	target = atoi(argv[1]);
	set_size = argc - 2;
	set = (int *) malloc(sizeof(int) * set_size);
	if (!set)
		return (EXIT_FAILURE);
	for (int i = 0; i < set_size; i++)
		set[i] = atoi(argv[i + 2]);
	subset = (int *) malloc(sizeof(int) * set_size);
	if (!subset)
		return (free(set), EXIT_FAILURE);
	find_subsets(set, set_size, target, subset, 0, 0, 0);
	return (free(set), free(subset), EXIT_SUCCESS);
}
