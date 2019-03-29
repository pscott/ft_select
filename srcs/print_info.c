#include "ft_select.h"

void			print_info(t_print_info *info)
{
	ft_printf("ELEMS: %d, MAX_NAME: %d, NB_CHARS: %d, NB_LINES: %d, ELEM_PER_LINE: %d, SIZE: %d", info->nb_elem, info->max_name_size, info->nb_chars, info->nb_lines, info->elem_per_line, info->w.ws_col);
	print_line();
}

static int			get_print_width(t_arg_list *lst, t_print_info *info)
{
	int			i;
	int			max;
	t_arg_list *tmp;

	if (!lst)
		return (0);
	info->nb_elem = lst->prev->id;
	i = -1;
	max = 0;
	tmp = lst;
	while (i++ < info->nb_elem && (tmp = tmp->next))
		max = (tmp->len > max) ? tmp->len : max;
	info->max_name_size = max;
	info->nb_chars = info->nb_elem * (info->max_name_size + SPACING);
	info->elem_per_line = info->w.ws_col / (info->max_name_size + SPACING);
	while (info->elem_per_line * info->nb_lines < info->nb_elem)
		info->nb_lines++;
	return (info->max_name_size);
}

int				get_print_info(t_arg_list *lst, t_print_info *info)
{
	info_addr(&info);
	if (ioctl(STDOUT, TIOCGWINSZ, &(info->w)) == -1)
		term_putstr_endline("error: failed to use ioctl. Expect some undefined behaviors.", STDERR);
	execute_str(SAVE_CURSOR);
	execute_str(CLEAR_BELOW);
	info->nb_elem = 0;
	info->max_name_size = 0;
	info->nb_lines = 1;
	info->print_width = 0;
	info->print_width = get_print_width(lst, info);
	retrieve_pos(&(info->pos));
	return (1);
}
