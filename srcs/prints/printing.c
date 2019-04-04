/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:56 by pscott            #+#    #+#             */
/*   Updated: 2019/04/04 18:23:33 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			print_current(t_arg_list *tmp, t_print_info *info,
		char *color)
{
	if (tmp->current)
	{
		execute_str(UNDERLINE);
		if (tmp->highlighted)
		{
			execute_str(HIGHLIGHT);
			ft_dprintf(g_dev_tty, "%s%-*s%s", BOLD, info->max_name_size,
					tmp->name, RESET);
			execute_str(NO_HIGHLIGHT);
		}
		else
			ft_dprintf(g_dev_tty, "%s%s%-*s%s", color, BOLD, info->max_name_size,
					tmp->name, RESET);
		execute_str(NO_UNDERLINE);
	}
}

static void			print_node(t_arg_list *tmp, t_print_info *info)
{
	char		*color;

	if (!(color = get_color(tmp->file_type, info)))
		color = "";
	if (tmp->current)
		print_current(tmp, info, color);
	else
	{
		if (tmp->highlighted)
		{
			execute_str(HIGHLIGHT);
			ft_dprintf(g_dev_tty, "%-*s", info->max_name_size, tmp->name);
			execute_str(NO_HIGHLIGHT);
		}
		else
			ft_dprintf(g_dev_tty, "%s%-*s%s", color, info->max_name_size,
					tmp->name, RESET);
	}
	if (*color)
		free(color);
	write(g_dev_tty, "  ", 2);
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
			ft_dprintf(g_dev_tty, "RLY?");
		else
			ft_dprintf(g_dev_tty, "Terminal size too small");
		execute_str(LEFT_CORNER);
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
		print_node(lst, info);
		if (lst->id + info->nb_lines > info->nb_elem)
		{
			if (total_printed != info->nb_elem - 1)
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
