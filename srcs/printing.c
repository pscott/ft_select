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
	write(STDIN_FILENO, "  ", 2);
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

static int			enough_printing_room(t_print_info *info)
{
	t_pos	curr_pos;
	int		size;

	retrieve_pos(&curr_pos);
	size = info->w.ws_col * (info->w.ws_row - curr_pos.row) - (info->w.ws_col - curr_pos.col);
	if (size < info->nb_chars)
		return (1);
	else
		return (0);
}

void				print_list(t_arg_list *lst, t_print_info *info)
{
	t_arg_list		*tmp;
	int				total_printed;
	int				jmp;

	execute_str(CLEAR_BELOW);
	if (!(tmp = lst))
	{
		term_putstr_endline("error: arg_list is empty", STDERR);
		return ;
	}
/*	if (!enough_printing_room(info))
	{
		term_putstr_endline("error: not enough room to print", STDERR);
		info->nb_lines = 2;
		reposition_cursor(info);
		return ;
	}*/
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
