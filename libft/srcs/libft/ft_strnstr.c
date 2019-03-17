/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:00:20 by pscott            #+#    #+#             */
/*   Updated: 2018/11/11 18:27:14 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t tmp;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && len)
	{
		tmp = len;
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && tmp > 0)
		{
			j++;
			tmp--;
		}
		if (needle[j] == 0)
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (NULL);
}
