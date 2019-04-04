/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:56 by pscott            #+#    #+#             */
/*   Updated: 2019/04/04 14:52:56 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			move_vertically(t_arg_list *lst, char *direction)
{
	t_arg_list *tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (!tmp->current)
		tmp = tmp->next;
	if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp->current = 0;
		tmp->next->current = 1;
	}
	else if (ft_strncmp(direction, "up", 3) == 0)
	{
		tmp->current = 0;
		tmp->prev->current = 1;
	}
	else
		return (0);
	return (1);
}

static int	move_left_border(t_arg_list *tmp, t_print_info *info)
{
	int	target;
	int	elem;
	int	res;

	res = -tmp->id;
	target = info->nb_lines == 1 ? 0 : tmp->id % info->nb_lines - 1;
	elem = info->nb_elem % info->nb_lines;
	res -= (target > elem) ? info->nb_lines + (elem - target) : elem - target;
	return (res);
}

int			move_horizontally(t_arg_list *lst, t_print_info *info,
		char *direction)
{
	int			jmp;

	if (!lst)
		return (0);
	while (!lst->current)
		lst = lst->next;
	lst->current = 0;
	jmp = 0;
	if (ft_strncmp(direction, "right", 6) == 0)
	{
		if (lst->id + info->nb_lines > info->nb_elem)
			jmp = info->nb_elem - lst->id + (lst->id % info->nb_lines + 1);
		else
			jmp = info->nb_lines;
	}
	else if (ft_strncmp(direction, "left", 5) == 0)
	{
		if (lst->id - info->nb_lines < 1)
			jmp = move_left_border(lst, info);
		else
			jmp = -info->nb_lines;
	}
	lst = jump_nodes(lst, jmp);
	lst->current = 1;
	return (1);
}
