#include "ft_ls.h"

t_ls	*ft_newlst(char *d_name)
{
	t_ls	*new;

	new = NULL;
	if ((new = ft_memalloc(sizeof(t_ls))) != NULL)
	{
		new->name = d_name;
		new->next = NULL;
	}
	return (new);
}

void	ft_addlst(t_ls **list, char *d_name)
{
	t_ls	*tmp;

	tmp = *list;
	if (*list == NULL)
		*list = ft_newlst(d_name);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_newlst(d_name);
	}
}