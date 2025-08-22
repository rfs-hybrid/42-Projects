static void	ft_swap(int *a, int *b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	if (size < 2)
		return ;
	for (unsigned int i = 0; i < size - 1; i++)
		for (unsigned int j = 0; j < size - i - 1; j++)
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
}
