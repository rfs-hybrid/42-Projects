#include "list.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	if (!lst || !lst->next)
		return (lst);
	t_list	*begin = lst;
	while (lst)
	{
		t_list	*current = lst->next;
		while (current)
		{
			if (!cmp(lst->data, current->data))
				ft_swap(&lst->data, &current->data);
			current = current->next;
		}
		lst = lst->next;
	}
	return (begin);
}
