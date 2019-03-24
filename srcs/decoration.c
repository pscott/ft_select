#include "ft_select.h"

int		move_right(t_arg_list *lst, t_print_info *info, char *direction)
{
	if (!lst)
		return (0);
	while (!lst->current)
		lst = lst->next;
	if (ft_strncmp(direction, "right", 6) == 0)
	{
		lst->current = 0;
		lst->next->current = 1;
	}
	print_list(lst, info);
	return (1);
}
