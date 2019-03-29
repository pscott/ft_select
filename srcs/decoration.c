#include "ft_select.h"

int		move_vertically(t_arg_list *lst, t_print_info *info, char *direction)
{
	t_arg_list *tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (!tmp->current)
		tmp = tmp->next;
	if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp->current = 0;
		tmp->next->current = 1;
	}
	else if (ft_strncmp(direction, "up", 3) == 0)
	{
		tmp->current = 0;
		tmp->prev->current = 1;
	}
	else
		return (0);
	print_list(lst, info);
	return (1);
}

int		move_horizontally(t_arg_list *lst, t_print_info *info, char *direction)
{
	t_arg_list *tmp;
	int			jmp;
	int			target;
	int			elem;

	if (!lst)
		return (0);
	tmp = lst;
	while (!tmp->current)
		tmp = tmp->next;
	tmp->current = 0;
	jmp = 0;
	if (ft_strncmp(direction, "right", 6) == 0)
	{
		if (tmp->id + info->nb_lines > info->nb_elem)
			jmp = info->nb_elem - tmp->id + (tmp->id % info->nb_lines + 1);
		else
			jmp = info->nb_lines;
	}
	else if (ft_strncmp(direction, "left", 5) == 0)
	{
		if (tmp->id - info->nb_lines < 1)
		{
			jmp = -tmp->id;
			target = tmp->id % info->nb_lines - 1;
			elem = info->nb_elem % info->nb_lines;
			jmp -= (target > elem) ? info->nb_lines + (elem - target) : elem - target;
		}
		else
			jmp = -info->nb_lines;
	}
	else
		return (0);
//	ft_printf("JMP: %d\n", jmp);
//	sleep(3);
	tmp = jump_nodes(tmp, jmp);
	tmp->current = 1;
	print_list(lst, info);
//	print_info(info);
//	ft_printf(" HERE: %d\n", tmp->id);
	return (1);
}
