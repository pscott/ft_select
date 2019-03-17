/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:25:01 by pscott            #+#    #+#             */
/*   Updated: 2019/01/27 21:41:40 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*malloc_error(void)
{
	ft_putstr_fd("Error: failed to allocate memory\n", 2);
	exit(1);
	return (NULL);
}

char		*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	if (!(res = (char *)malloc(sizeof(*res) * (size + 1))))
		return (malloc_error());
	i = 0;
	while (size + 1)
	{
		res[i] = 0;
		i++;
		size--;
	}
	return (res);
}
