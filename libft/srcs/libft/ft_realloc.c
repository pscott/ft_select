/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 12:04:12 by pscott            #+#    #+#             */
/*   Updated: 2019/01/27 19:07:23 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(void *data, size_t current_data_size,
		size_t *current_malloc_size, size_t append_size)
{
	char	*res;

	if (current_data_size + append_size < *current_malloc_size)
		return (data);
	res = ft_strnew(*current_malloc_size * REALLOC_FACTOR);
	*current_malloc_size *= REALLOC_FACTOR;
	res = (char*)ft_memcpy((void*)res, (void*)data, current_data_size);
	ft_memdel((void*)&data);
	return (res);
}
