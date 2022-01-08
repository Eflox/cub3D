#include "../include/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && *alst && new)
	{
		tmp = *alst;
		while (new && tmp && tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
	else if (alst)
	{
		*alst = new;
	}
}
