#include "ft_select.h"

static void			print_node(t_arg_list *tmp, int width)
{
	if (tmp->current)
		execute_str(UNDERLINE);
	if (tmp->highlighted)
		execute_str(HIGHLIGHT);
	ft_dprintf(STDERR, "%-*s", width, tmp->name);
	if (tmp->highlighted)
		execute_str(NO_HIGHLIGHT);
	if (tmp->current)
		execute_str(NO_UNDERLINE);
	write(STDERR, "  ", 2);
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

static int			setup_print(t_arg_list *lst, t_print_info *info)
{
	execute_str(CLEAR_BELOW);
	execute_str(BEGIN_LINE);
	if (!lst)
	{
		term_putstr_endline("error: arg_list is empty", STDERR);
		return (0);
	}
	if (!(info->elem_per_line))
	{
		execute_str(LEFT_CORNER);
		execute_str(CLEAR_BELOW);
		if (info->w.ws_col * info->w.ws_row < 23)
			ft_dprintf(STDERR, "RLY?");
		else
			ft_dprintf(STDERR, "Terminal size too small");
		return (0);
	}
	return (1);
}

void				print_list(t_arg_list *lst, t_print_info *info)
{
	int		total_printed;
	int		jmp;

	if (setup_print(lst, info) == 0)
		return ;
	total_printed = 0;
	while (total_printed < info->nb_elem)
	{
		print_node(lst, info->max_name_size);
		if (lst->id + info->nb_lines > info->nb_elem)
		{
			print_line();
			jmp = info->nb_elem - lst->id + (lst->id % info->nb_lines + 1);
		}
		else
			jmp = info->nb_lines;
		lst = jump_nodes(lst, jmp);
		total_printed++;
	}
	reposition_cursor(info);
}
