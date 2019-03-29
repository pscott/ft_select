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

static void		print_node(t_arg_list *tmp, int width)
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

void				print_selected(t_arg_list *lst)
{
	t_arg_list		*tmp;

	if (!(tmp = lst))
	{
		term_putstr_endline("error: arg_list is empty", STDERR);
		return ;
	}
	if (tmp->highlighted)
		ft_printf("%s ", tmp->name);
	while ((tmp = tmp->next) && (tmp != lst))
	{
		if (tmp->highlighted)
			ft_printf("%s ", tmp->name);
	}
}

static int			reposition_cursor(t_print_info *info)
{
	t_pos pos;

	retrieve_pos(&pos);
	move_cursor(0, pos.row - info->nb_lines);
	return (1);
}

void				print_list(t_arg_list *lst, t_print_info *info)
{
	t_arg_list		*tmp;
	int				total_printed;
	int				jmp;

	if (!(tmp = lst))
	{
		term_putstr_endline("error: arg_list is empty", STDERR);
		return ;
	}
	total_printed = 0;
	while (total_printed < info->nb_elem)
	{
		print_node(tmp, info->max_name_size);
		if (tmp->id + info->nb_lines > info->nb_elem)
		{
			print_line();
			jmp = info->nb_elem - tmp->id + (tmp->id % info->nb_lines + 1);
		}
		else
			jmp = info->nb_lines;
		tmp = jump_nodes(tmp, jmp);
		total_printed++;
	}
	reposition_cursor(info);
}
