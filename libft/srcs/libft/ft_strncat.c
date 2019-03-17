/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscott <pscott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:57:00 by pscott            #+#    #+#             */
/*   Updated: 2018/11/07 16:10:00 by pscott           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2 && n)
	{
		s1[i] = *s2;
		i++;
		s2++;
		n--;
	}
	s1[i] = 0;
	return (s1);
}
