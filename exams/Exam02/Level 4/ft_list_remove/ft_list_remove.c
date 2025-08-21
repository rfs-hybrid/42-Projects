#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list && *begin_list)
	{
		if (!cmp((*begin_list)->data, data_ref))
		{
			t_list	*tmp = (*begin_list)->next;
			free(*begin_list);
			(*begin_list) = tmp;
			ft_list_remove_if(begin_list, data_ref, cmp);
		}
		else
			ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
	}
}
