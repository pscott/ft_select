#include "ft_select.h"

t_arg_list *delete_node(t_arg_list *lst, t_print_info *info)
{
	t_arg_list *tmp;
	t_arg_list *res;

	tmp = lst;
	while (tmp->current == 0)
		tmp = tmp->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->current = 0;
	tmp->next->current = 1;
	res = tmp->next;
	free(tmp->name);
	free(tmp);
	get_print_info(res, info);
	print_list(res, info);
	return (res);
}
