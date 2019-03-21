#include "ft_select.h"

static void	free_node(t_arg_list *lst)
{
	ft_memdel((void*)&lst->name);
	ft_memdel((void*)&lst);
}

void		free_list(t_list_addr *addr)
{
	t_arg_list *lst;
	t_arg_list *tmp;

	lst = addr->head;
	while (lst->next != addr->head)
	{
		tmp = lst;
		lst = lst->next;
		free_node(tmp);
	}
	free_node(lst);
	ft_memdel((void*)&addr);
}
