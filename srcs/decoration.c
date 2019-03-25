#include "ft_select.h"

int		move_right(t_arg_list *lst, t_print_info *info, char *direction)
{
	t_arg_list *tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (!tmp->current)
		tmp = tmp->next;
	if (ft_strncmp(direction, "right", 6) == 0)
	{
		tmp->current = 0;
		tmp->next->current = 1;
	}
	print_list(lst, info);
	return (1);
}
