#include "ft_select.h"

int		highlight_node(t_arg_list *lst)
{
	t_arg_list *tmp;

	tmp = lst;
	while (tmp->current == 0)
		tmp = tmp->next;
	tmp->highlighted = !tmp->highlighted;
	tmp->current = 0;
	tmp->next->current = 1;
	return (1);
}