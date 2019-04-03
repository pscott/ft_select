/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:38:08 by pscott            #+#    #+#             */
/*   Updated: 2019/04/03 23:05:07 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			reposition_cursor(t_print_info *info)
{
	t_pos pos;

	retrieve_pos(&pos);
	move_cursor(0, pos.row - info->nb_lines);
	return (1);
}
