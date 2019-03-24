#include "ft_select.h"

void			print_info(t_print_info *info)
{
	ft_printf("ELEMS: %d, MAX_NAME: %d, NB_CHARS: %d, NB_LINES: %d", info->nb_elem, info->max_name_size, info->nb_chars, info->nb_lines);
	print_line();
}

static void			update_info(t_arg_list *lst, t_print_info *info)
{
	int		name_size;

	name_size = lst->name ? ft_strlen(lst->name) : 0;
	info->nb_elem += 1;
	if (name_size > info->max_name_size)
		info->max_name_size = name_size;
}

static void			get_args_len(t_arg_list *lst, t_print_info *info)
{
	t_arg_list	*tmp;

	if (!lst)
		return ;
	if ((tmp = lst))
		update_info(tmp, info);
	while ((tmp = tmp->next) && tmp != lst)
		update_info(tmp, info);
}

static int			get_print_width(t_arg_list *lst, t_print_info *info)
{
	
	if (!lst)
		return (0);
	get_args_len(lst, info);
	info->nb_chars = info->nb_elem * (info->max_name_size + 2);
	while ((info->nb_chars / info->nb_lines) >= info->w.ws_col)
		info->nb_lines++;
	return (info->max_name_size + 2);
}

static t_arg_list	*jump_nodes(t_arg_list *lst, int num)
{
	while (num)
	{
		lst = lst->next;
		num--;
	}
	return (lst);
}

void				print_list(t_arg_list *lst)
{
	t_arg_list		*tmp;
	int				print_w;
	int				to_print;
	t_print_info	info;

	info.nb_elem = 0;
	info.max_name_size = 0;
	info.nb_chars = 0;
	info.nb_lines = 1;
	if (ioctl(STDOUT, TIOCGWINSZ, &(info.w)) == -1)
		ft_putstr_fd("error: failed to use ioctl\n", STDERR);
	print_w = get_print_width(lst, &info);
	if (!(tmp = lst))
	{
		ft_putstr_fd("error: arg_list is empty\n", STDERR);
		return ;
	}
	ft_printf("%-*s", print_w, tmp->name);
	to_print = info.nb_elem / info.nb_lines;
	while ((tmp = jump_nodes(tmp, info.nb_lines)) && (tmp != lst) && !(tmp->deleted))
	{
		if (to_print == 0)
		{
			print_line();
			to_print = info.nb_elem / info.nb_lines;
		}
		ft_printf("%-*s", print_w, tmp->name);
		to_print--;
	}
}
