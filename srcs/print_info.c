#include "ft_select.h"

static void			print_info(t_print_info *info)
{
	ft_printf("ELEMS: %d, MAX_NAME: %d, NB_CHARS: %d, NB_LINES: %d, ELEM_PER_LINE: %d", info->nb_elem, info->max_name_size, info->nb_chars, info->nb_lines, info->elem_per_line);
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
	info->nb_chars = info->nb_elem * (info->max_name_size + SPACING);
	while ((info->nb_chars / info->nb_lines) >= info->w.ws_col)
		info->nb_lines++;
	info->elem_per_line = info->nb_elem / info->nb_lines;
	return (info->max_name_size);
}

int				get_print_info(t_arg_list *lst, t_print_info *info)
{
	info_addr(&info);
	if (ioctl(STDOUT, TIOCGWINSZ, &(info->w)) == -1)
		term_putstr_endline("error: failed to use ioctl", STDERR);
	info->nb_elem = 0;
	info->max_name_size = 0;
	info->nb_lines = 1;
	info->print_width = 0;
	info->print_width = get_print_width(lst, info);
	return (1);
}
