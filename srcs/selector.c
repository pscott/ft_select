#include "ft_select.h"

int		select_node(t_arg_list *lst, t_print_info *info)
{
	t_arg_list *tmp;

	tmp = lst;
	while (tmp->current == 0)
		tmp = tmp->next;
	tmp->highlighted = !tmp->highlighted;
	tmp->current = 0;
	tmp->next->current = 1;
	print_list(lst, info);
	return (1);
}
