/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:56 by pscott            #+#    #+#             */
/*   Updated: 2019/04/04 14:52:56 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		check_for_movement(t_arg_list *lst, t_print_info *info, char *buf)
{
	if (ft_strncmp(buf, RIGHTARROW, ARROW_LEN + 1) == 0)
		move_horizontally(lst, info, "right");
	else if (ft_strncmp(buf, LEFTARROW, ARROW_LEN + 1) == 0)
		move_horizontally(lst, info, "left");
	else if (ft_strncmp(buf, UPARROW, ARROW_LEN + 1) == 0
			|| ft_strncmp(buf, RTAB, RTAB_LEN + 1) == 0)
		move_vertically(lst, "up");
	else if (ft_strncmp(buf, DOWNARROW, ARROW_LEN + 1) == 0
			|| ft_strncmp(buf, TAB, TAB_LEN + 1) == 0)
		move_vertically(lst, "down");
	else
		return (0);
	return (1);
}

int		check_for_highlight(t_arg_list *lst, char *buf)
{
	if (ft_strncmp(buf, SPACE, SPACE_LEN + 1) == 0)
		highlight_node(lst);
	else
		return (0);
	return (1);
}

int		check_for_quit(t_arg_list *lst, char *buf)
{
	if (ft_strncmp(buf, "\x04", 2) == 0
			|| ft_strncmp(buf, ESCAPE, ESCAPE_LEN + 1) == 0)
	{
		reset_lst(lst);
		return (1);
	}
	else
		return (0);
}

int		check_for_delete(t_arg_list **lst, t_print_info *info, char *buf)
{
	if (ft_strncmp(buf, BACKSPACE, BACKSPACE_LEN + 1) == 0
			|| ft_strncmp(buf, DEL, DEL_LEN + 1) == 0)
	{
		if (info->nb_elem == 1)
		{
			execute_str(CLEAR_BELOW);
			return (-1);
		}
		else
			*lst = delete_node(*lst, info);
		return (1);
	}
	else
		return (0);
}

int		check_for_stop(char *buf)
{
	if (ft_strncmp(buf, "\x1a", 2) == 0)
	{
		sigtstp_handler(SIGTSTP);
		return (1);
	}
	else
		return (0);
}
