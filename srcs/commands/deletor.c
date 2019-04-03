/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:38:08 by pscott            #+#    #+#             */
/*   Updated: 2019/04/03 22:38:08 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	reindex_list(t_arg_list *lst)
{
	int			i;
	t_arg_list	*tmp;

	tmp = lst;
	tmp->id = 1;
	i = 2;
	while ((tmp = tmp->next) && tmp != lst)
	{
		tmp->id = i;
		i++;
	}
}

t_arg_list	*delete_node(t_arg_list *lst, t_print_info *info)
{
	t_arg_list *tmp;

	tmp = lst;
	while (tmp->current == 0)
		tmp = tmp->next;
	tmp->next->current = 1;
	if (tmp == lst)
		lst = lst->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	free_node(tmp);
	lst_addr(&lst);
	reindex_list(lst);
	get_print_info(lst, info);
	return (lst);
}
