/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:51:10 by pscott            #+#    #+#             */
/*   Updated: 2018/11/11 16:55:51 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **head)
{
	size_t len;

	len = 0;
	if (head == NULL)
		return (len);
	while (*head)
	{
		len++;
		*head = (*head)->next;
	}
	return (len);
}
