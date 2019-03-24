#include "ft_select.h"

t_arg_list	*jump_nodes(t_arg_list *lst, int num)
{
	while (num > 0)
	{
		lst = lst->next;
		num--;
	}
	while (num < 0)
	{
		lst = lst->prev;
		num++;
	}
	return (lst);
}

static	void		print_node(t_arg_list *tmp, int width)
{
	if (tmp->current)
		execute_str(UNDERLINE);
	if (tmp->highlighted)
		execute_str(HIGHLIGHT);
	ft_printf("%-*s", width, tmp->name);
	if (tmp->highlighted)
		execute_str(NO_HIGHLIGHT);
	if (tmp->current)
		execute_str(NO_UNDERLINE);
	write(STDOUT, "  ", 2);
}

void				print_list(t_arg_list *lst, t_print_info *info)
{
	t_arg_list		*tmp;
	int				print_w;
	int				printed;

	print_w = info->print_width + SPACING;
	if (!(tmp = lst))
	{
		term_putstr_endline("error: arg_list is empty", STDERR);
		return ;
	}
	print_node(tmp, print_w);
	printed = 1;
	while ((tmp = jump_nodes(tmp, info->nb_lines)) && (printed < info->nb_elem))
	{
		if (((printed) % info->elem_per_line == 0))
		{
			if (!(info->nb_elem % info->nb_lines))
				tmp = tmp->next;
			print_line();
		}
		print_node(tmp, print_w);
		printed++;
	}
}
