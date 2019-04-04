/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:56 by pscott            #+#    #+#             */
/*   Updated: 2019/04/04 14:52:56 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		highlight_node(t_arg_list *lst)
{
	t_arg_list *tmp;

	tmp = lst;
	while (tmp->current == 0)
		tmp = tmp->next;
	tmp->highlighted = !tmp->highlighted;
	tmp->current = 0;
	tmp->next->current = 1;
	return (1);
}
