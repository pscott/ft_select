/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:40:41 by pscott            #+#    #+#             */
/*   Updated: 2019/04/03 13:40:51 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		free_node(t_arg_list *lst)
{
	ft_memdel((void*)&lst->name);
	ft_memdel((void*)&lst);
}

void		free_list(t_arg_list *lst)
{
	t_arg_list	*head;
	t_arg_list	*tmp;

	head = lst;
	while (lst && (lst->next != head))
	{
		tmp = lst;
		lst = lst->next;
		free_node(tmp);
	}
	free_node(lst);
}
