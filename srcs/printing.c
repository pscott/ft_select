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
	write(STDIN, "  ", 2);
}

void				print_selected(t_arg_list *lst, t_print_info *info)
{
	t_arg_list		*tmp;
	int				print_w;

	print_w = info->print_width;
	if (!(tmp = lst))
	{
		term_putstr_endline("error: arg_list is empty", STDERR);
		return ;
	}
	if (tmp->highlighted)
		print_node(tmp, print_w);
	while ((tmp = tmp->next) && (tmp != lst))
	{
		if (tmp->highlighted)
			print_node(tmp, print_w);
	}
}

void				print_list(t_arg_list *lst, t_print_info *info)
{
	t_arg_list		*tmp;
	int				print_w;
	int				i;
	int				total_printed;

	print_w = info->print_width;
	if (!(tmp = lst))
	{
		term_putstr_endline("error: arg_list is empty", STDERR);
		return ;
	}
	print_node(tmp, print_w);
	i = 1;
	total_printed = 1;
	while ((tmp = jump_nodes(tmp, info->nb_lines)) && (total_printed < info->nb_elem))
	{
		if ((i % info->elem_per_line) == 0)
		{
/*			if ((info->nb_elem - lst->id) % info->elem_per_line)
			{
				ft_printf("!!");
				print_node(tmp, print_w);
			}*/
			if ((info->nb_elem - total_printed) % info->nb_lines)
			{
				print_node(tmp, print_w);
				total_printed++;
				tmp = jump_nodes(tmp, info->nb_lines);
			}
			if (((info->nb_elem) % info->nb_lines) == 0)
				tmp = tmp->next;
			print_line();
			i = 0;
		}
		print_node(tmp, print_w);
		total_printed++;
		i++;
	}
	/*
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
	}*/
//	move_cursor(info->pos.col, info->pos.row);
	execute_str(RESTORE_CURSOR);
}
