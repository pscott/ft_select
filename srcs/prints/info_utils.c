/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:56 by pscott            #+#    #+#             */
/*   Updated: 2019/04/04 14:52:56 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		fill_print_info(t_arg_list *lst, t_print_info *info)
{
	int			i;
	int			max;
	t_arg_list	*tmp;

	if (!lst)
		return ;
	info->nb_elem = lst->prev->id;
	i = -1;
	max = 0;
	tmp = lst;
	while (i++ < info->nb_elem && (tmp = tmp->next))
		max = (tmp->name_len > max) ? tmp->name_len : max;
	info->max_name_size = max;
	info->elem_per_line = info->w.ws_col / (info->max_name_size + SPACING);
	if (!info->elem_per_line)
		return ;
	while (info->elem_per_line * info->nb_lines < info->nb_elem)
		info->nb_lines++;
	if (info->nb_lines >= info->w.ws_row)
		info->elem_per_line = 0;
}

/*
** get_print_info sets elem_per_line to 0 if it cannot print
*/

void			get_print_info(t_arg_list *lst, t_print_info *info)
{
	char *ls_colors;

	info_addr(&info);
	ft_bzero(info->ls_colors, 23);
	if (ioctl(STDIN, TIOCGWINSZ, &(info->w)) == -1)
	{
		term_putstr_endline("error: exiting.", STDERR);
		reset_terminal_settings();
		exit(1);
	}
	execute_str(CLEAR_BELOW);
	info->nb_elem = 0;
	if ((ls_colors = getenv("LSCOLORS")))
		ft_strncpy(info->ls_colors, ls_colors, 22);
	info->max_name_size = 0;
	info->nb_lines = 1;
	fill_print_info(lst, info);
}
