/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:56 by pscott            #+#    #+#             */
/*   Updated: 2019/04/04 14:52:56 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Those functions act as global variables.
** Globals are fobidden at 42 (except for g_saved_attr)
** Call get_lst(NULL) to retrieve the current list address,
** or call get_lst(&lst) to set the static variable to lst's address.
** Same idea for info_addr.
*/

t_arg_list			*lst_addr(t_arg_list **new)
{
	static t_arg_list *lst = NULL;

	if (new)
		lst = *new;
	return (lst);
}

t_print_info		*info_addr(t_print_info **new)
{
	static t_print_info	*info = NULL;

	if (new)
		info = *new;
	return (info);
}
