/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:52:49 by pscott            #+#    #+#             */
/*   Updated: 2018/11/11 14:36:09 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**tmp;

	tmp = alst;
	while ((*tmp && tmp))
	{
		del((*tmp)->content, (*tmp)->content_size);
		free(*tmp);
		*tmp = (*tmp)->next;
	}
	alst = NULL;
}
