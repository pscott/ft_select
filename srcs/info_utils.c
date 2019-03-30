#include "ft_select.h"

static void		fill_print_info(t_arg_list *lst, t_print_info *info)
{
	int			i;
	int			max;
	t_arg_list *tmp;

	if (!lst)
		return ;
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
}

int				get_print_info(t_arg_list *lst, t_print_info *info)
{
	info_addr(&info);
	if (ioctl(STDOUT, TIOCGWINSZ, &(info->w)) == -1)
		term_putstr_endline("error: failed to use ioctl. Expect some undefined behaviors.", STDERR);
	execute_str(CLEAR_BELOW);
	info->nb_elem = 0;
	info->max_name_size = 0;
	info->nb_lines = 1;
	fill_print_info(lst, info);
	return (1);
}