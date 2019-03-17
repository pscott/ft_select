/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:26:36 by pscott            #+#    #+#             */
/*   Updated: 2018/11/11 13:28:31 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t	len;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	res = ft_strnew(len);
	while (len - i > 0)
	{
		res[i] = s[len - i - 1];
		i++;
	}
	return (res);
}
